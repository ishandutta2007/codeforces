#include<bits/stdc++.h>
#define ll long long
#define P 998244353
#define N 100005

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
ll f[N],g[N];

std::map<ll,std::pair<int,int>> mp;

int main(){
	init(1e5);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			f[i]=f[i-1]+a[i];
		g[n+1]=0;
		for(int i=n;i;i--)
			g[i]=g[i+1]+a[i];
		mp.clear();
		int res=1;
		for(int i=1;i<n;i++)
			if(f[i]<g[i+1])
				mp[f[i]].first++;
			else if(f[i]>g[i+1])
				mp[g[i+1]].second++;
			else
				res=fmo(res+res-P);
		for(auto [i,j]:mp){
			auto [x,y]=j;
			int tmp=0;
			for(int k=0;k<=x&&k<=y;k++)
				tmp=fmo(tmp+1ll*C(x,k)*C(y,k)%P-P);
			res=1ll*res*tmp%P;
		}
		printf("%d\n",res);
	}
}