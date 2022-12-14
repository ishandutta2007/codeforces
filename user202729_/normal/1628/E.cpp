// time-limit: 2000
// problem-url: https://codeforces.com/contest/1628/problem/E

// template test

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

// { ==== Begin library read ====


template<class T> T read(){
	T result; std::cin>>result; return result;
}

// } ==== End library read ====


// { ==== Begin library range ====



template<class T>
struct int_iter{
	//using iterator_category = std::random_access_iterator_tag;
	using iterator_category = std::random_access_iterator_tag;
	using value_type = T;
	//using difference_type = std::ptrdiff_t;
	using difference_type = T;
	using pointer = T*;
	using reference = T&;

	T x;
	constexpr int_iter(T x):x{x}{}
	T operator*()const{return x;}
	int_iter& operator++(){ ++x; return *this; }
	int_iter& operator--(){ --x; return *this; }

#define operation(op) \
	int_iter& operator op##=(difference_type y){ x op##= y; return *this; } \
	int_iter friend operator op(int_iter x, difference_type y){ return x op##= y; }
	operation(+) operation(-)
#undef operation
	int_iter friend operator+(difference_type y, int_iter x){ return x += y; }

#define operation(op) \
	auto operator op(int_iter const& other) const{return x op other.x;}
	operation(-) operation(<) operation(>) operation(<=) operation(>=) operation(==) operation(!=)
#undef operation

	T operator[](difference_type y)const{ return x+y; }
};

struct unreachable_iter{
	template<class T, class U,
		class=std::enable_if<
			std::is_same<T, unreachable_iter>::value xor std::is_same<U, unreachable_iter>::value, int>
	> friend bool operator!=(T const& first, U const& sec){ return true; }
};

template<class T> auto range(T first, T last);


template<class A, class B=A>
struct Range{
	A first; B last;
	constexpr Range(A first, B last):first{std::move(first)},last{std::move(last)}{}

	/*
	template<class Container> Range(Container&& container):
		first(std::begin(std::forward<Container>(container))), last(std::end(std::forward<Container>(container))){}
		*/

	// make sure container is not a temporary (TODO?)
	template<class Container> Range(Container& container):
		first(std::begin(container)), last(std::end(container)){}

	constexpr A const& begin() const{return first;}
	constexpr B const& end() const{return last;}
	constexpr auto size() const{ return last-first; }

	Range take(std::size_t len)const{
		return Range{first, std::next(first, len)};
	}
	Range drop(std::size_t len)const{
		return Range{std::next(first, len), last};
	}

	Range const& sort    () const{ std::sort(first, last); return *this; }
	template<class F> Range const& sort_by (F const& compare) const{ std::sort(first, last, compare); return *this; }
	template<class F> Range const& sort_key(F const& key) const{
		std::sort(first, last, [&](auto const& first, auto const& sec){
			return key(first)<key(sec);
		});
		return *this;
	}

	template<class T> Range const& shuffle(T&& engine) const{ std::shuffle(first, last, engine); return *this; }
	Range& unique() { last=std::unique(first, last); return *this; }
	//Range const& reverse() const{ std::reverse(first, last); return *this; }
	auto reverse() const{
		return range(
				std::make_reverse_iterator(last),
				std::make_reverse_iterator(first)
				);
		/*
		return Range<
				typename std::decay<decltype(std::make_reverse_iterator(last))>::type,
				typename std::decay<decltype(std::make_reverse_iterator(first))>::type
		>{
				std::make_reverse_iterator(last),
				std::make_reverse_iterator(first)
		};
		*/
	}

	auto const& assign(Range other) const{
		assert(size()==other.size());
		std::copy(other.first, other.last, first);
		return *this;
	}
	auto const& copy_to(A const& iterator) const{
		std::copy(first, last, iterator);
		return *this;
	}
	auto const& copy_to(Range const& range) const{
		std::copy(first, last, range.first);
		return *this;
	}

	template<class Container> Container collect() const{return Container(first, last);}

	template<class F> auto any  (F const& function) const{ return std::any_of(first, last, function); }
	template<class F> auto all  (F const& function) const{ return std::all_of(first, last, function); }
	template<class F> auto none (F const& function) const{ return std::none_of(first, last, function); }
	template<class F> auto count(F const& function) const{ return std::count_if(first, last, function); }
	template<class F> auto find (F const& function) const{ return std::find_if(first, last, function); }
};


template <typename T>
auto dereferencable(const T& x) -> decltype(void(*x), std::true_type());

std::false_type dereferencable(...);

template<class T> auto range(T first, T last){
	if constexpr(std::is_integral<T>::value){
		assert(first<=last);  // otherwise won't work properly
		return Range<int_iter<T>>{first, last};
	}else{
		static_assert(decltype(dereferencable(first))::value, "value type is neither integral nor dereferencable");
		return Range<T>{first, last};
	}
}

template<class T> auto range(T&& value){
	using T1=typename std::decay<T>::type;
	if constexpr(std::is_integral<T1>::value)
		return Range<int_iter<T1>>{{{}}, std::forward<T>(value)};
	else
		return Range<typename std::decay<decltype(value.begin())>::type>{std::forward<T>(value)};
}


//template<class Container> auto range(Container container){
//	return Range{ std::begin(container), std::end(container) };
//}

template<class T, class=std::enable_if<std::is_integral<T>::value, int>>
auto infinite_range(T first){return Range<int_iter<T>, unreachable_iter>{first, {}};}

template<class T> T&& identity(T&& x){ return x; }

// } ==== End library range ====


// { ==== Begin library Dsu ====



// { ==== Begin library ZeroSized.h ====


// some compiler extension to make code simple
struct Empty{ int _[0];
	bool operator==(Empty) const{return true;}
	bool operator!=(Empty) const{return false;}
};

std::ostream& operator<<(std::ostream& stream, Empty ){
	return stream<<"{}";
}

// } ==== End library ZeroSized.h ====


// the class, with CRTP for beforeChange()

template<class Data, class F, bool path_compression, bool union_by_rank, class ActualClass> struct Dsu__{

	void beforeChange(int /*node*/){}  // CRTP-virtual function, called before data[node] is changed



	struct Node{
		Data data;
		int par; //  0: have par, -1: is root, < -1: is root and have large rank and UNION_BY_RANK
	};
	std::vector<Node> data;
	F merge_function;

	Dsu__(F merge_function): data(), merge_function(merge_function) {
		static_assert(path_compression or union_by_rank);
	}

	void assign(int n, auto starting_data /* (index)  Data */){
		data.clear(); data.reserve(n);
		for(int i=0; i<n; ++i){
			if(data.size()>=data.capacity()) __builtin_unreachable();
			data.push_back({starting_data(i), -1});
		}
	}

	void assign(int n){
		assign(n, [&](int /*index*/){ return Data {}; });
	}

	bool isRoot(int node) const{return data[node].par<0;}

	int root(int node)
//#if not PATH_COMPRESSION
//		const
//#endif
	{
		if(isRoot(node)
				) return node;
		if constexpr(path_compression){
			((ActualClass*) this)->beforeChange(node);
			return 
				data[node].par= root(data[node].par);
		}else{
			return 
				root(data[node].par);
		}
	}

	auto join(int a, int b){
		struct Result{
			bool already_joined;
			int newRoot;
			Data* data;
            
            bool just_joined() const{return not already_joined;}
		};

		a=root(a); b=root(b);

		if(a==b) return Result{true, b, &data[b].data};

		if(union_by_rank){
			if(data[a].par<data[b].par) std::swap(a, b);
			else if(data[a].par==data[b].par) --data[b].par;
		}

		beforeChange(a);
		data[a].par=b;
		if(not std::is_same<Empty, Data>::value){
			((ActualClass*) this)->beforeChange(b);
			data[b].data=merge_function(
					std::move(data[b].data),
					std::move(data[a].data),
					b,
					a);
		}

		return Result{false, b, &data[b].data};
	}
};

template<class Data, class F, bool path_compression, bool union_by_rank> struct Dsu_:
	Dsu__<Data, F, path_compression, union_by_rank, Dsu_<Data, F, path_compression, union_by_rank>> {
	using Base=Dsu__<Data, F, path_compression, union_by_rank, Dsu_<Data, F, path_compression, union_by_rank>>;
	using Base::Base;
};

// public interface ========

// merge_function: used to merge data. On merge, called with
// (Data data_b, Data data_a, int b, int a)  Data
// where b is the new root

// join(a, b): if path_compression is false, b is the new root

// create a Dsu. Call with specified signature and template parameters.
template<
		class Data, // must be provided
		bool path_compression=true, bool union_by_rank=true, // optional

		class _F // auto deduced
		>
	Dsu_<Data, _F, path_compression, union_by_rank>
	Dsu(_F merge_function){ return {merge_function}; }

// create a "normal" Dsu.
template<bool path_compression=true, bool union_by_rank=true>
auto Dsu(){
	return Dsu<Empty, path_compression, union_by_rank>(
			[](Empty, Empty, int, int){return Empty {};}
			);
}

// } ==== End library Dsu ====


// { ==== Begin library RMQ ====
template<class T, class F> struct RMQ_{
	std::vector<std::vector<T>> data;
	F minFunction;

	/*
	RMQ_(std::vector<T> a, F minFunction): data{std::move(a)}, minFunction(std::move(minFunction)){
		for(int step=1; step<(int)data.back().size(); step<<=1){
			std::vector<T> tmp(data.back().begin(), data.back().end()-step);
			for(int i=0; i<(int)tmp.size(); ++i)
				tmp[i]=minFunction(tmp[i], data.back()[i+step]);
			data.push_back(std::move(tmp));
		}
	}
	*/

	RMQ_(std::vector<T> a, F minFunction): data{}, minFunction(std::move(minFunction)){
		data.push_back({});
		for(auto item: a)
			this->push_back({item});
	}

	void push_back(T item){
		data[0].push_back(std::move(item));
		for(int const layer: range(1, int(data.size()))){
			data[layer].push_back(minFunction(data[layer-1][data[layer].size()], data[layer-1].back()));
		}
		int newLayer=int(data.size());
		if((1<<(newLayer-1))<int(data.back().size())){
			data.push_back({minFunction(data.back()[0], data.back()[1<<(newLayer-1)])});
		}
		assert(std::cerr<<"");
	}
	
	void pop_back(){
		for(auto& item: data) item.pop_back();
		if(data.size()>1 and data.back().empty()) data.pop_back();
	}

	T operator()(int left, int right) const{
		assert(left<right);
		auto const layer=31^__builtin_clz(right-left);
		assert(left+(1<<layer)>=right-(1<<layer)); assert(right-(1<<layer)>=left);
		auto result=minFunction(
				data[layer][left], data[layer][right-(1<<layer)]);
		{
		auto const tmp=[&]{
			auto tmp=data[0][left];
			for(int const i: range(left, right)){
				tmp=minFunction(tmp, data[0][i]);
			}
			assert(tmp==result);
			return true;
		}; assert(tmp());}
		return result;
	}

};

// C++14
template<class T, class F> 
RMQ_<T, F> RMQ(std::vector<T> a, F minFunction){ return {std::move(a), std::move(minFunction)}; }

// simple case
template<class T>
auto RMQ(std::vector<T> a){ return RMQ(std::move(a), [&](T const& first, T const& sec)->T const&{
	return std::min(first, sec);
}); }

template<class T>
auto RMQ_max(std::vector<T> a){ return RMQ(std::move(a), [&](T const& first, T const& sec)->T const&{
	return std::max(first, sec);
}); }

// } ==== End library RMQ ====


// { ==== Begin library SegmentCollection ====



template<class OnAddSegmentType, class OnDeleteSegmentType>
struct SegmentCollectionTemplate{
	OnAddSegmentType onAddSegment;
	OnDeleteSegmentType onDeleteSegment;

	std::map<int, int> segments; // left  right

	void consistencyCheck() const{
		{
		auto const tmp=[&]{
			
			int last=INT_MIN;
			for(auto [left, right]: segments){
				assert(last<left);
				assert(left<right);
				last=right;
			}

			return true;
		}; assert(tmp());}
	}

	using Iter=std::map<int, int>::iterator;

	Iter addSegment(int left, int right){
		auto const [iterator, inserted]=segments.insert({left, right});
		assert(inserted);
		consistencyCheck();
		onAddSegment(left, right);
		return iterator;
	}

	Iter deleteSegment(Iter iter){
		onDeleteSegment(iter->first, iter->second);
		auto result=segments.erase(iter);
		consistencyCheck();
		return result;
	}

	void fillSegment(int left, int right){
		assert(left<right);
		auto iter=segments.lower_bound(left);
		if(iter!=segments.begin()){
			auto p=std::prev(iter);
			assert(p->first<left);
			if(p->second>=left){
				left=p->first;
				right=std::max(right, p->second);
				deleteSegment(p);
			}
		}

		while(iter!=segments.end() and iter->first<=right){
			assert(iter->first>=left);
			right=std::max(right, iter->second);
			iter=deleteSegment(iter);
		}

		addSegment(left, right);
	}

	void clearSegment(int left, int right){
		assert(left<right);
		auto iter=segments.lower_bound(left);
		if(iter!=segments.begin()){
			auto p=std::prev(iter);
			auto [t, u]=*p;
			assert(t<left);
			if(u>=left){
				deleteSegment(p);
				addSegment(t, left);
				if(right<u){
					addSegment(right, u);
					return;
				}
			}
		}

		while(iter!=segments.end() and iter->first<=right){
			auto const [t, u]=*iter;
			iter=deleteSegment(iter);
			assert(t>=left);
			assert(t<=right);
			if(u>right){
				addSegment(right, u);
				break;
			}
		}
	}
};

template<class OnAddSegmentType, class OnDeleteSegmentType>
auto makeSegmentCollection(OnAddSegmentType onAddSegment, OnDeleteSegmentType onDeleteSegment){
	return SegmentCollectionTemplate<OnAddSegmentType, OnDeleteSegmentType>{
		std::move(onAddSegment), std::move(onDeleteSegment)};
}

// wait if I do this what's the point of CRTP???

// } ==== End library SegmentCollection ====


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const numNode=read<int>();
	int const numQuery=read<int>();

	struct Edge{int u, v, weight;};
	std::vector<Edge> edges(numNode-1);
	for(auto& [u, v, weight]: edges){
		std::cin>>u>>v>>weight;
		--u;--v;
	}
	std::sort(begin(edges), end(edges), [&](auto const& first, auto const& sec){
		return first.weight<sec.weight;
	});

	struct DsuData{
		std::vector<int> nodes;
		std::vector<int> edgeWeights;
	};

	int curWeight;
	auto d=Dsu<DsuData>(
			[&](DsuData data_b, DsuData data_a, int , int ) ->DsuData{

				assert(data_a.nodes.size()==data_a.edgeWeights.size()+1);
				assert(data_b.nodes.size()==data_b.edgeWeights.size()+1);
				
				if(data_b.nodes.size()<data_a.nodes.size()) std::swap(data_a, data_b);
				for(auto x: data_a.nodes) data_b.nodes.push_back(x);
				data_b.edgeWeights.push_back(curWeight);
				for(auto x: data_a.edgeWeights) data_b.edgeWeights.push_back(x);
				return data_b;
			});
	d.assign(numNode, [&](int node)->DsuData{
		return DsuData{.nodes={node}, .edgeWeights={}};
	});


	for(auto [u, v, weight]: edges){
		curWeight=weight;
		auto tmp=d.join(u, v);
		assert(tmp.just_joined());
	}

	auto [dsuNodeList, dsuEdgeWeights]=std::move(d.data[d.root(0)].data);
	assert(int(dsuNodeList.size())==numNode);
	assert(int(dsuEdgeWeights.size())==numNode-1);
	auto const maxDsuEdgeWeights=RMQ_max(dsuEdgeWeights);

	std::vector<int> dsuOrderOf(numNode);
	for(int const index: range(0, numNode)){
		dsuOrderOf[dsuNodeList[index]]=index;
	}


	auto const dsuOrderOfMinRange=RMQ(dsuOrderOf);
	auto const dsuOrderOfMaxRange=RMQ_max(dsuOrderOf);


	std::set<int> boundaryValues;

	auto segments=makeSegmentCollection(
	[&](int left, int right){
		auto const [iterator, inserted]=boundaryValues.insert(dsuOrderOfMinRange(left, right));
		assert(inserted);
		if(right-left>1){
			auto const [iterator, inserted]=boundaryValues.insert(dsuOrderOfMaxRange(left, right));
			assert(inserted);
		}
	},
	[&](int left, int right){
		boundaryValues.erase(boundaryValues.find(
					dsuOrderOfMinRange(left, right)));
		if(right-left>1){
			boundaryValues.erase(boundaryValues.find(
						dsuOrderOfMaxRange(left, right)));
		}
	});

#if LOCAL
	std::vector<char> open(numNode, false);
#endif

	for(int _=numQuery; _--;){
		char type; std::cin>>type;
		switch(type){
			case '1':
				{
					int const left=read<int>()-1;
					int const right=read<int>();
					segments.fillSegment(left, right);
#if LOCAL
					for(int const index: range(left, right)){
						open[index]=true;
					}
#endif
				}
				break;
			case '2':
				{
					int const left=read<int>()-1;
					int const right=read<int>();
					segments.clearSegment(left, right);
#if LOCAL
					for(int const index: range(left, right)){
						open[index]=false;
					}
#endif
				}
				break;
			case '3':
				{
					int const node=read<int>()-1;
					int result=-1;

					assert((boundaryValues.empty())==(std::accumulate(begin(open), end(open), 0)==0));

					if(not boundaryValues.empty()){
						int left=std::min(dsuOrderOf[node], *boundaryValues.begin());
						int right=std::max(dsuOrderOf[node], *boundaryValues.rbegin());
						if(left!=right){
							assert(left<right);
							result=maxDsuEdgeWeights(left, right);
						}
					}
					std::cout<<result<<'\n';
				}
				break;
			default: assert(false); __builtin_unreachable();
		}
	}
}