// time-limit: 3000
// problem-url: https://codeforces.com/contest/1687/problem/E

// nice problem :o but I'm way too slow to solve it
// (I mean, it's not like I don't say problems I can't solve to be nice but... need to solve first.........)
//
// with a small unproven detail >< hypergeometric sum

// <while implementing>

// and some large unproven detail**s**



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

// { ==== Begin library PrimeSieve.h ====

std::vector<int> minFactorF(int const limit){
	std::vector<int> minFactor(limit);
	for(int p=2; p<(int)minFactor.size(); ++p) if(minFactor[p]==0){
		minFactor[p]=p;
		if((int64_t)p*p<(int)minFactor.size())
			for(int j=p*p; j<(int)minFactor.size(); j+=p)
				if(minFactor[j]==0)
					minFactor[j]=p;
	}
	return minFactor;
}

template<class F> auto computeMultiplicativeFunction(F f, std::vector<int> const& minFactor_){
	// f: (prime, exponent, product) -> value -- return type=return type of f
	std::vector<decltype(f(2, 1, 2))> result(minFactor_.size(), 1);
	for(int prime=2; prime<(int)result.size(); ++prime) if(minFactor_[prime]==prime){
		for(auto [exponent, product]=std::make_pair(1, (int64_t)prime); product<(int)result.size(); product*=prime, exponent++) [&]{
			auto const value=f(prime, exponent, (int)product);
			for(int k=0;; ++k)
			for(int f=1; f<prime; ++f){
				auto const x=(prime*k+f)*product;
				if(x>=(int)result.size()) return;
				result[x]*=value;
			}
		}();
	}
	// * n log n, slow?
	return result;
}

#define MakeFunction(N, E) \
auto N(std::vector<int> const& minFactor_){ \
	return computeMultiplicativeFunction([&]( \
				[[maybe_unused]] int prime, [[maybe_unused]] int exponent, [[maybe_unused]] int product){ \
		return E; \
	}, minFactor_); \
} \
auto N(int limit){ return N(minFactorF(limit)); }


MakeFunction(MobiusF, (signed char)(exponent>=2 ? 0: -1))
MakeFunction(phiF, int(product/prime*(prime-1)))


std::vector<char> isCompositeF(int const limit){
	std::vector<char> isComposite(limit);
	std::vector<int> exponents;
	for(int p=2; p<(int)isComposite.size(); ++p) if(not isComposite[p]){
		if((int64_t)p*p<limit)
		for(int j=p*p; j<(int)isComposite.size(); j+=p)
			isComposite[j]=true;
	}
	return isComposite;
}

std::vector<int> primesF(int const limit){
	std::vector<int> primes;
	auto const isComposite=isCompositeF(limit);
	for(int p=2; p<limit; ++p)
		if(not isComposite[p]) primes.push_back(p);
	return primes;
}

// } ==== End library PrimeSieve.h ====

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
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const number=read<int>();
	std::vector<int> a_(number);
	for(auto& it: a_) {
		std::cin>>it;
	}
	auto const a=std::move(a_); // ???
	
	// possibly overcomplicated algorithm
	auto minFactor=minFactorF(1+*std::max_element(begin(a), end(a)));
	std::vector<int> primeSeenCount(minFactor.size());
	for(auto it: a){
		while(it!=1){
			primeSeenCount[minFactor[it]]++;
			it/=minFactor[it];
		}
	}

	//std::vector<int> densePrimes;

	std::vector<char> keep(number);

	auto const order=[&](int prime, int value){
		int result {};
		while(value%prime==0){value/=prime; result++;}
		return result;
	};

	std::vector<int> indices=range(number).collect<std::vector<int>>();  // I should really just switch to C++20's range library...?

	for(int const p: range(0, int(primeSeenCount.size()))){
		if(primeSeenCount[p]*2>=number){
			//densePrimes.push_back(p);
			// p is dense
			// there are only a very small number of dense primes

			std::sort(begin(indices), end(indices), [&](auto const& first, auto const& sec){
				auto const order1=order(p, a[first]), order2=order(p, a[sec]);
				if(order1!=order2) return order1<order2;
				return keep[first]>keep[sec]; // keep=1 put before keep=0.
			});

			keep[indices[0]]=keep[indices[1]]=true;
		}
	}

	for(int _=60; _--;){
		keep[std::uniform_int_distribution<int>(0, int(keep.size())-1)(engine)]=true;
	}  // this is also part of the unproven magic


	indices.clear();
	for(int const i: range(0, int(keep.size()))){
		if(keep[i]) indices.push_back(i);
	}

	assert(indices.size()<=120);

	auto const computeTarget=[&]{
		std::map<int, int> result; // map {prime  exponent in target}
		for(auto index: indices) if(index>=0){
			auto it=a[index];
			while(it!=1){
				auto const p=minFactor[it]; it/=p;
				if(not result.count(p)){
					int smallest=INT_MAX, secondSmallest=INT_MAX; // exponent
					for(auto index: indices) if(index>=0){
						secondSmallest=std::min(secondSmallest, order(p, a[index]));
						if(secondSmallest<smallest) std::swap(smallest, secondSmallest);
					}
					assert(number>=2); // therefore...
					assert(secondSmallest<INT_MAX);

					result[p]=smallest+secondSmallest;
				}
			}
		}

		for(auto iter=result.begin(); iter!=result.end();){
			if(iter->second==0) iter=result.erase(iter);
			else ++iter;
		}

		return result;
	};

	auto target=computeTarget();
	for(auto& index: indices){
		auto tmp=index;
		index=-1;
		if(computeTarget()!=target) index=tmp; // restore old value
	}

	indices.erase(std::remove(begin(indices), end(indices), -1), end(indices));

	assert(indices.size()<=14); // huh. (sure? since p#(1e6) = 7 but...??? I can only informally prove it's  16?)
	// <do some calculation>
	// seems barely pass...?


	// should learn theory properly some day
	
	int numOp;
	for(int const mask: range(1, int(1<<indices.size()))){
		int setSize=__builtin_popcount(mask);
		int weight=setSize%2==0 ? setSize-2: 2-setSize;
		numOp+=std::abs(weight);
	}

	std::cout<<numOp<<'\n';
	for(int const mask: range(1, int(1<<indices.size()))){
		int setSize=__builtin_popcount(mask);
		int weight=setSize%2==0 ? setSize-2: 2-setSize;
		for(int _=std::abs(weight); _--;){
			std::cout<<
			(weight>0 ? "0 ": "1 ")
			<<setSize;
			for(int const i: range(0, int(indices.size()))){
				if(mask>>i&1)
				std::cout<<' '<<indices[i]+1;
			}
			std::cout<<'\n';
		}
	}
}