#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n,k;
ll a[1000005],f[1000005],g[1000005];

ll power(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void solve(){
	ll x=1,ans=0; f[0]=g[0]=1;
	for(int i=1;i<=k+2;i++) x=x*(n-i)%cys,f[i]=f[i-1]*i%cys,g[i]=(-g[i-1]*i%cys+cys)%cys;
	for(int i=1;i<=k+2;i++) ans=(ans+a[i]*x%cys*power(n-i,cys-2)%cys*power(f[i-1],cys-2)%cys*power(g[k-i+2],cys-2)%cys)%cys;
	printf("%lld\n",ans);
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=k+2;i++) a[i]=(a[i-1]+power(i,k))%cys;
	if(n<=k+2) printf("%lld\n",a[n]);
	else solve();
	return 0;
}