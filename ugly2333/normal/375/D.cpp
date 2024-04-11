//CF 375D
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
const int N = 111111;
int n,m,a[N],t[N],f[N];
int tt=1,tin[N],tout[N],p[N];
vector<int> v1[N];
int ans[N],h[N],cnt[N];
vector<pair<int,int> > v2[N],q[N];
int s[N];
void inc(int x){
	cnt[x]++;
	s[cnt[x]]++;
}
void dfs1(int u,int fa){
	int i,sz,x;
	f[u]=fa;
	t[u]=1;
	sz=v1[u].size();
	for(i=0;i<sz;i=i+1){
		x=v1[u][i];
		if(x!=fa){
			dfs1(x,u);
			t[u]+=t[x];
			v2[u].push_back(make_pair(-t[x],x));
		}
	}
	sort(v2[u].begin(),v2[u].end());
}
void dfs2(int u){
	int i,sz,x;
	tin[u]=tt;
	sz=v2[u].size();
	for(i=0;i<sz;i=i+1)
		dfs2(v2[u][i].second);
	tout[u]=tt;
	p[tt++]=u;
}
int main()
{
	int i,j,k,x,y,sz,ty,cl,cr;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v1[x].push_back(y);
		v1[y].push_back(x);
	}
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		q[x].push_back(make_pair(y,i));
	}
	dfs1(1,0);
	dfs2(1);
	h[0]=1;
	for(i=1;i<=n;i=i+1){
		j=p[i];
		if(h[j])
			continue;
		y=j;
		k=0;
		while(y&&!h[y]){
			h[y]=1;
			k=y;
			y=f[y];
		}
		ty=t[k];
		h[y]=1;
		cl=tin[j];
		cr=cl-1;
		x=j;
		while(x!=y){
			while(cl>tin[x]){
				cl--;
				inc(a[p[cl]]);
			}
			while(cr<tout[x]){
				cr++;
				inc(a[p[cr]]);
			}
			sz=q[x].size();
			for(k=0;k<sz;k=k+1)
				ans[q[x][k].second]+=s[q[x][k].first];
			x=f[x];
		}
		for(k=cl;k<=cr;k=k+1)
			cnt[a[p[k]]]=0;
		for(k=0;k<=ty+10;k=k+1)
			s[k]=0;
	}
	for(i=1;i<=m;i=i+1)
		cout<<ans[i]<<endl;
	return 0;
}