// time-limit: 2000
// problem-url: https://codeforces.com/contest/1599/problem/F

// hackable
// but I have no other idea

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>



std::mt19937 engine( std::chrono::duration_cast<std::chrono::nanoseconds>(
			std::chrono::steady_clock::now().time_since_epoch()).count());


template<class F> struct Modular_ {
	static auto MOD(){ return
#define MOD (F::get())
		MOD; }
	using T=typename std::decay<decltype(MOD)>::type;

	T val;
	explicit operator T() const { return val; }
	Modular_():val(){}

	template<class U> static auto check_can_mod_mod()->decltype(std::declval<U>()%MOD, void());
	template<class U
		, class=decltype(check_can_mod_mod<U>()) // sfinae
		> Modular_(U v)
		{
			/*
			val=T(v%MOD);
			if(val<0)val+=MOD;
			*/
			v%=MOD;
			if(v<0)v+=MOD;
			val=T(v);
		}

	template<class U> static Modular_ raw(U value){ // for micro-optimizations
		using V=std::common_type_t<U, decltype(MOD)>;
		assert(0<=value); assert((V)value<(V)MOD);
		Modular_ result; result.val=value; return result;
	}

#define COMPAREOP(OP) [[nodiscard]] bool operator OP(Modular_ b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	[[nodiscard]] Modular_ operator+() const{ return *this; }
	[[nodiscard]] friend Modular_ operator-(Modular_ x) { x.val=x.val?MOD-x.val:0; return x; }
	Modular_& operator+=(Modular_ m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	Modular_& operator-=(Modular_ m) {
		if(std::is_signed_v<T>){
			if ((val -= m.val) < 0) val += MOD;
		}else{
			if (val < m.val) val+=MOD; val-=m.val;
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

		if constexpr(std::is_same<T, int>::value){
			val = int((int64_t)val*m.val%MOD);
		}else if constexpr(std::is_same<T, int64_t>::value){
			uint64_t result=
				(uint64_t)val*(uint64_t)m.val-
				uint64_t((long double)val*m.val/MOD)*(uint64_t)MOD;
			result+=MOD;
			if(result>=MOD){
				result-=MOD;
				if(result>=MOD) result-=MOD;
			}
			val=result;
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
		Modular_ a=*this;
		Modular_ ans = 1; for (; p; p >>= 1, a *= a) if (p&1) ans *= a;
		return ans;
	}
	[[nodiscard]] Modular_ inv() const {
		T a=val,b=MOD, ax=1,bx=0;
		while(b!=0){
			T q=a/b, t=a%b;
			a=b; b=t;
			t=T(ax-bx*q); ax=bx; bx=t;
		}
		assert(a==1);
		if(ax<0)ax+=MOD;
		return ax;
	}
	Modular_& operator/=(Modular_ m) { return (*this) *= m.inv(); }
	friend std::ostream& operator<<(std::ostream& stream, Modular_ m) { return stream<<m.val<<'M'; }

#define ARITHBINARYOP(OP) [[nodiscard]] friend Modular_ operator OP(Modular_ a, Modular_ b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP

#undef MOD
};

template<class T, T x> struct TGetter{ static T get(){ return x; } };
template<int MOD> using Modular=Modular_<TGetter<int, MOD>>;
template<int const& MOD> using ModularP=Modular_<TGetter<int const&, MOD>>; // warning: must use global variable (with linkage)
template<int64_t const& MOD> using ModularP64=Modular_<TGetter<int64_t const&, MOD>>; // warning: must use global variable (with linkage)


int constexpr mod=(int)1e9+7;
using modular=Modular<mod>;

bool modSqrtable(modular x){
	return x.pow((mod-1)/2)==1;
}

modular modSqrt(modular x){
	assert(modSqrtable(x));
	assert(
			(
			 (mod-1)/2
			 +1)%2==0);
	return x.pow(((mod-1)/2+1)/2);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin>>n;
	int numQuery; std::cin>>numQuery;

	std::vector<int> pos(n);
	for(auto& it: pos) {
		std::cin>>it;
		it=(int)modular(it); //... just to be sure
	}

	std::vector<int> values=pos;
	std::sort(begin(values), end(values));
	values.erase(std::unique(begin(values), end(values)), end(values));

	std::unordered_map<int, int> indexOfValue;
	for(int i=0; i<(int)values.size(); ++i)
		indexOfValue[values[i]]=i;

	std::vector<int> sortedIndex(pos.size());
	for(int i=0; i<(int)pos.size(); ++i)
		sortedIndex[i]=int(std::lower_bound(begin(values), end(values), pos[i])-begin(values));

	struct Q{
		int index, left, right, d;
	};

	int constexpr blockSize=(int)std::sqrt(2e5);
	std::vector<std::vector<Q>> queries(n/blockSize+1);
	for(int queryIndex=0; queryIndex<numQuery; ++queryIndex){
		int l; std::cin>>l; --l;
		int r; std::cin>>r;
		int d; std::cin>>d;
		queries[l/blockSize].push_back(Q{queryIndex, l, r, d});
	}

	int left=0, right=0,
		numDiff=0; // number of distinct values in the current range == number of nonzero values in count
	modular sum=0; // sum over distinct elements
	modular sum2=0; // sum ^2, over distinct elements
	// fallback double check
	//modular sum3=0; 
	std::vector<int> count(values.size());


	std::vector<char> result(numQuery, -1);
	for(auto& block: queries){
		std::sort(begin(block), end(block),
				[&](auto const& first, auto const& sec){
					return first.right<sec.right;
				});

		for(auto [queryIndex, curLeft, curRight, d]: block){

			auto const addElement=[&](int index){
				int const s=sortedIndex[index];
				if(0==count[s]){
					numDiff+=1;
					sum+=values[s];
					sum2+=modular(values[s]).pow(2);
					//sum3+=modular(values[s]).pow(3);
				}
				++count[s];
			};

			auto const removeElement=[&](int index){
				int const s=sortedIndex[index];
				--count[s];
				if(0==count[s]){
					numDiff-=1;
					sum-=values[s];
					sum2-=modular(values[s]).pow(2);
					//sum3-=modular(values[s]).pow(3);
				}
			};

			while(left>curLeft) addElement(--left);
			while(right<curRight) addElement(right++);
			while(left<curLeft) removeElement(left++);
			while(right>curRight) removeElement(--right);

			assert(curLeft<curRight);
			assert(numDiff>=1);
			if(numDiff<=1){
				result[queryIndex]=true;
				continue;
			}else if(d==0){
				result[queryIndex]=false;
				continue;
			}
			
			modular const average=sum/numDiff;
			modular const startToEndDistance=modular(numDiff-1)*d;
			modular const first=average-startToEndDistance/2;

			// sequence: first, first+d, first+d*2, ..., first+d*(numDiff-1)

			modular const d_=modular(d);
			modular const numDiff_=numDiff;
			assert(sum
					==
					numDiff_*(d_*(numDiff_ - 1) + 2*first)/2);
			if(not(
					sum2==
			numDiff_*(d_.pow(2)*(2*numDiff_.pow(2) - 3*numDiff_ + 1) + 6*d_*first*(numDiff_ - 1) + 6*first.pow(2))/6
			//and sum3==
			//numDiff_*(d_.pow(3)*numDiff_*(numDiff_.pow(2) - 2*numDiff_ + 1) + 2*d_.pow(2)*first*(2*numDiff_.pow(2) - 3*numDiff_ + 1) + 6*d_*first.pow(2)*(
			//numDiff_ - 1) + 4*first.pow(3))/4
			)){
				// sympy-computed
				result[queryIndex]=false;
				continue;
			}

			auto const randomElement=[&]{
				return first+modular(d)*std::uniform_int_distribution(0, numDiff-1)(engine);
			};


			result[queryIndex]=[&]{
				// 2e5 * 30 * ~~20~~ ~= ~~1e8~~ fast
				for(int _=0; _<30; ++_){
					auto const x=randomElement();
					/*
					auto const index=int(std::lower_bound(begin(values), end(values), (int)x)-begin(values)); // ~20
					*/
					auto const iterator=indexOfValue.find((int)x);
					int index;
					//if(index==(int)values.size() or values[index]!=(int)x){
					if(iterator==indexOfValue.end()){
						return false;
					}
					index=iterator->second;

					if(count[index]==0)
						return false;
				}
				return true;
			}();

		}

	}

	// d==0
		
	for(auto x: result){
		assert(x==not not x);
		std::cout<<(x ? "Yes\n": "No\n");
	}
	
}