//CF1707D
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
const int N = 2222;
int p;
void ad(int &x,int y){
	x+=y;
	if(x>=p)
		x-=p;
}
int mul(int x,int y){
	return (LL)x*y%p;
}
int n,f[N][N],g[N][N],s[N][N],l[N][N],r[N][N],t[N];
vector<int> v[N];
void dfs(int u,int fa){
	int i,j,x,m;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x!=fa)
			dfs(x,u);
	}
	m=0;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x!=fa){
			m++;
			for(j=0;j<=n;j++)
				g[m][j]=f[x][j],s[m][j]=g[m][j];
			for(j=1;j<=n;j++)
				ad(s[m][j],s[m][j-1]);
			for(j=0;j<=n;j++)
				l[m][j]=s[m][j],r[m][j]=s[m][j];
		}
	}
	if(m==0){
		for(j=1;j<=n;j++)
			f[u][j]=1;
		return;
	}
	for(j=0;j<=n;j++)
		l[0][j]=1,r[m+1][j]=1;
	for(i=1;i<=m;i++)
		for(j=0;j<=n;j++)
			l[i][j]=mul(l[i][j],l[i-1][j]);
	for(i=m;i>=1;i--)
		for(j=0;j<=n;j++)
			r[i][j]=mul(r[i][j],r[i+1][j]);
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			x=mul(l[i-1][j],r[i+1][j-1]);
			x=mul(x,g[i][j]);
			ad(f[u][j],x);
		}
	}
	for(j=1;j<=n;j++)
		ad(f[u][j],f[u][j-1]);
	if(u==1)
		return;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++)
			t[j]=mul(l[i-1][j],r[i+1][j]);
		for(j=1;j<=n;j++)
			ad(t[j],t[j-1]);
		for(j=1;j<=n;j++)
			ad(f[u][j],mul(t[j-1],g[i][j]));
	}
}
int c[N][N];
int main()
{
	int i,j,x,y;
	scanf("%d%d",&n,&p);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	for(i=0;i<=n;i++){
		c[i][0]=1;
		for(j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
	}
	/*for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			cout<<f[i][j]<<' ';
		cout<<endl;
	}*/
	for(i=1;i<n;i++){
		for(j=1;j<i;j++)
			ad(f[1][i],p-mul(f[1][j],c[i][j]));
		printf("%d ",f[1][i]);
	}
	return 0;
}