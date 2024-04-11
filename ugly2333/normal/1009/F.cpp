//CF1009F
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
const int N = 1e6+16;
int n,p[N],s[N];
vector<int> v[N],a[N],b[N];
void mrg(int x,int y){
	int px=p[x],py=p[y],sx=a[px].size(),sy=a[py].size(),i,j;
	if(sx<sy){
		mrg(y,x);
		return;
	}
	for(i=sx-1,j=sy-1;j>=0;i--,j--)
		a[px][i]+=a[py][j];
	for(i++;i<sx;i++){
		if(!i||a[px][i]>=a[px][b[px][i-1]])
			b[px][i]=i;
		else
			b[px][i]=b[px][i-1];
	}
	p[y]=p[x];
}
void dfs(int u,int fa){
	int i=v[u].size(),x;
	while(i--){
		x=v[u][i];
		if(x==fa)
			continue;
		dfs(x,u);
		mrg(u,x);
	}
	x=p[u];
	if(!a[x].size())
		b[x].push_back(0);
	else{
		i=*b[x].rbegin();
		if(a[x][i]<=1)
			b[x].push_back(a[x].size());
		else
			b[x].push_back(i);
	}
	a[x].push_back(1);
	s[u]=b[x].size()-1-*b[x].rbegin();
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i=i+1)
		p[i]=i;
	dfs(1,0);
	for(i=1;i<=n;i=i+1)
		printf("%d\n",s[i]);
	return 0;
}