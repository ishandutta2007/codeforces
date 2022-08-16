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

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
ll a[200005],b[200005],cnt[1005],dif[1005];

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%m) if(p&1) ret=ret*x%m;
	return ret;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),b[i]=a[i]%m;
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=2;i<=n;i++) if(b[i]==b[i-1]) return printf("0\n"),0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++) dif[(a[i]-j+m)%m]+=cnt[j];
		cnt[a[i]%m]++;
	}
	ll ans=1;
	for(int i=0;i<m;i++) ans=ans*qpow(i,dif[i])%m;
	printf("%lld\n",ans);
	return 0;
}