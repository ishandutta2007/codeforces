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
int T,n,m,col[SZ],cnt[3]; Edg
const int MOD=998244353;
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
void dfs(int x)
{
	++cnt[col[x]];
	for esb(x,e,b)
	{
		if(!col[b])
			col[b]=3-col[x],dfs(b);
		else if(col[b]!=3-col[x]) throw "GG";
	}
}
void sol()
{
	scanf("%d%d",&n,&m); M=0;
	for(int i=1;i<=n;++i) fst[i]=col[i]=0;
	for(int i=1,a,b;i<=m;++i)
		scanf("%d%d",&a,&b),adde(a,b);
	ll ans=1;
	try
	{
		for(int i=1;i<=n;++i) if(!col[i])
		{
			memset(cnt,0,sizeof cnt);
			col[i]=1; dfs(i);
			ans*=qp(2,cnt[1])+qp(2,cnt[2]);
			ans=(ans%MOD+MOD)%MOD;
		}
	}
	catch(...)
	{
		puts("0");
		return;
	}
	printf("%lld\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--) sol();
}