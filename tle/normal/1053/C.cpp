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
const int MOD=1e9+7;
int n,q,a[SZ],w[SZ];
struct Fenwick1
{
ll bs[SZ];
void edt(int x,ll y)
{
	for(;x<=n;x+=x&-x) bs[x]+=y;
}
ll qs(int x)
{
	ll s=0;
	for(;x>=1;x-=x&-x) s+=bs[x];
	return s;
}
}B0;
struct Fenwick
{
int bs[SZ];
void edt(int x,int y)
{
	for(;x<=n;x+=x&-x) (bs[x]+=y)%=MOD;
}
ll qs(int x)
{
	int s=0;
	for(;x>=1;x-=x&-x) (s+=bs[x])%=MOD;
	return s;
}
}B1;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),a[i]-=i;
	for(int i=1;i<=n;++i) scanf("%d",w+i);
	for(int i=1;i<=n;++i)
		B0.edt(i,w[i]),
		B1.edt(i,w[i]*(ll)a[i]%MOD);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x<0)
		{
			x=-x; int dt=y-w[x];
			w[x]=y; B0.edt(x,dt);
			B1.edt(x,dt*(ll)a[x]%MOD);
		}
		else
		{
			ll sl=B0.qs(x-1),
			su=B0.qs(y)-sl;
			su=(su+1)/2;
			int l=x,r=y;
			while(l<r)
			{
				int m=(l+r)>>1;
				if(B0.qs(m)-sl>=su) r=m;
				else l=m+1;
			}
			int m=l;
			//mid pos is m
			ll ans=(B1.qs(y)-B1.qs(m))-
			(B0.qs(y)-B0.qs(m))%MOD*(a[m])%MOD
			-(B1.qs(m)-B1.qs(x-1))
			+(B0.qs(m)-B0.qs(x-1))%MOD*(a[m])%MOD;
			ans=(ans%MOD+MOD)%MOD;
			printf("%d\n",int(ans));
		}
	}
}