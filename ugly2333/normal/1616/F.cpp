//CF1616E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 66;
const int M = 333;
const int W = 11111;
int n,m,w,a[N][N],b[M],f[W][M],e[W],g[M],h[M];
int main()
{
	int T,i,j,k,l,x,y,z;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				a[i][j]=-1;
		memset(f,0,sizeof(f));
		w=0;
		for(i=0;i<m;i++){
			scanf("%d%d%d",&x,&y,&z);
			a[x][y]=i,a[y][x]=i;
			if(z!=-1){
				w++;
				/*if(z==1)
					f[w][0]=1;
				if(z==2)
					f[w][1]=1;
				f[w][i*2]=1;*/
				f[w][m]=z%3;
				f[w][i]=1;
			}
		}
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				for(k=j+1;k<=n;k++){
					if(a[i][j]>=0&&a[j][k]>=0&&a[k][i]>=0){
						w++;
						//f[w][i*2]=1,f[w][j*2]=1,f[w][k*2]=1;
						f[w][a[i][j]]=1,f[w][a[j][k]]=1,f[w][a[k][i]]=1;
					}
				}
		for(i=1;i<=w;i++)
			e[i]=-1;
		for(i=0;i<m;i++){
			k=0;
			for(j=1;j<=w;j++)
				if(e[j]==-1&&f[j][i])
					k=j;
			if(!k){
				continue;
			}
			e[k]=i;
			if(f[k][i]==1){
				for(l=0;l<=m;l++)
					g[l]=f[k][l],h[l]=(3-g[l])%3;
			}
			else{
				for(l=0;l<=m;l++)
					h[l]=f[k][l],g[l]=(3-h[l])%3,f[k][l]=g[l];
			}
			for(j=1;j<=w;j++)
				if(k!=j&&f[j][i]){
					if(f[j][i]==1){
						for(l=i;l<=m;l++)
							f[j][l]=(f[j][l]+h[l])%3;
					}
					else{
						for(l=i;l<=m;l++)
							f[j][l]=(f[j][l]+g[l])%3;
					}
				}
		}
		x=0;
		for(i=1;i<=w;i++){
			/*for(j=0;j<=m;j++)
				cout<<f[i][j]<<' ';
			cout<<endl;*/
			if(e[i]==-1&&f[i][m]){
				x=1;
			}
		}
		if(x){
			printf("-1\n");
		}
		else{
			memset(b,0,sizeof(b));
			for(i=1;i<=w;i++)
				if(e[i]>=0)
					b[e[i]]=f[i][m];
			for(i=0;i<m;i++)
				printf("%d ",b[i]+(b[i]==0)*3);
			printf("\n");
		}
	}
	return 0;
}