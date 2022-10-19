#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int n,lim,a[14],inv[14][14],f[1<<14],g[1<<14],res;
vector<int>v[1<<14];
int main(){
	scanf("%d",&n),lim=1<<n;
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)inv[i][j]=ksm(a[i]+a[j]);
	for(int i=0;i<lim;i++)for(int j=0;j<n;j++)if(i&(1<<j))v[i].push_back(j);
	for(int i=1;i<lim;i++){
		f[i]=1;
		for(int j=(i-1)&i;j;j=(j-1)&i){
			int k=(i^j);
			int t=f[k];
			for(auto x:v[j])for(auto y:v[k])t=1ll*a[x]*inv[x][y]%mod*t%mod;
			(f[i]+=mod-t)%=mod;
		}
//		printf("%d\n",f[i]);
	}
	g[lim-1]=1;
	for(int i=lim-1;i>=0;i--){
		for(int j=(i-1)&i;j;j=(j-1)&i){
			int k=(i^j);
			int t=1ll*g[i]*f[k]%mod;
			for(auto x:v[j])for(auto y:v[k])t=1ll*a[x]*inv[x][y]%mod*t%mod;
			(g[j]+=t)%=mod;
		}
	}
	for(int i=1;i<lim;i++)res=(1ll*__builtin_popcount(i)*f[i]%mod*g[i]+res)%mod;
	printf("%d\n",res);
	return 0;
}
/*
14
1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/