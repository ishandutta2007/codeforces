/*
I've learned this before, how could I forget that...
[at least I didn't read the editorial]
I figured out the formula with some help from Mathematica. How would I solve
the problem int the real	contest...

UPD: Silly integer overflow issue. Need more assertions.
*/


#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

#define MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE 1
int const MOD=998244353;
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

unsigned constexpr ceil_log2(unsigned x){
	return 31^__builtin_clz(2*x-1);
}
unsigned constexpr revbit(unsigned x){
	x=(x&0x55555555)<<1|((x>>1)&0x55555555);
	x=(x&0x33333333)<<2|((x>>2)&0x33333333);
	x=(x&0x0f0f0f0f)<<4|((x>>4)&0x0f0f0f0f);
	x=(x&0x00ff00ff)<<8|((x>>8)&0x00ff00ff);
	return x>>16|x<<16;
}

void fft(std::vector<modular>& a){
	static auto const roots=[]{
		std::vector<modular> roots={31};
		while(roots.back()!=MOD-1){
			roots.push_back(roots.back()*roots.back());
		}
		return roots;
	}();

	int n=ceil_log2((int)a.size());
	a.resize(1<<n);
	for(unsigned i=1;i<a.size();++i){
		unsigned j=revbit(i)>>(32-n);
		if(i<j)std::swap(a[i],a[j]);
	}

	auto iter=end(roots);
	for(unsigned blocksize=1;blocksize<a.size();blocksize<<=1){
		auto w=*--iter;
		for(unsigned base=0;base<a.size();base+=blocksize*2){
			modular x=1;
			for(unsigned i=0;i<blocksize;++i,x*=w){
				auto& even=a[base+i];
				auto& odd=a[base+blocksize+i];
				auto p=x*odd;
				odd=even-p;
				even=even+p;
			}
		}
	}
}

void ifft(std::vector<modular>& a){
	fft(a);
	std::reverse(++a.begin(),a.end());
	modular invn=modular(a.size()).inv();
	for(modular& x:a)x*=invn;
}

/*
struct poly{
	std::vector<modular> d;
	modular& operator[](std::size_t x){return d[x];}
	modular const& operator[](std::size_t x) const {return d[x];}

	friend poly operator*(poly a,poly b){
		if(a.d.empty() or b.d.empty()) return {{}};

		auto const new_size=1<<ceil_log2(unsigned(a.d.size()+b.d.size()-1));
		a.d.resize(new_size);
		b.d.resize(new_size);

		fft(a.d);
		fft(b.d);
		std::transform(begin(a.d),end(a.d),begin(b.d),begin(a.d),std::multiplies<modular>{});
		ifft(a.d);
		while(not a.d.empty() and a.d.back()==0)
			a.d.pop_back();

		return a;
	}
};
*/

std::vector<modular> fact;

void transform(std::vector<modular> &p, int factor){
	if(p.size()==1) return;
	auto const lg_mid=31^__builtin_clz(p.size()-1);
	auto const mid=1<<lg_mid;
	assert(mid<(int)p.size());
	assert(mid*2>=(int)p.size());

	std::vector<modular> temp(begin(p)+mid, end(p));
	transform(temp, factor);
	temp.resize(mid*2);
	fft(temp);

	std::vector<modular> temp2(mid*2);
	assert(factor==-1 or factor==1);
	for(int i=0;i<=mid;++i) temp2[i]=fact[mid]/(fact[i]*fact[mid-i]) *
		((mid-i)%2!=0 and factor==-1 ? -1 : 1);
	fft(temp2);

	std::transform(begin(temp),end(temp),begin(temp2),begin(temp),std::multiplies{});
	ifft(temp);

	temp.resize(p.size());
	p.resize(mid);
	transform(p,factor);
	std::transform(begin(p),end(p),begin(temp),begin(temp),std::plus{});
	p=std::move(temp);
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; int64_t numStep; std::cin>>n>>numStep;

	fact.resize(n+2);
	fact[0]=1;
	for(int i=1;i<(int)fact.size();++i) 
		fact[i]=fact[i-1]*i;

	std::vector<modular> p(n+1);
	for(auto &x: p) std::cin>>x.val;

	assert(std::cin);
	{
		char c; assert(not (std::cin>>c));
	}

	transform(p,1);
	for(int i=0;i<=n;++i) p[i]*=modular(i+1).pow(-numStep%(MOD-1)+(MOD-1));
	transform(p,-1);

	for(auto x: p) std::cout<<(int) x<<' ';
	std::cout<<'\n';
}