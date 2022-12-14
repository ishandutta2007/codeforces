// :(
// aho-corasick tree is overkill.
// it's possible to solve it int O(n) memory as well.
// [I didn't read the editorial or see other submissions' time/memory usage]
//
//
// ======
//
// Actually memory is n*26 and time is n**2*26. A bit too large.

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

template<class T>
struct Modular_ {
#define MOD (T{}())

	int val;
	explicit constexpr operator int() const { return val; }
	constexpr Modular_():val(){}
#if 1 // slightly less efficient to construct, easier to implement
	constexpr Modular_(auto v):val(int(v%MOD)){ if(val<0)val+=MOD; }
#else
	constexpr Modular_(int v):val(v){
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
		val = int((int64_t)val*m.val%MOD);
		return *this;
	}
	[[nodiscard]] Modular_ constexpr pow(int p) const {
		Modular_ a=*this;
		Modular_ ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	[[nodiscard]] Modular_ constexpr inv() const {
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
	Modular_ constexpr& operator/=(Modular_ m) { return (*this) *= m.inv(); }

#define ARITHBINARYOP(OP) [[nodiscard]] friend Modular_ constexpr operator OP(Modular_ a, Modular_ b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP

#undef MOD
};

template<int x> struct IntConstGetter{ int operator()() const{ return x; } };
template<int MOD> using Modular=Modular_<IntConstGetter<MOD>>;

using modular=Modular<998244353>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s, t; std::cin>>s>>t;

	for(auto & it: s) it-='a';
	for(auto & it: t) it-='a';

	modular result=0;

	//std::vector<int> cur(t.size());
	//std::iota(begin(cur),end(cur), 1);
	//// cur[left] = min left1>left such that t[left:left+len] == t[left1:left1+len]
	//// (for all valid indices)

	std::vector<std::array<int, 26>> prepend(t.size()+1), append(t.size()+1);
	// prepend[left][ch] = first occurrence of ch+s[left:left+len] >= left-1
	// append: similar but append, >= left

	{
		std::array<int, 26> next; next.fill((int)t.size());
		append.back()=next;
		for(int index=(int)t.size(); index--;){
			next[t[index]]=index;
			append[index]=next;
			prepend[index+1]=next;
		}
		prepend[0]=prepend[1];
	}

	//std::vector<char> canon(t.size()+1); // canon[left] = t[left:left+len] is the first occurrence?
	//canon[0]=true;

	std::vector<modular> count(t.size()+1);
	// count[left]=number of ways to get minimum matching at [left:left+len]
	count[0]=1;

	int len=0;
	for(auto const ch: s){
		// update count for len+1
		std::vector<modular> nextCount(count.size());
		for(auto index=(int)count.size(); index--;) if(count[index]!=0){
			assert(prepend[index][ch]>=std::max(index-1, 0));
			assert(append[index][ch]>=index);

			nextCount[prepend[index][ch]]+=count[index];
			nextCount[append[index][ch]]+=count[index];
		}
		count=std::move(nextCount);

		// update prepend and append table, and increment len
		std::vector<std::array<int, 26>> newPrepend(t.size()+1), newAppend(t.size()+1);
		newPrepend.back().fill((int)t.size());
		newPrepend.back()[t.back()]=(int)t.size()-1;
		newAppend.back().fill((int)t.size());

		//std::vector<char> newCanon(t.size()+1);
		for(int index=(int)t.size(); index--;)
		//if(canon[index])
		{
			for(int ch=0;ch<26;++ch) {
				auto& it=newAppend[index][ch];
				//newCanon[it]=true;

				if(index+len+1>=(int)t.size() or t[index+len+1]==ch){
					it=index;
					continue;
				}
				it=append[index+1][ch];
				if(index+1==(int)t.size()){
					assert(it==(int)t.size());
					assert(newPrepend[it][t[index]]==(int)t.size());
					// otherwise it=index would have been executed

					continue;
				}else{
					assert(it>index+1);
					it=newPrepend[it][t[index]];
				}
			}
			for(int ch=0;ch<26;++ch) {
				auto& it=newPrepend[index][ch];
				//newCanon[it]=true;

				if(index!=0 and t[index-1]==ch){
					it=index-1;
					continue;
				}
				it=prepend[index][ch];
				assert(it>index-1);
				if(index+len<(int)t.size())
					it=newAppend[it][t[index+len]];
			}
		}
		prepend=std::move(newPrepend);
		append=std::move(newAppend);
		//canon=newCanon;
		++len;

		if(len>=(int)t.size()) result+=count[0];
	}

	std::cout<<(int)result<<'\n';
}