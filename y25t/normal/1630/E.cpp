#include<bits/stdc++.h>
#define N 1000005
#define P 998244353

inline int fmo(int x){
	return x+((x>>31)&P);
}
inline int fp(int x,int k=P-2){
	int res=1;
	for(;k;k>>=1,x=1ll*x*x%P)
		if(k&1)
			res=1ll*res*x%P;
	return res;
}

int fac[N],inv[N],ifac[N];
inline void init(int x){
	fac[0]=1;
	for(int i=1;i<=x;i++)
		fac[i]=1ll*fac[i-1]*i%P;
	inv[1]=1;
	for(int i=2;i<=x;i++)
		inv[i]=fmo(-1ll*P/i*inv[P%i]%P);
	ifac[0]=1;
	for(int i=1;i<=x;i++)
		ifac[i]=1ll*ifac[i-1]*inv[i]%P;
}
inline int C(int x,int y){
	if(x<0||y<0||x<y)
		return 0;
	return 1ll*fac[x]*ifac[y]%P*ifac[x-y]%P;
}

int T;

int n,a[N];

std::vector<int> D;
int f[N],g[N];
inline void cal(int d){
	g[d]=fac[n/d];
	int t=1;
	for(auto i:D)
		t=1ll*t*ifac[i/d]%P;
	for(int i=0;i<(int)D.size();i++){
		int x=D[i]/d;
		int tmp=1ll*t*fac[x]%P;
		for(int j=1;j<=x;j++)
			f[d]=fmo(f[d]+1ll*fmo(fmo(1ll*fac[n/d-j]*tmp%P*ifac[x-j]%P
					-2ll*(n/d-1/j>=0&&x-j-1>=0?1ll*fac[n/d-1-j]*tmp%P*ifac[x-j-1]%P:0)%P)
					+(n/d-2-j>=0&&x-j-2>=0?1ll*tmp*fac[n/d-2-j]%P*ifac[x-j-2]%P:0)-P)*(n/d)%P-P);
		g[d]=1ll*g[d]*ifac[x]%P;
	}
}

int main(){
	init(1e6);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			a[i]=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			a[x]++;
		}
		int k=0;
		D.clear();
		for(int i=1;i<=n;i++)
			if(a[i]){
				k=std::__gcd(k,a[i]);
				D.push_back(a[i]);
			}
		if(D.size()==1){
			puts("1");
			continue;
		}
		for(int i=1;i<=n;i++)
			f[i]=g[i]=0;
		for(int i=1;i<=n;i++) if(n%i==0&&k%i==0)
			cal(i);
		int A=0,b=0;
		for(int i=0;i<n;i++){
			int d=n/std::__gcd(n,i);
			A=fmo(A+1ll*d*f[d]%P-P),b=fmo(b+g[d]-P);
		}
		printf("%lld\n",1ll*A*fp(b)%P);
	}
}