// time-limit: 3000
// problem-url: https://codeforces.com/contest/1666/problem/I


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

// { ==== Begin library AssertEqual.h ====
// helper macro. Both for -checking and print out value of the sides if fail
#define assertCondition(a, b, condition) assert(( \
			[&]{ \
				auto _val1=(a); \
				auto _val2=(b); \
				assert(condition); \
				return true; \
			}()))
#define assertEqual(a, b) assertCondition(a, b, _val1==_val2 \
		or not (std::cerr<<_val1<<"  "<<_val2<<'\n'))
#define assertFloatEqual_(a, b, epsilon, _unused...) assertCondition(double(a), double(b), \
		std::abs(_val1-_val2)< \
		std::max({std::abs(_val1), std::abs(_val2), 1.})*epsilon \
		or not (std::cerr<<_val1<<"  "<<_val2<<'\n'))
#define assertFloatEqual(args...) assertFloatEqual_(args, 1e-12) // default epsilon
// there will be no error if there are more parameters than allowed (3)...

// } ==== End library AssertEqual.h ====
void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int const numRow=read<int>();
	int const numCol=read<int>();

	auto const scan=[&](int row, int col){
		assert(0<=row and row<numRow);
		assert(0<=col and col<numCol);
		std::cout<<"SCAN "<<row+1<<' '<<col+1<<'\n'<<std::flush;
		return read<int>();
	};

	auto const dig=[&](double row, double col)->int{
		assertEqual(row, int(row));
		assertEqual(col, int(col));
		assert(0<=row and row<numRow);
		assert(0<=col and col<numCol);
		std::cout<<"DIG "<<int(row)+1<<' '<<int(col)+1<<'\n'<<std::flush;
		return read<int>();
	};

	auto const digForce=[&](double row, double col){
		int result=dig(row, col);
		assert(result==1);
	};


	double a=scan(0, 0)/2., b=scan(numRow-1, 0)/2.;

	double centerCol=(a+b-(numRow-1))/2, centerRow=a-centerCol;
	assertEqual(centerCol*2, int(centerCol*2));
	assertEqual(centerRow*2, int(centerRow*2));

	double c=scan(int(centerRow), 0)/2., d=scan(0, int(centerCol))/2.;
	double upRow=centerCol+centerRow-c, leftCol=centerCol+centerRow-d;
	assertEqual(upRow, int(upRow));
	assertEqual(leftCol, int(leftCol));

	double downRow=centerRow*2-upRow, rightCol=centerCol*2-leftCol;
	if(dig(upRow, leftCol)){
		digForce(downRow, rightCol);
	}else{
		digForce(upRow, rightCol);
		digForce(downRow, leftCol);
	}




}