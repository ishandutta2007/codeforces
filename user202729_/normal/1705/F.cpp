// time-limit: 2000
// problem-url: https://codeforces.com/contest/1705/problem/F

// a 2900 div2f problem? huh.

// test 11 is main test.......
// okay let's try this one. Actually asymptotically better, or so I think
// modulo implementation bug... (well I *could* exit 1 to distinguish but...)


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


// { ==== Begin library RandomEngine.h ====



std::mt19937 engine(
#if LOCAL
		123456
#else
		std::chrono::duration_cast<std::chrono::nanoseconds>(
			std::chrono::steady_clock::now().time_since_epoch()).count()
#endif
		);

// } ==== End library RandomEngine.h ====


// { ==== Begin library YComb ====

template<class T> struct YComb_{
	//T const& f;
	T f; // will figure out later...
	YComb_(T const& f): f(f) {}
	template<class... Args> auto operator()(Args... args)const{
		return f(*this, std::forward<Args>(args)...);
	}
};

// C++14 compatibility
template<class T> YComb_<T> YComb(T f){ return {std::move(f)}; }
template<class T> YComb_<T> makeYComb(T f){ return {std::move(f)}; } // old code...

// } ==== End library YComb ====


int main(){
	int const number=read<int>();
	

	// return how many answers in s are correct.
	auto const query=[&](std::vector<char> s)->int{  // input has bool values, 0|1
		//for(auto index: indices) s[index]='T';
		std::string line(number, char(0));
		for(int const index: range(0, number)){
			line[index]=s[index] ? 'T': 'F';
		}

		std::cout<<line<<std::endl;
		auto const result=read<int>();
		if(result==number or result==-1){
			std::exit(0);
		}
		return result;
	};

	auto const resultSetSize=query(std::vector<char>(number, true));

	std::vector<char> result(number);
	
	auto const intersectSize=[&](std::vector<int> indices)->int{  // bonus, also fill result if it's determined that's true
		std::vector<char> s(number);
		for(auto index: indices) s[index]=true;


		auto intersectSize=(int(indices.size())+resultSetSize+query(s)-number)>>1;
		assert(0<=intersectSize);
		assert(intersectSize<=int(indices.size()));
		if(intersectSize==int(indices.size())){
			for(auto index: indices) result[index]=true;
		}

		return intersectSize;
	};

	auto const solve=makeYComb([&](auto solve, std::vector<int> indices)->void{
		// populate result with whether the answer is T or F for the indices in indices.

		if(indices.size()%2!=0){
			intersectSize({indices.back()});
			indices.pop_back();
		}

		assert(indices.size()%2==0);
		if(indices.empty()) return;

		std::vector<int> parta, partb;
		for(int i=0; i+4<=int(indices.size()); i+=4){
			auto x=intersectSize(std::vector<int>(indices.begin()+i, indices.begin()+i+4));
			if(x==0 or x==4){
				continue; // already done
			}
			auto y=intersectSize(std::vector<int>(indices.begin()+i, indices.begin()+i+2));
			if(y==1){
				parta.push_back(indices[i]);
				partb.push_back(indices[i+1]);
			}
			if(x-y==2){
				result[indices[i+2]]=true;
				result[indices[i+3]]=true;
			}else if(x-y==1){
				parta.push_back(indices[i+2]);
				partb.push_back(indices[i+3]);
			}
		}

		if(indices.size()%4!=0){
			auto x=intersectSize(std::vector<int>(indices.end()-2, indices.end()));
			if(x==1){
				parta.push_back(indices.end()[-2]);
				partb.push_back(indices.back());
			}
		}

		solve(parta);
		for(int const index: range(0, int(parta.size()))){
			if(not result[parta[index]]){
				result[partb[index]]=true;
			}
		}
	});


	std::vector<int> indices(number);
	for(int const index: range(0, number)){
		indices[index]=index;
	}
	std::shuffle(begin(indices), end(indices), engine);
	solve(indices);

	query(result);
	assert(false); __builtin_unreachable();

}