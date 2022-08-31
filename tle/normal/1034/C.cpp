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
#define SZ 1000999
int n,a[SZ]; Edg
const int MOD=1e9+7;
ll sb[SZ],sw[SZ],f[SZ];
ll sz[SZ],su=0,lim;
ll dfs(int x)
{
	sz[x]=a[x];
	for esb(x,e,b) sz[x]+=dfs(b);
	return sz[x];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),su+=a[i];
	for(int i=1,p;i<n;++i)
		scanf("%d",&p),ad_de(p,i+1);
	dfs(1);
	for(int i=1;i<=n;++i)
	{
		//su/t*u=sz[i]
		//sz[i]/su=u/t
		ll gg=su/__gcd(sz[i],su);
		if(gg<=n) ++sb[gg];
	}
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;j+=i) sw[j]+=sb[i];
	ll ans=0;
	f[1]=1;
	for(int i=1;i<=n;++i)
	{
		if(su%i==0&&f[i])
		{
			if(sw[i]!=i) continue;
			(ans+=f[i])%=MOD;
			for(int j=i+i;j<=n;j+=i) (f[j]+=f[i])%=MOD;
		}
	}
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}