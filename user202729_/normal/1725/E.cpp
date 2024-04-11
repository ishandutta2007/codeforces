// (what happened with the compiler warning system?)
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



auto const endValue=int(2e5)+1;
auto const minFactor=minFactorF(endValue);

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const number=read<int>();

	std::vector<std::vector<int>> nodesOfFactor(endValue+1);
	for(int const node: range(0, number)){
		int a=read<int>();
		while(a!=1){
			auto p=minFactor[a];
			do a/=p; while(a%p==0);
			nodesOfFactor[p].push_back(node);
		}
	}

	std::vector<std::vector<int>> add(number);
	for(int _=number-1; _--;){
		int const u=read<int>()-1;
		int const v=read<int>()-1;
		add[u].push_back(v);
		add[v].push_back(u);
	}

	// LCA by HLD
	int const root=0;

	std::vector<int> subtreeSize(number);

	std::vector<int> preorder(number);
	int countedOrder=0;

	makeYComb([&](auto work, int node)->int{
		preorder[node]=countedOrder++;
		subtreeSize[node]=1;
		for(auto other: add[node]){
			add[other].erase(std::find(begin(add[other]), end(add[other]), node));
			// delete parent edge
			subtreeSize[node]+=work(other);
			// compute subtreeSize
		}

		if(not add[node].empty()){
			for(int const i: range(1, int(add[node].size()))){
				if(subtreeSize[add[node][i]]>subtreeSize[add[node][0]]){
					std::swap(add[node][i], add[node][0]);
				}
			}
		}
		// now the heavy child is the first child

		return subtreeSize[node];
	})(root);

	assert(countedOrder==number);

	std::vector<int> chainTop(number); // as in HLD chain
	std::vector<int> chainPar(number); // par of chainTop
	std::vector<int> depth(number);

	depth[root]=0;
	chainTop[root]=root;
	chainPar[root]=-1;

	makeYComb([&](auto work, int node)->void{
		for(auto other: add[node]){
			chainTop[other]=other==add[node][0] ? chainTop[node]: other;
			chainPar[other]=other==add[node][0] ? chainPar[node]: node;
			depth[other]=depth[node]+1;
			work(other);
		}
	})(root);

	auto const lca=[&](int x, int y){
		while(chainTop[x]!=chainTop[y]){
			if(depth[chainTop[x]]<depth[chainTop[y]]){ // first time I implement it like this, originally mistook this to be depth[x]<depth[y] (need to prove more carefully ???)
				y=chainPar[y];
			}else x=chainPar[x];
		}
		return depth[x]<depth[y] ? x: y;
	};


	std::vector<int> subsetPar(number); // temp-used
	std::vector<int> subsetSubtreeSize(number); // temp-used (count number of interesting nodes below each node.)
	//std::vector<std::vector<int>> subsetChildren(number); // temp-used

	int64_t result {};
	
	for(auto& nodes: nodesOfFactor) if(not nodes.empty()){
		std::sort(begin(nodes), end(nodes), [&](auto const& first, auto const& sec){
			return preorder[first]<preorder[sec];
		});
		auto const interestingSubsetSize=int(nodes.size());
		for(int const i: range(1, interestingSubsetSize)){
			auto const x=lca(nodes[i-1], nodes[i]);
			subsetSubtreeSize[x]=0; // clear out temp-used memory
			nodes.push_back(x);
		}

		for(int const i: range(0, interestingSubsetSize)){
			subsetSubtreeSize[nodes[i]]=1;
		}



		std::sort(begin(nodes), end(nodes), [&](auto const& first, auto const& sec){
			return preorder[first]<preorder[sec];
		});
		nodes.erase(std::unique(begin(nodes), end(nodes)), end(nodes));

		auto const isParent=[&](int a, int b){
			return lca(a, b)==a;
		};

		//for(auto node: nodes) subsetChildren[node].clear();

		// figure out the subset tree structure
		std::vector<int> stack{nodes[0]};
		for(int const i: range(1, int(nodes.size()))){
			auto const node=nodes[i];
			while(not isParent(stack.back(), node)) stack.pop_back();
			subsetPar[node]=stack.back();
			//subsetChildren[stack.back()].push_back(node);
			stack.push_back(node);
		}

		// compute subsetSubtreeSize
		for(int i=int(nodes.size())-1; i>0; i--){
			subsetSubtreeSize[subsetPar[nodes[i]]]+=subsetSubtreeSize[nodes[i]];
		}
		assert(subsetSubtreeSize[nodes[0]]==interestingSubsetSize);

		for(int i=int(nodes.size())-1; i>0; i--){
			auto const edgeLength=depth[nodes[i]]-depth[subsetPar[nodes[i]]];
			assert(edgeLength>0);
			auto const a=subsetSubtreeSize[nodes[i]];
			result=(result+((a*int64_t(interestingSubsetSize-a)*(interestingSubsetSize-2))>>1)%998244353*edgeLength)%998244353;
		}
	}

	std::cout<<result<<'\n';
}


// time-limit: 3000
// problem-url: https://codeforces.com/contest/1725/problem/E