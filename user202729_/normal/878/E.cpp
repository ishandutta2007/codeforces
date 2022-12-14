// are older contests easier?...

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
template<class F> // mod = F{}(). F must be default-constructible and cheap to construct
struct Modular_ {
	using T=typename std::decay<decltype(F{}())>::type;
	static constexpr T MOD=F{}();
	T val;
	explicit constexpr operator T() const { return val; }
	constexpr Modular_():val(){}
#if 1 // slightly less efficient to construct, easier to implement
	constexpr Modular_(auto v):val(T(v%MOD)){ if(val<0)val+=MOD; }
#else
	constexpr Modular_(T v):val(v){
		assert(0<=v and v<MOD);
	}
#endif

#define COMPAREOP(OP) [[nodiscard]] bool constexpr operator OP(Modular_ b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	[[nodiscard]] friend Modular_ constexpr operator-(Modular_ x) { x.val=x.val?MOD-x.val:0; return x; }
	Modular_ constexpr& operator+=(Modular_ m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	Modular_ constexpr& operator-=(Modular_ m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	Modular_ constexpr& operator*=(Modular_ m) {
		if(__builtin_constant_p(m.val)){
			switch(m.val){
				case 1: return *this;
				case 2: return *this+=*this;
				case 3: return *this+=*this+*this;
				case 0: return *this=0;
				case -1: return *this=-*this;
			}
		}else if(__builtin_constant_p(val)){
			return *this=m**this;
		}

		bool constexpr is_int=std::is_same<T, int>::value;
		bool constexpr is_int64_t=std::is_same<T, int64_t>::value;
		static_assert(is_int or is_int64_t, "Mod type not supported");

		if(is_int){
			val = int((int64_t)val*m.val%MOD);
		}else{
			uint64_t result=
				(uint64_t)val*(uint64_t)m.val-
				uint64_t((long double)val*m.val/MOD)*(uint64_t)MOD;
			result+=MOD;
			if(result>=MOD){
				result-=MOD;
				if(result>=MOD) result-=MOD;
			}
			val=result;
		}
		return *this;
	}
	template<class U>
	[[nodiscard]] Modular_ constexpr pow(U p) const {
		Modular_ a=*this;
		Modular_ ans = 1; for (; p; p >>= 1, a *= a) if (p&1) ans *= a;
		return ans;
	}
	[[nodiscard]] Modular_ constexpr inv() const {
		T a=val,b=MOD, ax=1,bx=0;
		while(b){
			T q=a/b, t=a%b;
			a=b; b=t;
			t=ax-bx*q; ax=bx; bx=t;
		}
		assert(a==1);
		if(ax<0)ax+=MOD;
		return ax;
	}
	Modular_ constexpr& operator/=(Modular_ m) { return (*this) *= m.inv(); }

#define ARITHBINARYOP(OP) [[nodiscard]] friend Modular_ constexpr operator OP(Modular_ a, Modular_ b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP

#undef MOD
};

template<int MOD> using Modular=Modular_<std::integral_constant<int, MOD>>;

template<class T, T const& x> struct TPointerGetter{ T operator()() const{ return x; } };
template<int const& x> using IntPointerGetter=TPointerGetter<int, x>;
template<int const& MOD> using ModularP=Modular_<IntPointerGetter<MOD>>;

using modular=Modular<1000000007>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, numQuery; std::cin>>number>>numQuery;

	std::vector<int> values(number);
	int constexpr MAX_VALUE=1000000000;
	for(auto& it: values){
		std::cin>>it;
		assert(-MAX_VALUE<=it and it<=MAX_VALUE);
	}

	struct Step{int left, value;};
	std::vector<Step> step(number+1);
	// step[right]= {left, getValue(left, right)} (with maximum such left value)
	// or {-1, INT_MAX} if the left value does not exist

	std::vector<modular> suffixValue(number+1);
	for(auto index=number; index--;)
		suffixValue[index]=values[index]+suffixValue[index+1]*2;

	auto const getValue=[&](int left, int right)->modular{
		return suffixValue[left]-suffixValue[right]*modular(2).pow(right-left);
	}; // values[left]+values[left+1]*2+values[left+2]*4+...

#if 0 // slowly compute step
	for(int right=0; right<=number; ++right){
		int left=right; int64_t value=0;

		while(true){
			if(left==0 or value>MAX_VALUE){
				step[right]={-1, INT_MAX};
				break;
			}else if(value<0){
				assert(value>=-MAX_VALUE);
				step[right]={left, decltype(MAX_VALUE)(value)};
				break;
			}

			// value=values[left]+values[left+1]*2+values[left+2]*4+...+values[right-1]*something
			value=value*2+values[--left];
		}
	}
#else // quickly compute step
	struct Item{
		int left; // maximum left value...
		int value; // floor of value divided by something...
		bool operator<(Item other) const{return value<other.value;}
	};
	std::vector<Item> items;
	for(int right=0;; ++right){
		assert(MAX_VALUE<=modular::MOD);

		int maxLeft=-1;
		for(auto [left, value]: items) if(value<0)
			maxLeft=std::max(maxLeft, left);
		if(maxLeft==-1)
			step[right]={-1, INT_MAX};
		else
			step[right]={maxLeft, (int)getValue(maxLeft, right)-modular::MOD};

		if(right==number) break;

		for(auto& it: items)
			it.value=(it.value>>1)+values[right];
		items.push_back({right, values[right]});

		std::sort(begin(items), end(items),[&](auto first, auto sec){
			return first.value!=sec.value ? first.value<sec.value: first.left>sec.left;
		});
		items.erase(std::unique(begin(items), end(items),[&](auto first, auto sec){
			return first.value==sec.value;
		}), items.end());
	}
#endif

	struct Jump{int left; int64_t value;};
	std::vector<std::vector<Jump>> jump;
	jump.emplace_back(step.size());
	std::transform(begin(step), end(step), jump.back().begin(),[&](Step it){return Jump{it.left, it.value};});
	while(true){
		std::vector<Jump> next=jump.back();
		bool useful=false;
		for(auto&[left, value]: next) if(left>=0){
			auto const [nextLeft, nextValue]=jump.back()[left];
			left=nextLeft;
			if(left>=0){
				useful=true;
				value+=nextValue;
			}else{
				assert(nextValue==INT_MAX);
				value=INT_MAX;
			}
		}
		if(useful) jump.push_back(std::move(next)); else break;
	}

	for(int _=0; _<numQuery; ++_){
		int left, right; std::cin>>left>>right;--left;
		modular result{};
#if 0
		while(step[right].left>left){
			result+=modular(step[right].value)*2;
			right=step[right].left;
		}
#else
		for(auto layer=jump.size(); layer--;){
			if(auto const cur=jump[layer][right]; cur.left>left){
				std::tie(result, right)=std::pair(result+modular(cur.value)*2, cur.left);
			}
		}
#endif
		result+=getValue(left, right);

		std::cout<<(int)result<<'\n';
	}
}