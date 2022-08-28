//CF1637B
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
const int N = 111;
int n,a[N],b[N],f[N][N],g[N][N];
int main()
{
	int T,i,j,k,x;
	scanf("%d",&T);
	while(T--){
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(i=1;i<=n;i++){
			f[i][i-1]=0;
			memset(b,0,sizeof(b));
			for(j=i;j<=n;j++){
				if(a[j]<=n)
					b[a[j]]=1;
				for(x=f[i][j-1];b[x];x++)
				f[i][j]=x;
				g[i][j]=x+1;
			}
		}
		for(j=1;j<=n;j++)
			for(i=1;i<=j;i++)
				for(k=i;k<j;k++)
					g[i][j]=max(g[i][j],g[i][k]+g[k+1][j]);
		x=0;
		for(i=1;i<=n;i++)
			for(j=i;j<=n;j++)
				x+=g[i][j];
		printf("%d\n",x);
	}
	return 0;
}