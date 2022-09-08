//CF1726A
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
const int N = 222222;
int n,m,a[N],f[N];
vector<int> v[N],h[N],p,q;
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
int dfs(int u,int fa,int t){
	int i,x;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x==fa)
			continue;
		if(x==t)
			return h[u][i];
		x=dfs(x,u,t);
		if(x)
			return x;
	}
	return 0;
}
int main()
{
	int T,i,x,y,xx,yy;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			f[i]=i,v[i].clear(),h[i].clear();
		p.clear(),q.clear();
		for(i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			if(fnd(x)!=fnd(y)){
				f[fnd(x)]=fnd(y);
				v[x].push_back(y);
				v[y].push_back(x);
				h[x].push_back(i);
				h[y].push_back(i);
			}
			else{
				p.push_back(x);
				p.push_back(y);
				q.push_back(i);
				xx=x,yy=y;
			}
		}
		if(q.size()==3){
			sort(p.begin(),p.end());
			if(p[0]==p[1]&&p[2]==p[3]&&p[4]==p[5])
				q[2]=dfs(xx,0,yy);
		}
		for(i=1;i<=m;i++)
			a[i]=0;
		for(i=0;i<q.size();i++)
			a[q[i]]=1;
		for(i=1;i<=m;i++)
			printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}