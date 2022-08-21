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
Edg
int n,ea[SZ],eb[SZ],col[SZ];
void dfs(int x)
{
	for es(x,e)
	{
		int b=vb[e];
		if(col[b]!=-1) continue;
		col[b]=col[x]^1; dfs(b);
	}
}
int main()
{
	memset(col,-1,sizeof(col));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",ea+i,eb+i);
		--ea[i], --eb[i];
		adde(ea[i],eb[i]);
	}
	for(int i=0;i<n;i++) adde(i*2,i*2+1);
	for(int i=0;i<n+n;i++)
	{
		if(col[i]!=-1) continue;
		col[i]=0; dfs(i);
	}
	for(int i=0;i<n;i++)
	printf("%d %d\n",col[ea[i]]+1,col[eb[i]]+1);
}