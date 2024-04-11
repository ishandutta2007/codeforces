#include<bits/stdc++.h>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec seocnd
#define P 998244353
#define N 200005

inline int fmo(int x){
	return x+((x>>31)&P);
}

int n,a[N],b[N],c[N];

int f[N],g[N],h[N],s[N];

int ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	ans=(a[n]+1)%P;
	for(int i=1;i<=n+1;i++){
		int j=std::upper_bound(a+1,a+n+1,b[i])-a;
		f[i]=i==j?i:f[j];
		g[i]=fmo(fmo(g[j]+h[j]-P)+fmo(b[i]%P-a[i]%P)-P);
		h[i]=fmo(fmo(s[i-1]-s[f[i]-1])-g[i]);
		s[i]=fmo(s[i-1]+h[i]-P);
		if(c[i])
			ans=fmo(ans+h[i]-P);
	}
	printf("%d\n",ans);
}