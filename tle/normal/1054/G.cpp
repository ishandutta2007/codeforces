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
int T,n,m;
bitset<2005> bb[2005],rb[2005];
pii sb[2005];
char t[2333][2333];
Edg
int ff[SZ];
int gf(int x) {return ff[x]?ff[x]=gf(ff[x]):x;}
void uni(int a,int b)
{
	a=gf(a),b=gf(b);
	if(a^b)ff[a]=b;
}
pair<int,pii> g[5000005];
void sol()
{
	scanf("%d%d",&n,&m);
	M=0; for(int i=1;i<=n;++i) fst[i]=ff[i]=0;
	for(int i=1;i<=m;++i)
		scanf("%s",t[i]+1);
	for(int i=1;i<=n;++i)
	{
		memset(&bb[i],0,sizeof bb[0]);
		memset(&rb[i],0,sizeof rb[0]);
		for(int j=1;j<=m;++j)
			if(t[j][i]=='1') bb[i][j]=1;
			else rb[i][j]=1;
	}
	int gn=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			g[++gn]=mp(-int((bb[i]&bb[j]).count()),pii(i,j));
	sort(g+1,g+1+gn);
	vector<pii> ed;
	for(int i=1;i<=gn;++i)
	{
		int a=g[i].se.fi,b=g[i].se.se;
		if(gf(a)!=gf(b))
		{
			uni(a,b); adde(a,b);
			ed.pb(pii(a,b));
		}
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j) ff[j]=0;
		for(int j=1;j<=n;++j) if(t[i][j]=='1')
			for esb(j,e,b) if(t[i][b]=='1') uni(j,b);
		int cp=0;
		for(int j=1;j<=n;++j) if(t[i][j]=='1')
			cp+=gf(j)==j;
		if(cp>1)
		{
			puts("NO");
			return;
		}
	}
	puts("YES");
	for(auto t:ed)
		printf("%d %d\n",t.fi,t.se);
}
int main()
{
	scanf("%d",&T);
	while(T--) sol();
}