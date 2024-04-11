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
int n,m,edg[24];
int cl[4555555],ta[4555555],tb[4555555];
inline void op(int x)
{
	if(!cl[x]) return;
	printf("%d ",ta[x]+1);
	op(tb[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i) edg[i]=1<<i;
	for(int i=0;i<m;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		--a,--b;
		edg[a]|=1<<b; edg[b]|=1<<a;
	}
	memset(cl,127/3,sizeof cl);
	for(int r=0;r<=n;++r)
	{
	for(int i=0;i<(1<<n);++i) if(__builtin_popcount(i)==r)
	{
		bool g=1;
		for(int j=0;j<n;++j) if(i&(1<<j))
			g&=(edg[j]&i)==i;
		if(g) cl[i]=0, ta[i]=tb[i]=-1;
		for(int j=0;j<n;++j)
		{
			int miss=(~edg[j])&i;
			int qt=cl[miss|(1<<j)]+1;
			if(qt>=cl[i]) continue;
			cl[i]=qt; ta[i]=j; tb[i]=miss|(1<<j);
		}
	}
	}
	printf("%d\n",cl[(1<<n)-1]);
	op((1<<n)-1);
}