#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define int long long
#define inf 1000000000000000000
using namespace std;
const int maxn=200005;
int n,m,T,ans,tot,k;
int X[maxn],f[maxn];
vector<int>v[maxn],w[maxn],p[maxn];
map< pair<int,int>,int >mp;
signed main(){
	scanf("%lld",&T);
	while(T--){
		mp.clear(),scanf("%lld%lld%lld",&n,&m,&k);
		mp[make_pair(1,1)]=1,mp[make_pair(n,m)]=2,tot=2,p[1].push_back(1),p[n].push_back(m);
		for(int i=1;i<=n;i++)
			scanf("%lld",&X[i]);
		for(int i=1,a,b,c,d,h;i<=k;i++){
			scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&h);
			if(mp[make_pair(a,b)]==0)
				mp[make_pair(a,b)]=++tot,p[a].push_back(b);
			if(mp[make_pair(c,d)]==0)
				mp[make_pair(c,d)]=++tot,p[c].push_back(d);
			int x=mp[make_pair(a,b)],y=mp[make_pair(c,d)];
			v[x].push_back(y),w[x].push_back(h);
		}
		for(int i=1;i<=tot;i++)
			f[i]=inf;
		f[1]=0;
		for(int i=1;i<=n;i++){
			if(p[i].size()==0)
				continue;
			sort(p[i].begin(),p[i].end());
			int now=inf;
			for(int j=0;j<p[i].size();j++){
				int x=p[i][j],u=mp[make_pair(i,x)];
				if(now!=inf)
					f[u]=min(f[u],x*X[i]+now);
				if(f[u]!=inf)
					now=min(now,f[u]-x*X[i]);
			}
			now=inf;
			for(int j=p[i].size()-1;j>=0;j--){
				int x=p[i][j],u=mp[make_pair(i,x)];
				if(now!=inf)
					f[u]=min(f[u],now-x*X[i]);
				if(f[u]!=inf){
					now=min(now,f[u]+x*X[i]);
					for(int k=0;k<v[u].size();k++)
						if(f[v[u][k]]>f[u]-w[u][k])
							f[v[u][k]]=f[u]-w[u][k];
				}
			}
		}
		if(f[2]==inf)
			puts("NO ESCAPE");
		else printf("%lld\n",f[2]);
		for(int i=1;i<=tot;i++)
			v[i].clear(),w[i].clear();
		for(int i=1;i<=n;i++)
			p[i].clear();
	}
	return 0;
}