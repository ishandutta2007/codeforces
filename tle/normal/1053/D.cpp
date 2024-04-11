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
int n,p[SZ],mr[2000555];
bool np[2000555];
#define S 6000000
int fy[2000555];
int ny[S],yy[S],an,cm[2000555];
const int MOD=1e9+7;
map<int,int> sb;
bool go(int g)
{
	int su=0;
	for(int t=fy[g];t;t=ny[t])
	{
		int y=0;
		while(g%yy[t]==0)
			++y,g/=yy[t];
		if(mr[yy[t]]>=y)
			continue;
		su=1; mr[yy[t]]=y;
	}
	return su;
}
int mc[2000555];
void AA(int g)
{
	for(int t=fy[g];t;t=ny[t])
	{
		int y=0;
		while(g%yy[t]==0)
			++y,g/=yy[t];
		if(mr[yy[t]]==y) ++mc[yy[t]];
	}
}
bool BB(int g)
{
	bool must=0;
	for(int t=fy[g];t;t=ny[t])
	{
		int y=0;
		while(g%yy[t]==0)
			++y,g/=yy[t];
		if(mr[yy[t]]==y) must|=mc[yy[t]]==1;
	}
	return must;
}
ll zy[SZ]; int zn=0;
int main()
{
	for(int i=2;i<=2000000;++i) if(!np[i])
		for(int j=i;j<=2000000;j+=i)
			++an,yy[an]=i,ny[an]=fy[j],
			fy[j]=an,np[j]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",p+i),++sb[-p[i]];
	int aa=0;
	for(auto g:sb)
	{
		if(g.se<2) continue;
		int w=-g.fi;
		if(!go(w)) aa=1;
		else zy[++zn]=w;
		for(int j=1;j<g.se;++j)
			if(!go(w-1)) aa=1;
			else zy[++zn]=w-1;
	}
	for(auto g:sb)
	{
		if(g.se!=1) continue;
		int w=-g.fi;
		if(go(w)) zy[++zn]=w;
		else if(go(w-1)) zy[++zn]=w-1;
		else aa=1;
	}
	for(int i=1;i<=zn;++i)
		AA(zy[i]);
	for(int i=1;i<=zn;++i)
		if(!BB(zy[i])) aa=1;
	ll ans=1;
	for(int i=1;i<=2000000;++i)
		while(mr[i]--) ans=ans*i%MOD;
	ans+=aa;
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}