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
int n; struct th {int t,d,p,ri;}a[SZ];
bool operator < (th a,th b) {return a.d<b.d;}
int f[105][2025],ys[1026];
bitset<105> g[105][2025];
#define C 2000
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",&a[i].t,&a[i].d,&a[i].p),a[i].ri=i;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=C;++j)
			f[i][j]=f[i-1][j],g[i][j]=g[i-1][j];
		for(int j=0;j<=C;++j)
			if(j+a[i].t<a[i].d)
			{
				int s=f[i-1][j]+a[i].p;
				if(s>f[i][j+a[i].t])
				{
					f[i][j+a[i].t]=s;
					g[i][j+a[i].t]=g[i-1][j];
					g[i][j+a[i].t][i]=1;
				}
			}
	}
	int gg=0;
	for(int i=0;i<=C;++i)
		if(f[n][i]>f[n][gg]) gg=i;
	bitset<105> r=g[n][gg];
	printf("%d\n",f[n][gg]);
	vector<int> vs;
	for(int i=1;i<=n;++i)
		if(r[i]) vs.pb(a[i].ri);
	printf("%d\n",int(vs.size()));
	for(auto g:vs) printf("%d ",g);
}