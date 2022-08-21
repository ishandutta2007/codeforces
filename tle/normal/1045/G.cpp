#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T>
struct rbt: tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>{};
rbt<pii> rb[2];
int n,k,x[SZ],r[SZ],q[SZ];
vector<pii> v1,v2;
map<int,pair<vector<pii>,vector<pii> > > m;
int c=0;
void ins(int a,int b)
{
	rb[a].insert(pii(b,++c));
}
int calc(int a,int l,int r)
{
	return rb[a].order_of_key(pii(r+1,-1))-rb[a].order_of_key(pii(l,-1));
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",x+i,r+i,q+i),
		v1.pb(pii(x[i],i)),
		v2.pb(pii(x[i]-r[i],i));
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(auto t:v1)
		for(int j=0;j<=k;++j)
			m[q[t.se]+j].fi.pb(t);
	for(auto t:v2)
		for(int j=0;j<=k;++j)
			m[q[t.se]+j].se.pb(t);
	ll ans=0;
	for(auto&it:m)
	{
		int u=0;
		map<int,pii> sd;
		rb[0].clear(); rb[1].clear();
		for(auto p:it.se.fi)
		{
			while(u<it.se.se.size()
			&&it.se.se[u].fi<=p.fi)
			{
				if(q[it.se.se[u].se]==it.fi)
					ins(0,x[it.se.se[u].se]);
				else ins(1,x[it.se.se[u].se]);
				++u;
			}
			if(q[p.se]==it.fi)
				ans+=calc(0,x[p.se]+1,x[p.se]+r[p.se])
				+calc(1,x[p.se]+1,x[p.se]+r[p.se]),
				++sd[x[p.se]].se;
			else
				ans+=calc(0,x[p.se]+1,x[p.se]+r[p.se]),
				++sd[x[p.se]].fi;
		}
		for(auto t:sd)
			ans+=t.se.fi*(ll)t.se.se,
			ans+=t.se.se*(ll)(t.se.se-1)/2;
	}
	cout<<ans<<"\n";
}