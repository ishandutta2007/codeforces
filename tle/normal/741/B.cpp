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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#ifdef LOCAL
#define TIMER cerr<<clock()<<"ms\n"
#else
#define TIMER
#endif
#define SZ 666666
int n,m,w,wi[SZ],bi[SZ];
vi vs[SZ];
ll tw[SZ],tb[SZ];
int ff[SZ];
int gf(int x)
{
	return ff[x]?ff[x]=gf(ff[x]):x;
}
ll dp[23333],tmp[23333];
int main()
{
	scanf("%d%d%d",&n,&m,&w);
	for(int i=1;i<=n;i++) scanf("%d",wi+i);
	for(int i=1;i<=n;i++) scanf("%d",bi+i);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int gx=gf(x),gy=gf(y);
		if(gx^gy) ff[gx]=gy;
	}
	for(int i=1;i<=n;i++) tw[gf(i)]+=wi[i];
	for(int i=1;i<=n;i++) tb[gf(i)]+=bi[i];
	for(int i=1;i<=n;i++) vs[gf(i)].pb(i);
	for(int i=1;i<=n;i++)
	{
		if(!vs[i].size()) continue;
		for(int j=0;j<=w;j++) tmp[j]=dp[j];
		for(int j=tw[i];j<=w;j++)
		tmp[j]=max(tmp[j],dp[j-tw[i]]+tb[i]);
		//for(int j=0;j<=w;j++) cout<<tmp[j]<<",";puts("");
		for(int s:vs[i])
		for(int j=wi[s];j<=w;j++)
		tmp[j]=max(tmp[j],dp[j-wi[s]]+bi[s]);
		for(int j=0;j<=w;j++) dp[j]=tmp[j];
		//for(int j=0;j<=w;j++) cout<<tmp[j]<<",";puts("");
	}
	printf("%I64d\n",dp[w]);
}