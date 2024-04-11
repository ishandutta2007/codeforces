//CF 932D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 444444;
const int M = 22;
const LL INF = 1e18;
int q,n=1,f[N][M],ff[N][M];
LL g[N][M],ss[N][M];
int main()
{
	int i,j;
	LL x,y,ans=0;
	for(j=0;j<=20;j=j+1)
		g[0][j]=INF,ss[0][j]=INF;
	for(j=1;j<=20;j=j+1)
		g[1][j]=INF,ss[1][j]=INF;
	scanf("%d",&q);
	while(q--){
		scanf("%d%lld%lld",&i,&x,&y);
		x^=ans,y^=ans;
		if(i==1){
			n++;
			f[n][0]=x;
			g[n][0]=y;
			for(j=1;j<=20;j=j+1){
				x=f[n][j-1];
				f[n][j]=f[x][j-1];
				g[n][j]=min(INF,max(g[n][j-1],g[x][j-1]));
			}
			x=f[n][0];
			for(j=20;j>=0;j=j-1){
				if(g[x][j]<y)
					x=f[x][j];
			}
			ff[n][0]=x;
			ss[n][0]=y;
			for(j=1;j<=20;j=j+1){
				x=ff[n][j-1];
				ff[n][j]=ff[x][j-1];
				ss[n][j]=min(INF,ss[n][j-1]+ss[x][j-1]);
			}
		}
		else{
			ans=0;
			for(j=20;j>=0;j=j-1){
				if(x&&ss[x][j]<=y){
					ans+=1<<j;
					y-=ss[x][j];
					x=ff[x][j];
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}