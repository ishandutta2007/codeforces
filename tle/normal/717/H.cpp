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
int n,e,ea[SZ],eb[SZ];
int ds[SZ],tmd[SZ],th[SZ],T=0;
vector<int> wss[SZ];
bool col[SZ];
int lst[SZ];
bool cmp(int a,int b)
{
	return th[a]>th[b];
}
void suiji()
{
	for(int i=1;i<=n;i++) tmd[i]=wss[i][rand()%wss[i].size()];
	for(int i=1;i<=T;i++) th[i]=0;
	for(int i=1;i<=n;i++) th[tmd[i]]+=ds[i];
	for(int i=1;i<=T;i++) lst[i]=i;
	sort(lst+1,lst+1+T,cmp);
	for(int i=1;i<=T;i++) col[lst[i]]=i&1;
	int cc=0;
	for(int i=1;i<=e;i++)
	{
		if(col[tmd[ea[i]]]!=col[tmd[eb[i]]]) cc+=2;
	}
	if(cc>=e)
	{
		for(int i=1;i<=n;i++) printf("%d ",tmd[i]);
		puts("");
		for(int i=1;i<=T;i++) printf("%d ",col[i]+1);
		puts("");
		exit(0);
	}
}
int main()
{
	scanf("%d%d",&n,&e);
	for(int i=1;i<=e;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		ea[i]=a; eb[i]=b;
		++ds[a]; ++ds[b];
	}
	for(int i=1;i<=n;i++)
	{
		int p,w; scanf("%d",&p);
		while(p--)
		{
			scanf("%d",&w), wss[i].push_back(w);
			T=max(T,w);
		}
	}
	while(1) suiji();
}