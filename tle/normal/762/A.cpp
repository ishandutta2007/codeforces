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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#ifdef LOCAL
#define TIMER cerr<<clock()<<"ms\n"
#else
#define TIMER
#endif
#define SZ 666666
typedef pair<ll,ll> pll;
vector<pll> fj(ll x)
{
	vector<pll> vec;
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i) continue;
		pll cur=pii(i,0);
		while(x%i==0) ++cur.se, x/=i;
		vec.pb(cur);
	}
	if(x>1) vec.pb(pll(x,1));
	return vec;
}
ll n,ans=0;
vector<pll> pp;
vector<ll> aa;
void dfs(int dep=0,ll cur=1)
{
	if(dep==pp.size())
	{
		aa.pb(cur);
		return;
	}
	ll a=pp[dep].fi,b=pp[dep].se;
	for(int j=0;j<=b;j++)
	{
		dfs(dep+1,cur);
		cur*=a;
	}
}
int main()
{
	cin>>n;
	pp=fj(n);
	dfs();
	int k; cin>>k;
	sort(aa.begin(),aa.end());
	if(k>aa.size()) puts("-1");
	else cout<<aa[k-1]<<"\n";
}