//CF 894E
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
const int N = 1e6+16;
const int W = 1e8+18;
int n,m,a[N],tt,vis[N],cl[N],ind[N];
int b[N],bb;
LL cnt[N],dp[N],sb[N];
vector<pair<int,int> > v[N],h[N];
vector<int> r[N];
queue<int> Q;
void dfsr(int u){
	int i,sz;
	vis[u]=1;
	sz=r[u].size();
	for(i=0;i<sz;i=i+1)
		if(!vis[r[u][i]])
			dfsr(r[u][i]);
	a[++tt]=u;
}
void dfsv(int u,int c){
	int i,sz;
	vis[u]=1;
	cl[u]=c;
	sz=v[u].size();
	for(i=0;i<sz;i=i+1)
		if(!vis[v[u][i].first])
			dfsv(v[u][i].first,c);
}
int main()
{
	int i,j,sz,x,y,z;
	LL ans;
	bb=0;
	while(b[bb]<=W){
		bb++;
		b[bb]=b[bb-1]+bb;
		sb[bb]=(LL)sb[bb-1]+b[bb];
	}
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back(make_pair(y,z));
		r[y].push_back(x);
	}
	for(i=1;i<=n;i=i+1)
		if(!vis[i])
			dfsr(i);
	x=0;
	memset(vis,0,sizeof(vis));
	for(i=n;i>=1;i=i-1){
		if(!vis[a[i]])
			dfsv(a[i],++x);
	}
	for(i=1;i<=n;i=i+1){
		sz=v[i].size();
		for(j=0;j<sz;j=j+1){
			y=v[i][j].first;
			if(cl[i]==cl[y]){
				z=upper_bound(b+1,b+bb,v[i][j].second)-b;
				cnt[cl[i]]+=(LL)v[i][j].second*z-sb[z-1];
			}
			else{
				h[cl[i]].push_back(make_pair(cl[y],v[i][j].second));
				ind[cl[y]]++;
			}
		}
	}
	for(i=1;i<=n;i=i+1)
		r[i].clear(),v[i].clear();
	for(i=1;i<=x;i=i+1)
		if(!ind[i])
			Q.push(i);
	scanf("%d",&z);
	z=cl[z];
	ans=0;
	memset(vis,0,sizeof(vis));
	while(!Q.empty()){
		i=Q.front();
		Q.pop();
		//cout<<i<<endl;
		if(i==z)
			vis[i]=1;
		if(vis[i])
			dp[i]+=cnt[i];
		ans=max(ans,dp[i]);
		sz=h[i].size();
		for(j=0;j<sz;j=j+1){
			y=h[i][j].first;
			ind[y]--;
			if(!ind[y])
				Q.push(y);
			if(vis[i])
				vis[y]=1,dp[y]=max(dp[y],dp[i]+h[i][j].second);
		}
	}
	cout<<ans<<endl;
	return 0;
}