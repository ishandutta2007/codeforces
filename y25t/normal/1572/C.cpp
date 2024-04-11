#include<bits/stdc++.h>
#define N 3005

int T;

int n,a[N];

int lst[N],pre[N],nxt[N];

int f[N][N],g[N][N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			lst[i]=0;
		for(int i=1;i<=n;i++){
			pre[i]=lst[a[i]];
			lst[a[i]]=i;
		}
		for(int i=1;i<=n;i++)
			lst[i]=n+1;
		for(int i=n;i;i--){
			nxt[i]=lst[a[i]];
			lst[a[i]]=i;
		}
		for(int len=2;len<=n;len++)
			for(int l=1,r=len;r<=n;l++,r++){
				f[l][r]=f[l+1][r]+1;
				for(int i=nxt[l];i<=r;i=nxt[i])
					f[l][r]=std::min(f[l][r],f[l][i-1]+f[i][r]);
				g[l][r]=g[l][r-1]+1;
				for(int i=pre[r];i>=l;i=pre[i])
					g[l][r]=std::min(g[l][r],g[i+1][r]+g[l][i]);
			}
		printf("%d\n",std::min(f[1][n],g[1][n]));
	}
}