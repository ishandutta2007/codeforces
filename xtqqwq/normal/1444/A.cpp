#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll x,y;

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x) if(p&1) ret=ret*x;
	return ret;
}

int main(){
	int T=readint();
	while(T--){
		x=readint(); y=readint();
		if(x%y!=0){
			printf("%lld\n",x);
			continue;
		}
		vector<pii> fac(0);
		for(int i=2;i*i<=y;i++){
			if(y%i==0){
				pii tmp=mp(i,0);
				while(y%i==0) tmp.se++,y/=i;
				fac.pb(tmp);
			}
		}
		if(y>1) fac.pb(mp(y,1));
		ll mina=1ll<<60;
		for(auto r:fac){
			int num=0;
			ll tmp=x;
			while(tmp%r.fi==0) num++,tmp/=r.fi;
			chkmin(mina,qpow(r.fi,num-r.se+1));
		}
		printf("%lld\n",x/mina);
	}
	return 0;
}