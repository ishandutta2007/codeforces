#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

int const MOD=998244353;
struct modular {
	int val;
	explicit constexpr operator int() const { return val; }
	constexpr modular():val(){}
	constexpr modular(int v):val(v){
		assert(0<=v and v<MOD);
	}

#define COMPAREOP(OP) bool constexpr operator OP(modular b) { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	modular operator-() const { return modular(val ? MOD-val : 0); }
	modular constexpr& operator+=(modular m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular constexpr& operator-=(modular m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular constexpr& operator*=(modular m) { val = (int64_t)val*m.val%MOD; return *this; }
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

struct poly{
	std::vector<modular> d;
	modular& operator[](std::size_t x){return d[x];}
	modular const& operator[](std::size_t x) const {return d[x];}

	friend poly operator*(poly a,poly b){ // not checked!
		if(a.d.empty() or b.d.empty()) return {{}};

		auto const new_size=ceil_log2(a.d.size()+b.d.size()-1);
		a.d.resize(new_size);
		b.d.resize(new_size);

		fft(a.d);
		fft(a.d);
		std::transform(begin(a.d),end(a.d),begin(b.d),begin(a.d),std::multiplies<modular>{});
		ifft(a.d);
		while(not a.d.empty() and a.d.back()==0)
			a.d.pop_back();

		return a;
	}

	poly pow(int exp)const{
		std::vector<modular> ans;
		auto const new_size=ceil_log2((d.size()-1)*exp+1);
		ans.reserve(new_size);
		ans=d;
		ans.resize((d.size()-1)*exp+1);

		fft(ans);
		for(auto& x:ans) x=x.pow(exp);
		ifft(ans);
		while(not ans.empty() and ans.back()==0)
			ans.pop_back();

		return {std::move(ans)};
	}

	modular operator()(modular x)const{
		modular ans {};
		modular base{1};
		for(auto ai:d){
			ans+=base*ai;
			base*=x;
		}
		return ans;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,nopt;std::cin>>n>>nopt;
	std::vector<int> h;h.reserve(n+1);h.resize(n);for(int& hi:h)std::cin>>hi;
	h.push_back(h[0]);

	poly p2{{1, (nopt-2+MOD)%MOD, 1}};

	int t1=0,t2=0;

	for(int i=0;i<n;++i){
		if(h[i]==h[i+1]){
			++t1;
		}else{
			++t2;
		}
	}

	poly ans{{1}};
	//assert(std::cerr<<t1<<'\n');
	//assert(std::cerr<<t2<<'\n');
	if(t2)ans=p2.pow(t2);
	if(t1){
		//poly p1{{0, nopt%MOD}};
		modular const f=modular{nopt}.pow(t1);
		std::transform(begin(ans.d),end(ans.d),begin(ans.d),[f](modular x){
				return x*f;
				});
		ans.d.insert(begin(ans.d), t1, modular{0});
	}

	auto const& f=ans.d;
	assert((int)f.size() <= 2*n+1);

	std::cout<<(int)std::accumulate(begin(f)+n+1,end(f),modular{0})<<'\n';
}