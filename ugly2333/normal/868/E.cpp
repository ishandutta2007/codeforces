//CF868E
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
const int N = 55;
const int inf = 1e9;
void cmin(int&x,int y){
	if(x>y)
		x=y;
}
void cmax(int&x,int y){
	if(x<y)
		x=y;
}
int n,s,m,a[N][N],b[N],c[N],f[N][N][N][N];
void dfs(int u,int fa){
	int x;
	for(x=1;x<=n;x=x+1){
		if(a[u][x]&&x!=fa){
			dfs(x,u);
			b[u]+=b[x];
		}
	}
}
int w,t[1111];
void clr(){
	int i;
	for(i=1;i<=w;i=i+1)
		t[i]=0;
}
void ins(int x){
	int i,j;
	for(i=1;i<=w;i=i+1)
		if(x>t[i])
			break;
	if(i>w)
		return;
	for(j=w;j>i;j=j-1)
		t[j]=t[j-1];
	t[i]=x;
}
int solve(int x,int y,int i,int j){
	if(!i&&!j)
		return 0;
	if(f[x][y][i][j])
		return f[x][y][i][j];
	if(c[y]==1){
		f[x][y][i][j]=a[x][y]+solve(y,x,j,0);
		return f[x][y][i][j];
	}
	int z,k;
	for(z=1;z<=n;z=z+1){
		if(a[y][z]&&z!=x){
			for(k=1;k<=i;k=k+1)
				solve(y,z,k,i+j-k);
		}
	}
	clr();
	for(z=1;z<=n;z=z+1){
		if(a[y][z]&&z!=x){
			for(k=1;k<=i;k=k+1)
				ins(f[y][z][k][i+j-k]);
			/*for(k=1;k<i;k=k+1)
				if(f[y][z][k][i+j-k]<f[y][z][k+1][i+j-k-1])
					exit(233);*/
		}
	}
	f[x][y][i][j]=t[i]+a[x][y];
	return f[x][y][i][j];
}
int main()
{
	int i,x,y,z,ans;
	cin>>n;
	for(i=1;i<n;i=i+1){
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
		c[x]++,c[y]++;
	}
	cin>>s>>m;
	for(i=1;i<=m;i=i+1){
		cin>>x;
		b[x]++;
	}
	dfs(s,0);
	w=100;
	ans=inf;
	for(i=1;i<=n;i=i+1)
		if(a[s][i])
			cmin(ans,solve(s,i,b[i],m-b[i]));
	cout<<ans;
	return 0;
}