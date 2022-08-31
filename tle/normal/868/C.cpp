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
int n,k; int g[16],c[4];
void dfs(int d,int r)
{
	bool ok=r;
	for(int i=0;i<4;++i)
		if(c[i]*2>r) ok=0;
	if(ok)
	{
		puts("YES");
		exit(0);
	}
	if(d<=0) return;
	for(int i=0;i<16;++i)
	{
		if(!g[i]) continue;
		--g[i];
		for(int j=0;j<4;++j)
			if(i&(1<<j)) ++c[j];
		dfs(d-1,r+1);
		for(int j=0;j<4;++j)
			if(i&(1<<j)) --c[j];
		++g[i];
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		int s=0,x;
		for(int j=1;j<=k;++j)
			scanf("%d",&x),s=s*2+x;
		++g[s];
	}
	dfs(5,0);
	puts("NO");
}