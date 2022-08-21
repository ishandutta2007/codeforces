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
#define SZ 233333
const int MOD=1e9+7;
int n,a[SZ],f[5005][10005];
ll qz[SZ],ans[10005];
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
int main()
{
	scanf("%d",&n); qz[1]=1;
	for(int i=1;i<n;++i)
		scanf("%d",a+i),qz[i+1]=qz[i]*a[i]%MOD;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			(f[min(i,j)-1][i+j]+=qz[i]*qz[j]%MOD)%=MOD;
	for(int i=n;i>=1;--i)
	{
		for(int j=1;j<=n+n;++j) (f[i][j]+=f[i+1][j])%=MOD;
		ll sw=qp(qz[i+1],(MOD-2)*2LL);
		for(int j=1;j<=n+n;++j) if(f[i][j])
			(ans[j-i*2]+=qz[i]*(ll)a[i]%MOD*(ll)(a[i]-1)%MOD*sw%MOD*f[i][j])%=MOD;
	}
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			(ans[j-i]+=qz[j]*2LL)%=MOD;
	for(int i=1;i<=(n-1)*2;++i)
		printf("%d ",int((ans[i]*(ll)((MOD+1)/2)%MOD+MOD)%MOD));
}