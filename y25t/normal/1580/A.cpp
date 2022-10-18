#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 405

int T;

int n,m,a[N][N];
char str[N];

int s[N][N];

int h[N],f[N],g[N];

int main(){
//	freopen(".in","r",stdin);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",str+1);
			for(int j=1;j<=m;j++){
				a[i][j]=str[j]=='1';
				s[i][j]=s[i][j-1]+a[i][j];
			}
		}
		int ans=inf;
		for(int l=1;l<=m;l++)
			for(int r=l+3;r<=m;r++){
				for(int i=1;i<=n;i++){
					h[i]=h[i-1]+(!a[i][r])+(!a[i][l])+s[i][r-1]-s[i][l];
					int tmp=(r-l-1)-(s[i][r-1]-s[i][l]);
					f[i]=h[i-1]+tmp,g[i]=tmp-h[i];
				}
				int tmp=inf;
				for(int i=5;i<=n;i++){
					if(i>=5)
						tmp=std::min(tmp,g[i-4]);
					ans=std::min(ans,f[i]+tmp);
				}
			}
		printf("%d\n",ans);
	}
}