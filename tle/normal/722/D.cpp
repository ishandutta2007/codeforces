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
set<int> wt[1800000];
map<int,int> is;
int n,xx[SZ],C=0;
int rs[SZ],rn=0;
int id(int x)
{
	int& w=is[x];
	if(!w) w=++C;
	return w;
}
bool cho[2333333];
bool ok(int pp,bool oo=0)
{
	for(int i=1;i<=C;i++) cho[i]=0;
	for(int i=1;i<=n;i++)
	{
		rn=0;
		for(int j=xx[i];j;j=j>>1) rs[++rn]=j;
		bool gg=0;
		for(int j=1;j<=rn;j++)
		{
			if(rs[j]>pp) continue;
			int x=id(rs[j]);
			if(cho[x]) continue;
			cho[x]=1;
			if(oo) printf("%d ",rs[j]);
			gg=1;
			break;
		}
		if(!gg) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",xx+i);
		rn=0;
		for(int j=xx[i];j;j=j>>1) rs[++rn]=j;
		for(int j=1;j<=rn;j++)
		{
			int x=id(rs[j]);
			wt[x].insert(xx[i]);
		}
	}
	int L=0,R=1e9+3;
	while(L<R)
	{
		int m=(L+R)>>1;
		if(ok(m)) R=m; else L=m+1;
	}
	ok(L,1);
}