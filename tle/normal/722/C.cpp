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
int n,p[SZ];
int ff[SZ];
int gf(int x)
{
	return ff[x]?ff[x]=gf(ff[x]):x;
}
ll sum[SZ];
void uni(int a,int b)
{
	int ga=gf(a),gb=gf(b);
	if(ga^gb) ff[gb]=ga, sum[ga]+=sum[gb];
}
ll ans[SZ];
bool ok[SZ];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",sum+i);
	for(int i=1;i<=n;i++) scanf("%d",p+i);
	ll maxn=0;
	for(int i=n;i>=1;i--)
	{
		ans[i]=maxn;
		int x=p[i];
		if(x!=1&&ok[x-1]) uni(x,x-1);
		if(x!=n&&ok[x+1]) uni(x,x+1);
		maxn=max(maxn,sum[gf(x)]);
		ok[x]=1;
	}
	for(int i=1;i<=n;i++) printf("%I64d\n",ans[i]);
}