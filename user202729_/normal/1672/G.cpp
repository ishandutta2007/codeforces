// if I had solved F2 a little faster I would have been able to solve this in contest...
// ... right? Maybe not... turns out it's a bit harder than expected...
// ... hopefully correct ...

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

// { ==== Begin library modular ====


// { ==== Begin library modmultiply64 ====

// identical to kactl's ModMulLL

int64_t modmultiply64(int64_t a, int64_t b, int64_t mod){
	uint64_t result=
		(uint64_t)a*(uint64_t)b-
		uint64_t((long double)a*b/mod)*(uint64_t)mod;
	result+=mod;
	if(result>=uint64_t(mod)){
		result-=mod;
		if(result>=uint64_t(mod)) result-=mod;
	}
	return int64_t(result);
}

// } ==== End library modmultiply64 ====

// { ==== Begin library extended_gcd ====

/**
 * input: (x, y)
 *
 * return (a, ax) such that a=ax*x+ay*y for some ay
 */
template<class T> struct extended_gcd_result { T a, ax; };
template<class T> extended_gcd_result<T> extended_gcd(T x, T y){
	static_assert(std::is_signed<T>::value, ""); // otherwise ax will fail...
	T a=x,b=y, ax=1,bx=0;
	while(b!=0){
		T q=a/b, t=a%b;
		a=b; b=t;
		t=T(ax-bx*q); ax=bx; bx=t;
	}
	
	return {a, ax};
}

// } ==== End library extended_gcd ====

// { ==== Begin library codecrunch_patch ====

#if __GNUC__<=4  // oops, codecrunch version is too old
#define IFCONSTEXPR__ if
#else
#define IFCONSTEXPR__ if constexpr
#endif

#if __cplusplus<=201199
#define CONSTEXPRIASSIGN__
#else
#define CONSTEXPRIASSIGN__ constexpr
#endif

// } ==== End library codecrunch_patch ====
template<class F, bool comparable=false> struct Modular_ {
	static auto MOD()
#define MOD (F::get())
	->decltype(MOD){ return MOD; }
	using T=typename std::decay<decltype(MOD)>::type;

	T val;
	explicit operator T() const { return val; }
	Modular_():val(){
		#if hasdebugprint
		assert(gdbgetstr(*this));
		#endif
	}
	#if hasdebugprint
	DEFINEGETSTR(Modular_)
	#endif

	template<class U> static auto check_can_mod_mod()->decltype(std::declval<U>()%MOD, void());
	template<class U
		, class=decltype(check_can_mod_mod<U>()) // sfinae
		> Modular_(U v)
		{
			IFCONSTEXPR__ (std::is_unsigned<T>::value){
				assert(v>=0);
			}

			/*
			val=T(v%MOD);
			if(val<0)val+=MOD;
			*/
			val=T(v%MOD);
			if(val<0)val+=MOD;
		}

	template<class U> static Modular_ raw(U value){ // for micro-optimizations
		assert(0<=value); assert(value<MOD);
		Modular_ result; result.val=value; return result;
	}

#define COMPAREOP(OP) \
	template <bool _=comparable> \
	[[nodiscard]] typename std::enable_if<_, bool>::type operator OP(Modular_ b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	[[nodiscard]] Modular_ operator+() const{ return *this; }
	[[nodiscard]] friend Modular_ operator-(Modular_ x) { x.val=x.val?MOD-x.val:0; return x; }
	Modular_& operator+=(Modular_ m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	Modular_& operator-=(Modular_ m) {
		if(std::is_signed<T>::value){
			if ((val -= m.val) < 0) val += MOD;
		}else{
			if (val < m.val) val+=MOD; 
			val-=m.val;
		}
		return *this;
	}
	Modular_& operator*=(Modular_ m) {
		//if(__builtin_constant_p(m.val)){
		//	switch(m.val){
		//		case 1: return *this;
		//		case 2: return *this+=*this;
		//		case 3: return *this+=*this+*this;
		//		case 0: return *this=0;
		//		case -1: return *this=-*this;
		//	}
		//}else if(__builtin_constant_p(val)){
		//	return *this=m**this;
		//}


		IFCONSTEXPR__(std::is_same<T, int>::value){
			val = int((int64_t)val*m.val%MOD);
		}else IFCONSTEXPR__(std::is_same<T, int64_t>::value){
			val=modmultiply64(val, m.val, MOD);
		}else{
			// TODO?
			val*=m.val;
			val%=MOD;
			//assert(false);
		}
		return *this;
	}
	template<class U>
	[[nodiscard]] Modular_ pow(U p) const {
		IFCONSTEXPR__(std::is_signed<U>::value) assert(p>=0);
		Modular_ a=*this;
		Modular_ ans = 1; for (; p; p >>= 1, a *= a) if (p&1) ans *= a;
		return ans;
	}
	[[nodiscard]] Modular_ inv() const {
		auto tmp=extended_gcd(val, T(MOD));
		assert(tmp.a==1);
		if(tmp.ax<0)tmp.ax+=MOD;
		return raw(tmp.ax);
	}
	Modular_& operator/=(Modular_ m) { return (*this) *= m.inv(); }
	friend std::ostream& operator<<(std::ostream& stream, Modular_ m) { return stream<<m.val<<'_'; }

	

#define ARITHBINARYOP(OP) [[nodiscard]] friend Modular_ operator OP(Modular_ a, Modular_ b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP

#undef MOD
};

template<class T, T x> struct TGetter{ static T get(){ return x; } };
template<int MOD> using Modular=Modular_<TGetter<int, MOD>>;
template<int64_t MOD> using Modular64=Modular_<TGetter<int64_t, MOD>>;
template<int MOD> using ModularComparable=Modular_<TGetter<int, MOD>, true>;
template<int64_t MOD> using ModularComparable64=Modular_<TGetter<int64_t, MOD>, true>;
template<int const& MOD> using ModularP=Modular_<TGetter<int const&, MOD>>; // warning: must use global variable (with linkage)
template<int64_t const& MOD> using ModularP64=Modular_<TGetter<int64_t const&, MOD>>; // warning: must use global variable (with linkage)

// } ==== End library modular ====

// { ==== Begin library transpose ====

template<std::size_t N> void _resize_optional(std::bitset<N> const& data, std::size_t size){}
template<class T, std::size_t N> void _resize_optional(std::array<T, N> const& data, std::size_t size){}
template<class T> void _resize_optional(T& data, std::size_t size){ data.resize(size); }

template<class V> [[nodiscard]] V transpose(V const& data){
	assert(not data.empty());
	V transpose(data[0].size());
	for(int const row: range(0, int(data[0].size()))){
		_resize_optional(transpose[row], data.size());
		for(int const col: range(0, int(data.size()))){
			assert(data[col].size()==data[0].size());
			transpose[row][col]=data[col][row];
		}
	}
	return transpose;
}



// } ==== End library transpose ====

// { ==== Begin library rref ====

/*
 * compute the reduced row echelon form... (mod 2)
 * delete the remaining zero rows.
 */
template<std::size_t N>
void rref(
		std::vector<std::bitset<N>>& data, int numCol){
	assert(numCol<=int(N));
	int lockRow=0;
	auto const numRow=int(data.size());
	for(int const col: range(0, numCol)){
		for(int const row: range(lockRow, numRow)){
			if(data[row][col]){
				if(row!=lockRow)
					std::swap(data[row], data[lockRow]);
				for(int const row: range(0, numRow)){
					if(row!=lockRow and data[row][col]){
						data[row]^=data[lockRow][col];
					}
				}
				++lockRow;
				break;
			}
		}
	}
	data.erase(data.begin()+lockRow, data.end());
}

// } ==== End library rref ====

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
using modular=Modular<998244353>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const numRow=read<int>();
	int const numCol=read<int>();
	
	int result {}; // number of degree of freedom
	if(numRow%2==0 and numCol%2==0){
		for(int _=numRow*numCol; _--;){
			char ch; std::cin>>ch;
			result+=ch=='?';
		}
	}else{

		auto const solveAlternative=[](std::vector<std::string> board)->int{
			// return number of degree of freedom under the following condition...
			assert(board.size()%2!=0);
			assert(board[0].size()%2==0);

			std::vector<char> xorCol(board[0].size()), anyQuestion(board[0].size());
			int numQuestion {};
			for(auto& row: board)
				for(int const col: range(0, int(row.size()))){
					xorCol[col]^=row[col];
					anyQuestion[col] = anyQuestion[col] or row[col]=='?';
					numQuestion+=row[col]=='?';
				}

			for(auto& item: xorCol) item&=1;
			int noQuestionParity=-1, numQuestionCol {};
			for(int const col: range(0, int(xorCol.size()))){
				if(anyQuestion[col]){
					numQuestionCol++;
				}else{
					if(noQuestionParity<0){
						noQuestionParity=xorCol[col];
					}else if(noQuestionParity!=xorCol[col]){
						std::cout<<"0\n";
						std::exit(0);
					}
				}
			}

			return numQuestion-numQuestionCol+(numQuestionCol==int(xorCol.size()));
		};

		std::vector<std::string> board(numRow);
		for(auto& row: board) std::cin>>row;
		if(numRow%2==0 and numCol%2!=0){
			result=solveAlternative(std::move(transpose(board)));
		}else if(numRow%2!=0 and numCol%2==0){
			result=solveAlternative(std::move(board));
		}else{
			// both sides are odd.

			std::vector<char> xorRow(numRow);
			std::vector<char> xorCol(board[0].size());
			for(int const row: range(0, numRow))
				for(int const col: range(0, numCol)){
					xorCol[col]^=board[row][col];
					xorRow[row]^=board[row][col];
				}
			for(auto& item: xorRow) item&=1;
			for(auto& item: xorCol) item&=1;


			modular result {}; // this one is not the number of degree of freedom!
			for(int const parity: range(0, 2)){
				
				int curDegree=0;
				std::vector<char> seenRow(numRow), seenCol(numCol);
				struct CannotSatisfy {};

#define dfsRow(row) dfs(row, std::true_type {})
#define dfsCol(col) dfs(col, std::false_type {})

				int numQuestion, curXorRow, curXorCol, numEntry/*row or col*/;
				auto const resetDfs=[&]{
					numQuestion=curXorRow=curXorCol=numEntry=0;
				};

				auto const dfs=makeYComb([&](auto dfs, int index, auto is_row)->void{
					if(is_row.value){
						int row=index;
						if(seenRow[row]) return;

						seenRow[row]=true;
						numEntry++;
						curXorRow^=xorRow[row];
						for(int const col: range(0, numCol)){
							if(board[row][col]=='?'){
								numQuestion++;
								dfsCol(col);
							}
						}
					}else{
						int col=index;
						if(seenCol[col]) return;

						seenCol[col]=true;
						numEntry++;
						curXorCol^=xorCol[col];
						for(int const row: range(0, numRow)){
							if(board[row][col]=='?'){
								//numQuestion++; // don't double count.
								dfsRow(row);
							}
						}
					}
				});

				auto const postprocess=[&]{
					assert(numQuestion>=numEntry-1);
					assert(numEntry>=1);
					assert(
							(
							 (numEntry*parity)&1)
							==
							(
							 (numEntry&parity)&1));
					assert(curXorRow==(curXorRow&1));
					assert(curXorCol==(curXorCol&1));

					if((curXorRow xor curXorCol) != (
								numEntry&parity&1
								))
						throw CannotSatisfy {};

					curDegree+=numQuestion-(numEntry-1);
				};

				try{
					for(int const row: range(0, numRow)) if(not seenRow[row]) {
						resetDfs();
						dfsRow(row);
						postprocess();
					}
					for(int const col: range(0, numCol)) if(not seenCol[col]) {
						resetDfs();
						dfsCol(col);
						postprocess();
					}
				}catch(CannotSatisfy){
					continue; // next parity
				}
#undef dfsRow
#undef dfsCol
				result+=modular(2).pow(curDegree);

			}
			std::cout<<int(result)<<'\n';
			return 0;
		}
	}
	std::cout<<int(modular(2).pow(result))<<'\n';
}

// time-limit: 1000
// problem-url: https://codeforces.com/contest/1672/problem/G