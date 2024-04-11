#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
const int N=300050;
const int M=20*N;
int root[N*2],ls[M],rs[M],tsz;
ll sum[M];
void Add(int &c, int ss, int se, int qs, int qe, int x)
{
	if(qs>qe || qs>se || ss>qe) return;
	if(!c) c=++tsz;
	if(qs<=ss && qe>=se){ sum[c]+=x;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,x);
	Add(rs[c],mid+1,se,qs,qe,x);
}
ll Get(int c, int ss, int se, int qi)
{
	if(ss==se) return sum[c];
	int mid=ss+se>>1;
	if(qi<=mid) return Get(ls[c],ss,mid,qi)+sum[c];
	else return Get(rs[c],mid+1,se,qi)+sum[c];
}
vector<int> E[N];
int lid[N],rid[N],dep[N],tid;
void DFS(int u, int p)
{
	dep[u]=dep[p]+1;
	lid[u]=++tid;
	for(int v:E[u]) if(v!=p) DFS(v,u);
	rid[u]=tid;
}
ll sol[N];
int main()
{
	int n,q,i,x,u,v,j,d;
	scanf("%i",&n);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	scanf("%i",&q);
	vector<pair<int,pair<int,int> > > Qs;
	while(q--)
	{
		scanf("%i %i %i",&u,&d,&x);
		Qs.pb(mp(min(n,d+dep[u]),mp(u,x)));
	}
	sort(Qs.begin(),Qs.end());
	vector<pair<int,int> > Ps;
	for(i=1;i<=n;i++) Ps.pb(mp(dep[i],i));
	sort(Ps.begin(),Ps.end());
	int ptr=(int)Qs.size()-1;
	for(j=n-1;j>=0;j--)
	{
		while(ptr>=0 && Qs[ptr].first>=Ps[j].first)
			Add(root[0],1,n,lid[Qs[ptr].second.first],rid[Qs[ptr].second.first],Qs[ptr].second.second),ptr--;
        sol[Ps[j].second]=Get(root[0],1,n,lid[Ps[j].second]);
	}
	for(i=1;i<=n;i++) printf("%lld ",sol[i]);
	return 0;
}