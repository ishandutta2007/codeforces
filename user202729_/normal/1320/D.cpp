
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


#define MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE 1
template<int MOD>
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

#define COMPAREOP(OP) [[nodiscard]] bool constexpr operator OP(modular b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	[[nodiscard]] friend modular constexpr operator-(modular x) { x.val=x.val?MOD-x.val:0; return x; }
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
	[[nodiscard]] modular constexpr pow(int p) const {
		modular a=*this;
		modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	[[nodiscard]] modular constexpr inv() const {
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

#define ARITHBINARYOP(OP) [[nodiscard]] friend modular constexpr operator OP(modular a, modular b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP
};

template<int... MODs> struct multimod : std::tuple<modular<MODs>...>{
	using super=std::tuple<modular<MODs>...>;
	multimod(int x):super( modular<MODs>(x)... ){}

#define CAT(x,y) x##y
#define CAT1(x,y) CAT(x,y)

#define ARITHBINARYOP_IMPL(OP,UNIQNAME) \
 \
	template<std::size_t... Is> \
	auto constexpr UNIQNAME(multimod x,std::index_sequence<Is...>){ \
		std::initializer_list {( \
				(std::get<Is>(*this) OP##= std::get<Is>(x)), \
				0)...}; \
	} \
	multimod constexpr& operator OP##=(multimod x){ \
		UNIQNAME(x,std::make_index_sequence<sizeof...(MODs)>()); \
		return *this; \
	} \
	[[nodiscard]] friend multimod constexpr operator OP(multimod a, multimod b) { return a OP##= b; }

#define ARITHBINARYOP(OP) ARITHBINARYOP_IMPL(OP,CAT1(_impl_,__COUNTER__))
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP
#undef ARITHBINARYOP_IMPL

#undef CAT
#undef CAT1

};

using Hash=multimod<1000000007, 1000000009>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::string string; 
	string.reserve(number);
	std::cin>>string;
	assert(string.size()==(unsigned) number);
	for(auto & ch: string) ch-='0';

	std::vector<Hash>hash(number,0);
	std::vector<int> countZeroAfter (number);
	{
		int cur=0;
		for(int index=number; index--;)
countZeroAfter[index]=cur+=(string[index]==0);
	}
	{
Hash cur=0;
int count=0; // number of ones int the currently block
for(int index=0; index<number;++index){
if(string[index]==0){
hash[index]=cur=cur*2+(count&1);
count=0;
}else{
++count;
}
}
}


	std::vector<Hash> pow(number+1, 1);
for(int it=1; it<(int)pow.size();++it)
pow[it]=pow[it-1]*2;

	std::vector<int> next(number), previous(number+1);
			{
				int curNext=number;
				for(int index=number; index--;){
if(string[index]==0) curNext=index;
next[index]=curNext;
				}
			}
			{
int curPrevious=-1;
for(int index=0;index<=number;++index) {
previous[index]=curPrevious;
if(string[index]==0)
curPrevious=index;
}
}


	int numQuery; std::cin>>numQuery;
	for(int _=0;_<numQuery;++_) {
		int left1, left2, len; std::cin>>left1>>left2>>len;
		--left1;
		--left2;

		auto const get=[&](int left){
auto  const firstOne=
next [left]-left
;
if(firstOne>=len)
return std::make_tuple(len&1, -1, -1, Hash{0});
auto lastOne=left+len-previous[left+len]-1;

auto const newLeft=left+firstOne;
auto const newRight=left+len-lastOne;
assert(string[left+firstOne]==0);
assert(string[newLeft ]==0);
assert(string[newRight-1]==0);
assert(lastOne<len);

return std::make_tuple(firstOne&1, lastOne&1,
countZeroAfter[newLeft]-countZeroAfter[newRight-1],
hash[newRight-1]-hash[newLeft]*
pow[
countZeroAfter[newLeft]-countZeroAfter[newRight-1]]
	);
		};


		std::cout<<(
get(left1)==get(left2)
			? "Yes\n": "No\n"
			);
	}
}