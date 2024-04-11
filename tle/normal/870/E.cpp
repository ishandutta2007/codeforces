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
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}\
void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
int n; pair<pii,int> ps[SZ],pp[SZ];
Edg
map<int,int> bf;
bool vis[SZ];
set<int> X,Y;
const int MOD=1e9+7;
bool dfs(int x,int f=0)
{
	//cout<<x<<","<<f<<"!!\n";
	X.insert(pp[x].fi.fi);
	Y.insert(pp[x].fi.se);
	bool g=1; vis[x]=1;
	for esb(x,e,b) if(b!=f)
	{
		if(vis[b]) g=0;
		else g&=dfs(b,x);
	}
	return g;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&ps[i].fi.fi,&ps[i].fi.se),
		ps[i].se=i,pp[i]=ps[i];
	bf.clear();
	sort(ps+1,ps+1+n);
	for(int i=1;i<=n;++i)
	{
		int&g=bf[ps[i].fi.fi];
		if(g) adde(ps[i].se,g);
		g=ps[i].se;
	}
	for(int i=1;i<=n;++i)
		swap(ps[i].fi.fi,ps[i].fi.se);
	bf.clear();
	sort(ps+1,ps+1+n);
	for(int i=1;i<=n;++i)
	{
		int&g=bf[ps[i].fi.fi];
		if(g) adde(ps[i].se,g);
		g=ps[i].se;
	}
	ll aa=1;
	for(int i=1;i<=n;++i)
	{
		if(vis[i]) continue;
		X.clear(); Y.clear(); int g=0;
		if(dfs(i,0)) g=1;
		int rs=X.size()+Y.size();
		//for(auto a:X) cout<<a<<",";cout<<"\n";
		//for(auto a:Y) cout<<a<<",";cout<<"\n";
		//cout<<rs<<","<<g<<" "<<X.size()<<","<<Y.size()<<"\n";
		ll ans=1;
		for(int i=1;i<=rs;++i) ans=ans*2%MOD;
		ans-=g; aa=aa*ans%MOD;
		//cout<<ans<<"\n";
	}
	aa=(aa%MOD+MOD)%MOD;
	printf("%d\n",int(aa));
}