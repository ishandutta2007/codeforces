// time-limit: 2000
// problem-url: https://codeforces.com/contest/1609/problem/F
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
// { ==== Begin library GlobalList.h ====
// efficient forward-linked list.

template<class Item> struct GlobalList{
	struct Data{Item item; int next;}; // -1: no next
	inline static std::vector<Data> data;

	struct Iterator{
		int index;

		bool operator==(Iterator other) const{return index==other.index;}
		bool operator!=(Iterator other) const{return index!=other.index;}
		
		Item const& operator*() const{
			return data[index].item;
		};
		Item& operator*(){return const_cast<Item&> (**(const Iterator*) this);}

		Item const* operator->() const{ return &**this; }
		Item* operator->() { return &**this; }

		int& next_(){return data[index].next;} // half-internal method
		Iterator operator++() {index=next_(); return *this;}
	};


	static Iterator newItem(Item item){
		Iterator result{(int)data.size()};
		data.push_back({std::move(item), -1});
		return result;
	}

	template<bool minSize=1> struct List{
		Iterator begin_, back_;

		List(Item item){
			static_assert(minSize==1);

			auto iter=newItem(std::move(item));
			begin_=back_=iter;
		}

		void push_front(Item item){
			auto iter=newItem(std::move(item));
			iter.next_()=begin_.index;
			begin_=iter;
		}

		void push_back(Item item){
			auto iter=newItem(std::move(item));
			back_.next_()=iter.index;
			back_=iter;
		}

		template<int minSize_=minSize>
		std::enable_if_t<minSize_==0, bool> empty() const{
			return begin()==end();
		}

		bool size_equal(int n)const{
			if constexpr(minSize==0){
				if(empty()) return n==0;
			}
			assert(n>=minSize);
			auto tmp=begin_;
			while(n>1){
				if(tmp==back_) return false;
				++tmp; n--;
			}
			return tmp==back_;
		}

		void pop_front() {
			assert(not size_equal(minSize));
			++begin_;
		}

		Iterator begin() const{return begin_;}
		Iterator before_end() const{return back_;}
		Iterator end() const{return {-1};}
		Item& front(){return *begin();} Item const& front()const{return *begin();}
		Item& back(){return *before_end();} Item const& back()const{return *before_end();}

		/*
		void for_each(auto f) const{
			// f: bool(Item)
			static_assert( std::is_invocable_r_v<bool, decltype(f), Item&> );
			assert(back_.next_()==-1);

			for(auto it=begin_;;){
				if(f(it)) break;
				if(it==back_) break;
				++it;
			}
		}
		*/
	};
};
//template<class Item> std::vector<typename GlobalList<Item>::Data> GlobalList<Item>::data;
//requires if not inline. Inline is (should be) safe as long as there's only one translation unit

/* some example:
struct I: GlobalList<int> {};
using L=GlobalList<int>::List<1>;
*/

// } ==== End library GlobalList.h ====
struct T{int64_t value; };

int const endNumBit=60;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin>>n;

	std::vector<T> a(n);
	for(int i=0; i<n; ++i){
		std::cin>>a[i].value;
		assert(__builtin_popcountll(a[i].value)<endNumBit);
	}

	int64_t result {};
	struct Item{
		struct A{ int64_t value; int len; };

		using L=GlobalList<A>::List<1>;

		std::array<int, endNumBit> denseData;
		L dense;
		int64_t sparse;

		int match() const{return denseData[__builtin_popcountll(sparse)];}

		void assertMatch() const{
			assert(([&]{
				for(int pop=0; pop<endNumBit; ++pop){
					int tmp{};
					for(auto [value, len]: dense) {
						assert(len>0);
						tmp+=len*(__builtin_popcountll(value)==pop);
					}
					assert(denseData[pop]==tmp);
				}
				return true;
			}()));
		}

		void appendDense(A item){
			assert(item.len>0);
			if(item.value==dense.front().value)
				dense.front().len+=item.len;
			else
				dense.push_front(item);
		}
	};
	std::vector<Item> items; // [0]: sparse is up, [1]: sparse is down, etc.
	auto const sparseDown=[&](int index)->bool{
		return index&1;
	};

	int curMatch=1;
	result+=curMatch;

	auto const singleton=[&](int64_t value)->Item{
		Item result{
			{}, // denseData
			{{value, 1}}, // dense
			value, // sparse
		};
		result.denseData[__builtin_popcountll(value)]++;
		return result;
	};

	items.push_back(singleton(a[0].value));

	auto const printItems=[&]{
		for(int i=0; i<(int)items.size(); ++i){
			std::cerr
				<<"sparse is "
				<<(sparseDown(i) ? "down": "up")
				<<' '
				<<"[" << items[i].sparse<<"] ";
			for(auto x: items[i].dense){
				for(int i=0; i<x.len; ++i)
					std::cerr<<x.value<<' ';
			}
			std::cerr<<'\n';
		}
		std::cerr<<"========\n";
		return true;
	};

	for(int i=1; i<n; ++i){
		auto const prev=a[i-1].value;
		assert(items.back().sparse==prev);
		assert(items.back().dense.front().value==prev);

		auto const value=a[i].value;

		auto const pullDown=[&](int index){
			auto& item=items[index];
			curMatch-=item.match();
			if(sparseDown(index)){
				if(value<item.sparse){
					item.sparse=value;
				}
			}else{
				int poppedLen {};
				while(item.dense.front().value>=value){
					poppedLen+=item.dense.front().len;
					item.denseData[__builtin_popcountll(item.dense.front().value)]-=item.dense.front().len;
					if(item.dense.size_equal(1)){
						assert(poppedLen!=0);
						item.dense.front()={value, poppedLen};
						item.denseData[__builtin_popcountll(value)]+=poppedLen;
						goto _escape;
					}
					item.dense.pop_front();
				}
				if(poppedLen!=0){
					item.dense.push_front({value, poppedLen});
					item.denseData[__builtin_popcountll(value)]+=poppedLen;
				}
_escape:;
			}
			curMatch+=item.match();
		};

		auto const pullUp=[&](int index){
			auto& item=items[index];
			curMatch-=item.match();
			if(not sparseDown(index)){
				if(value>item.sparse){
					item.sparse=value;
				}
			}else{
				int poppedLen {};
				while(item.dense.front().value<=value){
					poppedLen+=item.dense.front().len;
					item.denseData[__builtin_popcountll(item.dense.front().value)]-=item.dense.front().len;
					if(item.dense.size_equal(1)){
						assert(poppedLen!=0);
						item.dense.front()={value, poppedLen};
						item.denseData[__builtin_popcountll(value)]+=poppedLen;
						goto _escape;
					}
					item.dense.pop_front();
				}
				if(poppedLen!=0){
					item.dense.push_front({value, poppedLen});
					item.denseData[__builtin_popcountll(value)]+=poppedLen;
				}
_escape:;
			}
			curMatch+=item.match();
		};

		auto const merge2=[&](Item& a, Item& b)->bool{
			if(b.dense.size_equal(1) and b.dense.front().value==a.sparse){
				auto const len=b.dense.front().len;
				a.denseData[__builtin_popcountll(b.sparse)]+=len;
				a.appendDense({b.sparse, len});
				return true;
			}
			return false;
		};

		auto const mergeLast=[&]{
			if(items.size()<2) return false;
			auto& a=items.end()[-2]; auto& b=items.back();
			if(merge2(a, b)){
				items.pop_back();
				return true;
			}

			if(items.size()<3) return false;
			{
				auto& a=items.end()[-3];
				auto& b=items.end()[-2];
				auto& c=items.back();
				if(merge2(a, b)){
					assert(a.sparse==c.sparse);

					auto t=c.dense.before_end();
					t.next_()=a.dense.begin().index;
					auto u=t; ++u;
					if(t->value==u->value){
						t->len+=u->len;
						t.next_()=u.next_();
					}
					
					a.dense.begin_=c.dense.begin_;

					for(int pop=0; pop<(int)a.denseData.size(); ++pop)
						a.denseData[pop]+=c.denseData[pop];
					items.pop_back(); items.pop_back();
					return true;
				}
			}

			return false;
		};

		if(value<prev){
			while(true){
				if(items.size()>=1) pullDown((int)items.size()-1);
				assert(printItems());
				if(items.size()>=2) pullDown((int)items.size()-2);
				assert(printItems());
				if(items.size()>=3) pullDown((int)items.size()-3);
				assert(printItems());
				if(not mergeLast()) break;
				assert(printItems());
			}
		}else if(value>prev){
			while(true){
				if(items.size()>=1) pullUp((int)items.size()-1);
				assert(printItems());
				if(items.size()>=2) pullUp((int)items.size()-2);
				assert(printItems());
				if(items.size()>=3) pullUp((int)items.size()-3);
				assert(printItems());
				if(not mergeLast()) break;
				assert(printItems());
			}
		}

		curMatch++;
		items.push_back(singleton(value));
		(void)mergeLast();
		assert(printItems());

		assert(([&]{
			int tmp {};
			for(auto& x: items){
				tmp+=x.match();
				x.assertMatch();
			}
			assert(tmp==curMatch);

			tmp=0;
			for(int j=0; j<=i; ++j){
				int64_t minimum=a[i].value, maximum=a[i].value;
				for(int k=j; k<i; ++k){
					minimum=std::min(minimum, a[k].value);
					maximum=std::max(maximum, a[k].value);
				}
				tmp+=__builtin_popcountll(minimum)==__builtin_popcountll(maximum);
			}
			assert(tmp==curMatch);

			return true;
		}()));

		result+=curMatch;
	}

	std::cout<<result<<'\n';
}