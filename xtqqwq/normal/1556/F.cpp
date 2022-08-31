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

const int cys=1000000007;
int n;
int a[20];
ll val[20][70000],d[70000];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint();
	for(int i=0;i<n;i++) a[i]=readint();
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<n);j++){
			if((j>>i)&1) continue;
			val[i][j]=1;
			for(int k=0;k<n;k++)
				if((j>>k)&1)
					val[i][j]=val[i][j]*a[i]%cys*qpow(a[i]+a[k],cys-2)%cys;
		}
	}
	for(int i=1;i<(1<<n);i++){
		d[i]=1;
		for(int j=i;j;j=(j-1)&i){
			if(j==i) continue;
			ll pro=d[j];
			for(int k=0;k<n;k++)
				if((j>>k)&1)
					pro=pro*val[k][i^j]%cys;
			d[i]=mod(d[i]+cys-pro);
		}
	}
	ll ans=0;
	for(int i=1;i<(1<<n);i++){
		int cnt=0;
		for(int j=0;j<n;j++) cnt+=(i>>j)&1;
		ll pro=d[i];
		for(int j=0;j<n;j++) if((i>>j)&1) pro=pro*val[j][((1<<n)-1)^i]%cys;
		ans=(ans+pro*cnt)%cys;
	}
	printf("%lld\n",ans);
	return 0;
}