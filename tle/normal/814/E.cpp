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
typedef long long ll;
ll MOD=1e9+7,r2=(MOD+1)/2;
int n,d[SZ];
ll fac[SZ],pw[SZ];
int f[2][55][55][105];
inline int add(ll a,ll b) {return (a+b)%MOD;}
inline ll C2(ll x) {x%=MOD; return ((x*(x-1))>>1)%MOD;}
int main()
{
	pw[0]=fac[0]=1;
	for(int i=1;i<SZ;i++)
		fac[i]=fac[i-1]*i%MOD,
		pw[i]=pw[i-1]*r2%MOD;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",d+i);
	bool xx=0;
	if(d[2]==2) f[xx][1][0][d[1]-1]=1;
	else f[xx][0][1][d[1]-1]=1;
	int ans=0;
	for(int i=3;i<=n;i++)
	{
		bool c=i&1,b=!c;
		memset(f[c],0,sizeof f[0]);
		for(int k=0;k<=i;k++)
			for(int l=0;k+l<=i;++l)
				for(int m=0;m<=i+i;++m)
					{
						if(d[i]==2)
						{
						{
						int&p=f[c][k+1][l][m];
						p=add(p,f[b][k][l][m+1]);
						}
						{
						int&p=f[c][k][l][m];
						p=add(p,f[b][k+1][l][m+1]*ll(k+1));
						if(k) p=add(p,f[b][k-1][l+1][m+1]*ll(l+1));
						}
						}
						else
						{
						{
						int&p=f[c][k][l+1][m];
						p=add(p,f[b][k][l][m+1]);
						}
						{
						int&p=f[c][k+1][l][m];
						p=add(p,f[b][k+1][l][m+1]*ll(k+1));
						if(k) p=add(p,f[b][k-1][l+1][m+1]*ll(l+1));
						}
						{
						int&p=f[c][k][l][m];
						p=add(p,f[b][k][l+1][m+1]*ll(k)%MOD*ll(l+1));
						if(k>=2) p=add(p,f[b][k-2][l+2][m+1]*C2(l+2));
						p=add(p,f[b][k+2][l][m+1]*C2(k+2));
						}
						}
					}
		for(int k=0;k<=i;k++)
			for(int l=!k;k+l<=i;++l)
			{
				int&p=f[c][d[i]==2][d[i]==3][k+l*2-1];
				p=add(p,ll(f[b][k][l][0])*fac[k+l*2]%MOD*pw[l]);
			}
		if(i==n) ans=f[c][0][0][0];
	}
	printf("%d\n",ans);
}