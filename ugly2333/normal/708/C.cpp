//CF 708C
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
const int N = 444444;
int n,n2;
vector<int> v[N];
int f[N],t[N],t1[N],t2[N],g1[N],g2[N];
void dfs1(int u,int fa){
	int i,s,x;
	s=v[u].size();
	f[u]=fa;
	t[u]=1;
	t1[u]=0;
	g1[u]=0;
	for(i=0;i<s;i=i+1){
		x=v[u][i];
		if(x!=fa){
			dfs1(x,u);
			t[u]+=t[x];
			t1[u]=max(t1[u],t[x]);
			g1[u]=max(g1[u],g1[x]);
			if(t[x]<n2)
				g1[u]=max(g1[u],t[x]);
		}
	}
	if(t[u]<n2)
		g1[u]=max(g1[u],t[u]);
	t2[u]=n-t[u];
}
void dfs2(int u,int fa){
	int i,s,x,mx,mx2;
	s=v[u].size();
	if(t2[u]<n2&&g2[u]<t2[u])
		g2[u]=t2[u];
	mx=g2[u],mx2=0;
	for(i=0;i<s;i=i+1){
		x=v[u][i];
		if(x!=fa){
			if(g1[x]>mx)
				mx2=mx,mx=g1[x];
			else{
				if(g1[x]>mx2)
					mx2=g1[x];
			}
		}
	}
	for(i=0;i<s;i=i+1){
		x=v[u][i];
		if(x!=fa){
			if(g1[x]!=mx)
				g2[x]=mx;
			else
				g2[x]=mx2;
			dfs2(x,u);
		}
	}
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	n2=n/2+1;
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,0);
	g2[1]=0;
	dfs2(1,0);
	for(i=1;i<=n;i=i+1){
		//cout<<t1[i]<<' '<<g1[i]<<' '<<t2[i]<<' '<<g2[i]<<endl;
		if(t1[i]-g1[i]>=n2||t2[i]-g2[i]>=n2)
			cout<<0<<' ';
		else
			cout<<1<<' ';
	}
	return 0;
}