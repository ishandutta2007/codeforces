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
#define SZ 1234567 //crap
int n; Edg
const int MOD=998244353;
const int r2=(MOD+1)/2;
ll f[SZ],g[SZ];
//(exp of maxm, prob of increase 1)
void dfs(int x,int fa=0)
{
	g[x]=1;
	for esb(x,e,b) if(b!=fa)
	{
		dfs(b,x);
		g[x]=g[x]*(1+g[b])%MOD*r2%MOD;
		(f[x]+=(f[b]+g[b])*r2)%=MOD;
	}
	g[x]=1-g[x];
}
int main()
{
	scanf("%d",&n);
	for(int i=1,a,b;i<n;++i)
		scanf("%d%d",&a,&b),adde(a,b);
	dfs(1);
	ll ans=g[1]+f[1];
	for(int i=2;i<=n;++i)
		ans+=(g[i]+f[i])*r2,ans%=MOD;
	for(int i=1;i<=n;++i)
		ans*=2,ans%=MOD;
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}