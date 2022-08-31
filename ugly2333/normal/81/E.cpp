//
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
struct node{
	int x,y,z;
}f[N],g[N],dp[N],ans,tmp,q;
node operator+(node a,node b){
	node c;
	c.x=a.x+b.x;
	c.y=a.y+b.y;
	c.z=0;
	return c;
}
node operator-(node a,node b){
	node c;
	c.x=a.x-b.x;
	c.y=a.y-b.y;
	c.z=0;
	return c;
}
bool operator<(node a,node b){
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}
void prt(node a){
	cout<<a.x<<' '<<a.y<<' '<<a.z<<endl;
}
int n,a[N],b[N],vis[N],t[N],p[N];
vector<int> v[N];
void dfs(int u,int fa){
	vis[u]=1;
	int i,w,sz=v[u].size();
	node ff=q,gg=q;
	f[u]=q,g[u]=q;
	for(i=0;i<sz;i=i+1){
		w=v[u][i];
		if(w!=fa){
			//cout<<u<<w<<endl;
			dfs(w,fa);
			ff=ff+f[w];
		}
	}
	g[u]=ff;
	f[u]=g[u];
	for(i=0;i<sz;i=i+1){
		w=v[u][i];
		if(w!=fa){
			gg=ff-f[w]+g[w];
			gg.x++,gg.y+=b[u]^b[w],gg.z=w;
			if(f[u]<gg)
				f[u]=gg;
		}
	}
	//cout<<u<<endl;
	//prt(ff),prt(f[u]),prt(g[u]);
}
vector<pair<int,int> > h;
void getans(int u,int fa,bool isf){
	int i,w,sz=v[u].size();
	for(i=0;i<sz;i=i+1){
		w=v[u][i];
		if(w!=fa){
			if(isf&&w==f[u].z){
				h.push_back(make_pair(u,w));
				getans(w,fa,0);
			}
			else
				getans(w,fa,1);
		}
	}
}
int main()
{
	q.x=0,q.y=0,q.z=0;
	ans=q;
	int i,j,k,w;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",a+i,b+i);
		v[a[i]].push_back(i);
		b[i]--;
	}
	for(i=1;i<=n;i=i+1){
		if(vis[i])
			continue;
		j=0;
		w=i;
		while(!p[w]){
			t[j++]=w;
			p[w]=1;
			w=a[w];
		}
		reverse(t,t+j);
		for(k=0;t[k]!=w;k=k+1);
		dfs(t[0],t[k]);
		tmp=g[t[0]];
		dfs(t[0],t[0]);
		tmp=tmp+g[t[k]];
		tmp.x++,tmp.y+=b[t[0]]^b[t[k]];
		//prt(tmp),prt(f[t[0]]);
		if(f[t[0]]<tmp){
			ans=ans+tmp;
			getans(t[k],t[0],0);
			dfs(t[0],t[k]);
			getans(t[0],t[k],0);
			h.push_back(make_pair(t[0],t[k]));
		}
		else{
			ans=ans+f[t[0]];
			getans(t[0],t[0],1);
		}
		
	}
	cout<<ans.x<<' '<<ans.y<<endl;
	j=h.size();
	while(j--){
		cout<<h[j].first<<' '<<h[j].second<<endl;
	}
	return 0;
}
/*
5
5 2
3 2
5 1
2 1
4 2

6
5 2
3 2
5 1
2 1
4 2
3 1

8
2 2
3 2
5 1
3 1
6 1
5 1
8 2
7 1

*/