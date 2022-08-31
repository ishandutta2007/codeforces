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
int n,a[2][SZ],p[SZ];
bool vis[SZ];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a[0]+i);
	for(int i=1;i<=n;i++) scanf("%d",a[1]+i);
	{
	int g=0,ok=1;
	for(int i=1;i<=n;i++)  vis[i]=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		if(a[0][i]==a[1][i]) x=a[0][i];
		else x=(a[g^=1][i]);
		p[i]=x; if(vis[x]||x<1||x>n) ok=0;
		vis[x]=1;
	}
	for(int i=0;i<2;i++)
	{
		int c=0;
		for(int j=1;j<=n;j++)
			c+=a[i][j]!=p[j];
		if(c!=1) ok=0;
	}
	if(ok)
	{
		for(int i=1;i<=n;i++) printf("%d ",p[i]);
		return 0;
	}
	}
	{
	int g=1,ok=1;
	for(int i=1;i<=n;i++)  vis[i]=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		if(a[0][i]==a[1][i]) x=a[0][i];
		else x=(a[g^=1][i]);
		p[i]=x; if(vis[x]||x<1||x>n) ok=0;
		vis[x]=1;
	}
	for(int i=0;i<2;i++)
	{
		int c=0;
		for(int j=1;j<=n;j++)
			c+=a[i][j]!=p[j];
		if(c!=1) ok=0;
	}
	if(ok)
	{
		for(int i=1;i<=n;i++) printf("%d ",p[i]);
		return 0;
	}
	}
	{
	int g=0,ok=1,rr=0;
	for(int i=1;i<=n;i++) rr^=i;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		if(a[0][i]==a[1][i]) x=a[0][i],rr^=a[0][i];
		else x=-1;
		p[i]=x;
	}
	for(int i=1;i<=n;i++)
	{
		if(p[i]==-1) p[i]=rr;
		int x=p[i];
		if(vis[x]||x<1||x>n) ok=0;
		vis[x]=1;
	}
	for(int i=0;i<2;i++)
	{
		int c=0;
		for(int j=1;j<=n;j++)
			c+=a[i][j]!=p[j];
		if(c!=1) ok=0;
	}
	if(ok)
	{
		for(int i=1;i<=n;i++) printf("%d ",p[i]);
		return 0;
	}
	}
}