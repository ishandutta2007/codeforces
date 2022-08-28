//CF 864F
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
const int N = 3033;
vector<int> v[N],r[N],b[N];
vector<pair<int,int> > Q[N][N];
int ans[444444],vis[N],a[N];
int d,p[N],rt;
void dfsr(int u){
	if(vis[u])
		return;
	int i,s;
	s=r[u].size();
	vis[u]=1;
	for(i=0;i<s;i=i+1)
		dfsr(r[u][i]);
}
void dfsb(int u){
	//cout<<u<<endl;
	int i,s,x,y;
	p[++d]=u;
	s=Q[u][rt].size();
	for(i=0;i<s;i=i+1){
		x=Q[u][rt][i].first;
		y=Q[u][rt][i].second;
		if(x>d)
			ans[y]=-1;
		else
			ans[y]=p[d+1-x];
	}
	s=b[u].size();
	for(i=0;i<s;i=i+1)
		dfsb(b[u][i]);
	--d;
}

int main()
{
	int n,m,q,i,j,k,s,x,y,z;
	cin>>n>>m>>q;
	for(i=1;i<=m;i=i+1){
		cin>>x>>y;
		v[x].push_back(y);
		r[y].push_back(x);
	}
	for(i=1;i<=q;i=i+1){
		scanf("%d%d%d",&x,&y,&z);//cin>>x>>y>>z;
		Q[x][y].push_back(make_pair(z,i));
		ans[i]=-1;
	}
	for(i=1;i<=n;i=i+1){
		rt=i;
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		dfsr(i);
		for(j=1;j<=n;j=j+1){
			b[j].clear();
			if(!vis[j])
				continue;
			s=v[j].size();
			for(k=0;k<s;k=k+1)
				if(vis[v[j][k]])
					if(!a[j]||a[j]>v[j][k])
						a[j]=v[j][k];
		}
		//cout<<i<<endl<<endl;
		for(j=1;j<=n;j=j+1)	
			if(j!=rt&&a[j])
				b[a[j]].push_back(j);
		memset(p,0,sizeof(p));
		d=0;
		dfsb(i);
	}
	for(i=1;i<=q;i=i+1)
		cout<<ans[i]<<endl;
	return 0;
}