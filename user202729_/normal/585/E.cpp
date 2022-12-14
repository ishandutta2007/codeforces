// :(
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>



#define MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE 1
int const MOD=1000000007;
struct modular {
	int val;
	explicit constexpr operator int() const { return val; }
	constexpr modular():val(){}
#if MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE
	constexpr modular(auto v):val(int(v%MOD)){ if(val<0)val+=MOD; }
#else
	constexpr modular(int v):val(v){
		assert(0<=v and v<MOD);
	}
#endif

#define COMPAREOP(OP) bool constexpr operator OP(modular b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	friend modular operator-(modular x) { x.val=x.val?MOD-x.val:0; return x; }
	modular constexpr& operator+=(modular m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular constexpr& operator-=(modular m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular constexpr& operator*=(modular m) {
		if(__builtin_constant_p(m.val)){
			switch(m.val){
				case 1: return *this;
				case 2: return *this+=*this;
				case 3: return *this+=*this+*this;
				case 0: return *this=0;
				case -1: return *this=-*this;
			}
		}else if(__builtin_constant_p(val)){
			*this=m**this;
		}
		val = int((int64_t)val*m.val%MOD);
		return *this;
	}
	modular constexpr pow(int p) const {
		modular a=*this;
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	modular constexpr inv() const {
		int a=val,b=MOD, ax=1,bx=0;
		while(b){
			int q=a/b, t=a%b;
			a=b; b=t;
			t=ax-bx*q; ax=bx; bx=t;
		}
		assert(a==1);
		if(ax<0)ax+=MOD;
		return ax;
	}
	modular constexpr& operator/=(modular m) { return (*this) *= m.inv(); }

#define ARITHBINARYOP(OP) friend modular constexpr operator OP(modular a, modular b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> values(number);
	for(auto & item: values) std::cin>>item;
	std::sort(begin(values),end(values));
	
	std::vector<int> count(1+values.back());
	for(auto item: values) count[item]+=1;
	// now count[value]=count of value
	for(int value=1;value<(int)count.size();++value) 
		for(int multiple=value*2;multiple<(int)count.size();multiple+=value) 
			count[value]+=count[multiple];

	std::vector<modular> f(count.size());
	std::transform(1+begin(count),end(count), 1+begin(f),[&](int value){ return modular(2).pow(value)-1; });
	// now f[value]=count of nonempty subsets with gcd divisible by value
	auto const numSubset=modular(2).pow(number)-1;
	assert(f[1]==numSubset);

	std::vector<int> mob(f.size(), 2); // Mobius function
	mob[1]=1;
	for(int value=2;value<(int)mob.size();++value) if(mob[value]==2){
		// value is a prime
		if(value*(int64_t)value<(int)mob.size()){
			for(int multiple=value*value; multiple<(int)mob.size(); multiple+=value*value) 
				mob[multiple]=0;
		}
		for(int multiple=value;multiple<(int)mob.size(); multiple+=value) {
			if(mob[multiple]==2) mob[multiple]=1;
			mob[multiple]=-mob[multiple];
		}
		assert(mob[value]==-1);
	}

	decltype(f) g(f.size());
	for(int value=2;value<(int)f.size();++value) if(mob[value]!=0){
		assert(mob[value]==1 or mob[value]==-1);
		for(int multiple=value; multiple<(int)g.size(); multiple+=value) 
			g[multiple]-=f[value]*mob[value];
	}

	// now g[value]=count of subsets with gcd not coprime with value
	assert(g[1]==0);

	modular numSubsetWithGCD1=0;
	for(int value=1;value<(int)f.size();++value) numSubsetWithGCD1+=f[value]*mob[value];

	modular result=0;
	for(auto item: values)
		result+=numSubset-numSubsetWithGCD1-g[item];
	std::cout<<(int)result<<'\n';
}