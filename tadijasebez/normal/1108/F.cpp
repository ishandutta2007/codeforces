#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=200050;
struct DSU
{
	int p[N];
	DSU(){ for(int i=0;i<N;i++) p[i]=i;}
	int Find(int x){ return x==p[x]?x:p[x]=Find(p[x]);}
	void Union(int x, int y){ p[Find(x)]=Find(y);}
} Tree;
int main()
{
	int n,m,i,u,v,w;
	scanf("%i %i",&n,&m);
	vector<pair<int,pair<int,int> > > edges;
	for(int i=1;i<=m;i++) scanf("%i %i %i",&u,&v,&w),edges.pb(mp(w,mp(u,v)));
	sort(edges.begin(),edges.end());
	int j=0,ans=0;
	for(i=0;i<edges.size();i=j)
	{
		int cnt=0;
		for(j=i;j<edges.size() && edges[i].first==edges[j].first;j++)
			if(Tree.Find(edges[j].second.first)!=Tree.Find(edges[j].second.second))
				cnt++;
		for(j=i;j<edges.size() && edges[i].first==edges[j].first;j++)
			if(Tree.Find(edges[j].second.first)!=Tree.Find(edges[j].second.second))
				cnt--,Tree.Union(edges[j].second.first,edges[j].second.second);
		ans+=cnt;
	}
	printf("%i\n",ans);
	return 0;
}