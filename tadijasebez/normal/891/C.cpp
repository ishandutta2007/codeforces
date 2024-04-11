#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int N=500050;
int p[N],r[N];
int Find(int x)
{
	if(p[x]!=x) p[x]=Find(p[x]);
	return p[x];
}
void Union(int x, int y)
{
	x=Find(x);
	y=Find(y);
	if(r[x]<r[y]) p[x]=y;
	if(r[x]>r[y]) p[y]=x;
	if(r[x]==r[y]) r[x]++,p[y]=x;
}
int u[N],v[N],w[N],x[N];
vector<int> cnt[N],vals;
set<int> Set;
int main()
{
	int n,m,i,j,k,q;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%i %i %i",&u[i],&v[i],&w[i]);
		cnt[w[i]].push_back(i);
		vals.push_back(w[i]);
	}
	for(i=1;i<=n;i++) p[i]=i;
	sort(vals.begin(),vals.end());
	//vals.erase(unique(vals.begin(),vals.end()),vals.end());
	for(i=0;i<vals.size();i++)
	{
		int val=vals[i];
		if(i>0 && val==vals[i-1]) continue;
		for(j=0;j<cnt[val].size();j++)
		{
			int id=cnt[val][j];
			u[id]=Find(u[id]);
			v[id]=Find(v[id]);
		}
		for(j=0;j<cnt[val].size();j++)
		{
			int id=cnt[val][j];
			Union(u[id],v[id]);
		}
	}
	scanf("%i",&q);
	while(q--)
	{
		Set.clear();
		scanf("%i",&k);
		for(i=1;i<=k;i++)
		{
			scanf("%i",&x[i]);
			Set.insert(w[x[i]]);
			cnt[w[x[i]]].clear();
		}
		for(i=1;i<=k;i++) cnt[w[x[i]]].push_back(x[i]);
		bool ok=1;
		for(set<int>::iterator it=Set.begin();it!=Set.end();it++)
		{
			int val=*it;
			for(j=0;j<cnt[val].size();j++)
			{
				int id=cnt[val][j];
				p[u[id]]=u[id];
				r[u[id]]=0;
				p[v[id]]=v[id];
				r[v[id]]=0;
			}
			for(j=0;j<cnt[val].size();j++)
			{
				int id=cnt[val][j];
				if(Find(u[id])==Find(v[id])) ok=0;
				Union(u[id],v[id]);
			}
		}
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}