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
#include <assert.h>
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
#define SZ (1<<18)+5
//a boring problem?
const int MOD=998244353;
int n,m,e[SZ];
void fwt(int*x)
{
	for(int i=0;i<n;++i)
		for(int j=0;j<(1<<n);++j)
			if((j>>i)&1)
				(x[j]+=x[j^(1<<i)])%=MOD;
}
void ifwt(int*x)
{
	for(int i=0;i<n;++i)
		for(int j=0;j<(1<<n);++j)
			if((j>>i)&1)
				(x[j]-=x[j^(1<<i)])%=MOD;
}
int w[SZ],t[19][SZ],o[19][SZ];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a,--b;
		e[a]|=1<<b;
		e[b]|=1<<a;
	}
	for(int i=0;i<(1<<n);++i)
	{
		bool ok=1;
		for(int j=0;j<n;++j)
			if(i&(1<<j)) ok&=!(e[j]&i);
		if(ok) w[i]=t[__builtin_popcount(i)][i]=1;
	}
	//find inverse of t
	for(int p=0;p<=n;++p)
	{
		fwt(t[p]);
		for(int w=0;w<(1<<n);++w)
			o[p][w]=(p==0);
		for(int x=1;x<=p;++x)
			for(int g=0;g<(1<<n);++g)
				o[p][g]=(o[p][g]-(ll)t[x][g]*o[p-x][g])%MOD;
	}
	ifwt(o[n]);
	ll ans=o[n][(1<<n)-1];
	if(n&1) ans=-ans;
	ans=ans*m%MOD*((MOD+1)/2)%MOD;
	ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",int(ans));
}