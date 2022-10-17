#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n,k,T,ans;
int b[maxn],c[maxn],f[maxn],g[maxn*15];
int main(){
	for(int i=2;i<=1000;i++)
		f[i]=1e9;
	int mx=0;
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=i;j++)
			f[i+i/j]=min(f[i+i/j],f[i]+1);
		mx=max(mx,f[i]);
	}
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		k=min(k,15*n);
		for(int i=1;i<=n;i++)
			for(int j=k;j>=f[b[i]];j--)
				g[j]=max(g[j],g[j-f[b[i]]]+c[i]);
		printf("%d\n",g[k]);
		for(int i=0;i<=k;i++)
			g[i]=0;
	}
	return 0;
}