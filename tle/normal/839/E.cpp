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
int n,m,cnt=0,mx=0;
bitset<43> goo[43],bad[43];
void bk(bitset<43> r,bitset<43> p,bitset<43> x)
{
	if(!(p.count()||x.count()))
	{mx=max(mx,int(r.count())); return;}
	if(r.count()+p.count()-(p&x).count()<=mx) return;
	bitset<43> g=p|x;
	int mx=1e9,u=0;
	for(int i=1;i<=n;i++)
	{
		if(!g[i]) continue;
		int fs=(p&bad[i]).count();
		if(fs<mx) mx=fs,u=i;
	}
	bitset<43> s=p&bad[u];
	for(int i=1;i<=n;i++)
	{
		if(!s[i]) continue;
		bitset<43> R=r; R.set(i);
		bitset<43> P=p; P&=~bad[i];
		bitset<43> X=x; X&=~bad[i];
		bk(R,P,X); p.reset(i); x.set(i);
	}
}
int main()
{
	int k; scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;++j)
		{
			int s; scanf("%d",&s);
			if(i!=j) goo[i][j]=s;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) bad[i][j]=!goo[i][j];
	bitset<43> em,tw;
	memset(&em,0,sizeof em);
	memset(&tw,0,sizeof tw);
	for(int i=1;i<=n;i++) tw[i]=1;
	bk(em,tw,em); int ans=mx;
	printf("%.10lf\n",k*(ld)k*(ans-1)/ld(2.0*ans));
}