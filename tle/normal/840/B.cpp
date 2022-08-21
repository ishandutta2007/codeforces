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
int n,m,d[SZ];
Edgc
bool cho[SZ],vs[SZ];
void flip(int x)
{
	if(d[x]==-1) return;
	d[x]^=1;
}
void dfs(int x,int f,int fe)
{
	vs[x]=1;
	for esb(x,e,b) if(!vs[b])
		dfs(b,x,vc[e]);
	if(!f) return;
	if(d[x]==1)
	{
		cho[fe]^=1; flip(x); flip(f);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	int x=1;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",d+i);
		if(d[i]==-1) x=i;
	}
	for(int i=1;i<=m;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		adde(a,b,i);
	}
	dfs(x,0,0);
	for(int i=1;i<=n;++i)
		if(d[i]==1)
		{
			puts("-1");
			return 0;
		}
	vector<int> vec;
	for(int i=1;i<=m;++i)
		if(cho[i]) vec.pb(i);
	printf("%d\n",int(vec.size()));
	for(int j:vec) printf("%d ",j);
	puts("");
}