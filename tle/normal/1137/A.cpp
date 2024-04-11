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
int n,m;
int a[1005][1005];
pii g[1005][1005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i)
	{
		map<int,int> u;
		for(int j=1;j<=m;++j)
			u[a[i][j]]=0;
		int aa=0;
		for(auto&s:u)
			s.se=aa++;
		for(int j=1;j<=m;++j)
		{
			auto w=u[a[i][j]];
			pii cur(w,(int)u.size()-w-1);
			g[i][j]=cur;
		}
	}
	for(int i=1;i<=m;++i)
	{
		map<int,int> u;
		for(int j=1;j<=n;++j)
			u[a[j][i]]=0;
		int aa=0;
		for(auto&s:u)
			s.se=aa++;
		for(int j=1;j<=n;++j)
		{
			auto w=u[a[j][i]];
			pii cur(w,(int)u.size()-w-1);
			g[j][i].fi=max(g[j][i].fi,cur.fi);
			g[j][i].se=max(g[j][i].se,cur.se);
		}
	}
	for(int i=1;i<=n;++i,puts(""))
		for(int j=1;j<=m;++j)
			printf("%d ",g[i][j].fi+g[i][j].se+1);
}