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

const int cys1=1019260817,cys2=1222827239;
int n,m;
ll a[500005],now1[500005],now2[500005],pw1[500005],pw2[500005];
map<pll,ll> k;

ll mod1(ll x){return x>=cys1?x-cys1:x;}
ll mod2(ll x){return x>=cys2?x-cys2:x;}
ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		pw1[0]=pw2[0]=1;
		for(int i=1;i<=n;i++) pw1[i]=mod1(pw1[i-1]<<1),pw2[i]=mod2(pw2[i-1]<<1);
		for(int i=1;i<=n;i++) a[i]=readint(),now1[i]=now2[i]=0;
		int x,y;
		for(int i=1;i<=m;i++){
			x=readint(); y=readint();
			now1[y]=mod1(now1[y]+pw1[x-1]);
			now2[y]=mod2(now2[y]+pw2[x-1]);
		}
		k.clear();
		for(int i=1;i<=n;i++) if(now1[i]>0||now2[i]>0) k[mp(now1[i],now2[i])]+=a[i];
		ll ans=0;
		for(auto x:k) ans=gcd(ans,x.se);
		printf("%lld\n",ans);
	}
	return 0;
}