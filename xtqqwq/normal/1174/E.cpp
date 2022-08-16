#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n;
ll d[1000005],f[1000005],fac[1000005],inv[1000005];

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint();
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%cys;
	for(int i=1;i<=n;i++) inv[i]=qpow(fac[i],cys-2);
	for(int i=n;i>=1;i--){
		if(2*i>n) d[i]=f[i]=1;
		for(int j=i+i;j<=n;j+=i){
			if(d[j]+1>d[i]) d[i]=d[j]+1,f[i]=0;
			if(d[j]+1==d[i]) f[i]=(f[i]+f[j]*fac[n/i-n/j]%cys*fac[n-n/j-1]%cys*inv[n/i-n/j-1]%cys*inv[n-n/i]%cys)%cys;
		}
	}
	cout<<f[1]<<endl;
	return 0;
}