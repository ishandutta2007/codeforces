// just randomize it.
// (partially copied from some submission, but I should be able to figure out this solution myself)

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

#define MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE 0
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

	friend modular constexpr operator-(modular x) { x.val=x.val?MOD-x.val:0; return x; }
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
			return *this=m**this;
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

std::mt19937 engine(
#if LOCAL
		123456
#else
		std::chrono::duration_cast<std::chrono::nanoseconds>(
			std::chrono::steady_clock::now().time_since_epoch()).count()
#endif
		);

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::array<int, 26> reversePermutation;
	//for(auto & it: reversePermutation){ std::cin>>it; --it; }
	for(int index=0;index<26;++index) {
		int value; std::cin>>value;
		reversePermutation[--value]=index;
	}
	std::string s, t; std::cin>>s>>t;
	auto const n=1<<ceil_log2((int)t.size()+(int)s.size()-1);
	for(auto & ch: s) ch=char(ch-'a');
	for(auto & ch: t) ch=char(ch-'a');

	std::array<std::vector<modular>, 10> data;
	for(auto & it: data) it.resize(n);

	std::reverse(begin(t),end(t));

	std::array<modular, 26> val;
	std::generate(begin(val),end(val), [&]{ return std::uniform_int_distribution<int>(1, MOD-1)(engine); });

#define L [&](auto it)
//#define A it
//#define B reversePermutation[it]
#define A val[it]
#define B val[reversePermutation[it]]

	std::transform(begin(s),end(s), begin(data[0]), L{ return   modular(A*A*A*A);   });
	std::transform(begin(s),end(s), begin(data[1]), L{ return   -modular(A*A*A*2);   });
	std::transform(begin(s),end(s), begin(data[2]), L{ return   modular(A*A);   });
	std::transform(begin(s),end(s), begin(data[3]), L{ return   -modular(2*A);   });
	std::transform(begin(s),end(s), begin(data[4]), L{ return   modular(1);   });

	std::transform(begin(t),end(t), begin(data[5]), L{ return   modular(1);  });
	std::transform(begin(t),end(t), begin(data[6]), L{ return   modular(A+B); });
	std::transform(begin(t),end(t), begin(data[7]), L{ return   modular( (A+B)*(A+B)+2*A*B   ); });
	std::transform(begin(t),end(t), begin(data[8]), L{ return   modular( A*B*(A+B)   ); });
	std::transform(begin(t),end(t), begin(data[9]), L{ return   modular( A*A*B*B   ); });

#undef L
#undef A
#undef B

	auto const t_size=(int)t.size();

	for(auto & it: data) fft(it);

	std::vector<modular> result(n);
	for(int index=0;index<n;++index)
		result[index]=
			data[0][index]*data[5][index]+
			data[1][index]*data[6][index]+
			data[2][index]*data[7][index]+
			data[3][index]*data[8][index]+
			data[4][index]*data[9][index];
	ifft(result);


	for(int index=t_size-1; index>=(int)s.size()-1; --index)
		std::cout<<((int)result[index]==0);
	std::cout<<'\n';
}