#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

int const MOD=1000000007;
struct modular {
	int val;
	explicit constexpr operator int() const { return val; }
	constexpr modular():val(){}
#if MODULAR_LESS_EFFICIENT_BUT_EASIER_TO_CODE
	constexpr modular(int64_t v):val(int(v%MOD)){
		if(val<0)val+=MOD;
	}
#else
	constexpr modular(int v):val(v){
		assert(0<=v and v<MOD);
	}
#endif

#define COMPAREOP(OP) bool constexpr operator OP(modular b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	modular operator-() const { return modular(val ? MOD-val : 0); }
	modular constexpr& operator+=(modular m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	modular constexpr& operator-=(modular m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	modular constexpr& operator*=(modular m) { val = int((int64_t)val*m.val%MOD); return *this; }
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
	int n;std::cin>>n;
	std::vector<int> p(n);
	int maxp=0;
	for(int& pi:p){
		std::cin>>pi;
		maxp=std::max(maxp,pi);
	}

	std::vector<int> cnt(maxp+1);
	for(int pi:p)++cnt[pi];

	std::vector<int> minf(std::max(10,maxp+1));
	for(int p=2;p<(int)minf.size();++p)if(minf[p]==0){
		minf[p]=p;
		for(int64_t j=p*(int64_t)p;j<(int64_t)minf.size();j+=p)
			if(minf[j]==0)
				minf[j]=p;
	}

	bool add=std::any_of(begin(cnt),end(cnt),[](int x){return x>=3;});
	// let some ai=0, then out will be incremented by 1 (can be done at most once)
	// it should always be done when there's some prime appears more than 2 times

	struct item{
		int val,nequal; // could have used char or short
	};
	std::vector<item> out_exp(maxp+1);
	auto const upd=[&](int p,int exp){
		if(exp==out_exp[p].val)
			++out_exp[p].nequal;
		else if(exp>out_exp[p].val)
			out_exp[p]={exp,1};
	};

	auto const check=[&](int p,int exp){
		return out_exp[p].val>exp or (out_exp[p].val==exp and out_exp[p].nequal>=2);
	};

	for(auto p=(int)cnt.size();p--;){
		if(cnt[p]>=1){
			if(out_exp[p].val>0){
				int x=p-1;
				while(x>1){
					int q=minf[x];
					int exp=0;
					do{ ++exp;x/=q; } while(x%q==0);
					upd(q,exp);
				}
			}else{
				upd(p,1);
			}
		}

		if(cnt[p]>=2){
			int x=p-1;
			while(x>1){
				int q=minf[x];
				int exp=0;
				do{ ++exp;x/=q; } while(x%q==0);
				upd(q,exp);
			}
		}
	}


	if(not add){ // check if it's possible to remove any number and keep the value unchanged
		for(int p=2;p<(int)cnt.size();++p)if(cnt[p]>=1){
			if(check(p,1)){
				add=true;
				break;
			}
		}

		if(not add)
		for(int p=2;p<(int)cnt.size();++p)if(cnt[p]>=2){
			int x=p-1;
			while(x>1){
				int q=minf[x];
				int exp=0;
				do{ ++exp;x/=q; } while(x%q==0);
				if(not check(q,exp))goto nextp;
			}

			add=true;
			break;
		
nextp:;
		}
	}


	modular out=1;
	for(int p=2;p<(int)out_exp.size();++p)if(out_exp[p].val){
		assert(minf[p]==p);
		out*=modular(p).pow(out_exp[p].val);
	}

	if(add)out+=1;
	std::cout<<(int)out<<'\n';
}