#include<bits/stdc++.h>
#define N 65

int m,a[N];

int f[N][N][N*N],g[N][N][N*N];

int n,b[N],c[N],e[N][N];

int main(){
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+m+1);
	f[0][0][0]=1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<N;j++) for(int k=N*N-1;k>=j*(j-1)/2;k--)
			for(int l=1;l<=j&&l*a[i]<=k;l++) if(f[i-1][j-l][k-l*a[i]])
				f[i][j][k]=1,g[i][j][k]=l;
	for(n=1;n<N;n++)
		if(f[m][n][n*(n-1)/2]){
			int t=n,s=n*(n-1)/2;
			for(int i=m;i;i--){
				int l=g[i][t][s];
				for(int j=1;j<=l;j++)
					b[t--]=a[i],s-=a[i];
			}
			break;
		}
	if(n==N)
		return puts("="),0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			e[i][j]=1,c[i]++;
	while(1){
		bool flg=0;
		for(int i=1;i<=n&&!flg;i++) if(c[i]<b[i])
			for(int j=i+1;j<=n&&!flg;j++) if(c[j]>b[j]){
				flg=1;
				for(int k=1;k<=n;k++) if(e[k][i]&&e[j][k]){
					std::swap(e[k][i],e[i][k]),c[i]++;
					std::swap(e[j][k],e[k][j]),c[j]--;
					break;
				}
			}
		if(!flg)
			break;
	}
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			putchar(e[i][j]+'0');
		puts("");
	}
}