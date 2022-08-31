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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
int n,a[SZ],b[SZ],cn[SZ];
map<int,int> cnt;
ll fac[SZ],C[666][666];
const ll MOD=1e9+7;
ll f[666][666]; int an=0,su=0;
void pack(int x)
{
	if(!x) return;
	++an;
	for(int i=0;i<=su;++i)
	{
		if(!f[an-1][i]) continue;
		//ggap
		for(int g=0;g<=i&&g<=x;++g)
		{
			for(int r=0;r<=su+1-i&&g+r<=x;++r)
			{
				if(r||g);else continue;
				ll cur=C[su+1-i][r]*C[i][g]%MOD*C[x-1][g+r-1]%MOD;
				//g+rgap
				//x-g-rgap
				(f[an][x-g-r+i-g]+=f[an-1][i]*cur%MOD)%=MOD; 
			}
		}
	}
	su+=x;
}
int main()
{
	f[0][0]=fac[0]=1;
	for(int i=1;i<SZ;++i)
		fac[i]=fac[i-1]*i%MOD;
	for(int i=0;i<=660;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		int x=a[i];
		for(int j=2;j*j<=x;++j)
			while(x%(j*j)==0) x/=j*j;
		b[i]=x; ++cnt[x];
	}
	ll ans=1;
	for(auto g:cnt)
		ans=ans*fac[g.se]%MOD,pack(g.se);
	ans=ans*f[an][0]%MOD;
	printf("%d\n",int(ans));
}