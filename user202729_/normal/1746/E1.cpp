// time-limit: 1000
// problem-url: https://codeforces.com/contest/1746/problem/E1

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

// { ==== Begin library read ====


template<class T> T read(){
	T result;
	std::cin>>result;
	assert(std::cin);
	return result;
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

// iterate over container backwards. Currently only support lvalue, avoid iterator invalidation etc.
template<class T> auto reverse_range(T& value){
	return range(value.rbegin(), value.rend());
}

//template<class Container> auto range(Container container){
//	return Range{ std::begin(container), std::end(container) };
//}

template<class T, class=std::enable_if<std::is_integral<T>::value, int>>
auto infinite_range(T first){return Range<int_iter<T>, unreachable_iter>{first, {}};}

template<class T> T&& identity(T&& x){ return x; }

// } ==== End library range ====


int main(){
	std::ios::sync_with_stdio(0);
	int const number=read<int>();
	
	auto const halve=[&](std::vector<int>& source, std::vector<int>& target){
		assert(target.empty());
		target.assign(source.begin()+source.size()/2, source.end());
		source.erase(source.begin()+source.size()/2, source.end());
	};
	
	std::vector<int> first, sec;
	for(int const i: range(1, number+1)){
		first.push_back(i);
	}

	auto const merge=[&](std::vector<int> a, std::vector<int> const& b){
		a.insert(a.end(), begin(b), end(b));
		return a;
	};


	auto const guess=[&](std::vector<int> const& items)->bool{
		std::cout<<"? "<<items.size();
		for(auto x: items) std::cout<<' '<<x;
		std::cout<<'\n';
		std::string const s=read<std::string>();
		assert(s=="YES" or s=="NO");
		return s=="YES";
	};

	auto const initialize=[&]{
		first=merge(std::move(first), std::move(sec));
		sec.clear();
		halve(first, sec);
		if(not guess(first)) std::swap(first, sec);
	};
	initialize();


	while(first.size()+sec.size()>=4){
		// at the moment, the last answer says that x belongs to first

		if(first.size()<=1 or sec.size()<=1){
			// last answer is useless, spend another query
			initialize();
		}
		
		std::vector<int> first1=std::move(first), first2;
		halve(first1, first2);
		std::vector<int> sec1=std::move(sec), sec2;
		halve(sec1, sec2);

		if(not guess(merge(first1, sec1))){
			std::swap(first1, first2);
			std::swap(sec1, sec2);
		}

		// so last-last answer says it belongs to [first1, first2]
		// and last answer says it belongs to [first1, sec1]
		sec2.clear();

		first=merge(std::move(first1), std::move(sec1));
		sec=std::move(first2);
	}

	// okay  3 left
	first=merge(std::move(first), std::move(sec));
	sec.clear();

	if(first.size()==3){
		//std::array<int, 4> answers;
		int answers {};
		for(auto i: {0, 1, 1, 0}){
			//answers.push_back(guess({first[i]}));
			answers=answers*2+guess({first[i]});
		}

		int exclude;
		switch(answers){
			case 0: exclude=1; break;
			case 1: exclude=1; break;
			case 2: exclude=0; break;
			case 3: exclude=2; break;
			case 4: exclude=0; break;
			case 5: exclude=0; break;
			case 6: exclude=0; break;
			case 7: exclude=0; break;
			case 8: exclude=1; break;
			case 9: exclude=1; break;
			case 10: exclude=0; break;
			case 11: exclude=1; break;
			case 12: exclude=2; break;
			case 13: exclude=1; break;
			case 14: exclude=0; break;
			case 15: exclude=0; break;
		}

		first.erase(first.begin()+exclude);
	}

	for(auto x: first){
		std::cout<<"! "<<x<<'\n';
		std::string const s=read<std::string>();
		if(s==":)") break;
		assert(s==":(");
	}



}