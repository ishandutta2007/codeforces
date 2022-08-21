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
int n,l[SZ],rot; Edg
void dfs(int x,int f=0)
{
	l[x]=0;
	for esb(x,e,b)
	{
		if(b==f) continue;
		dfs(b,x);
		if(rot) return;
		if(!l[x]) l[x]=l[b]+1;
		else if(l[x]!=l[b]+1)
		{rot=x; return;}
	}
	if(!l[x]) ++l[x];
}
bool gg; int l2=0;
void dfs2(int x,int f=0)
{
	l[x]=0;
	for esb(x,e,b)
	{
		if(b==f) continue;
		dfs2(b,x);
		if(gg) return;
		if(!l[x]) l[x]=l[b]+1;
		else if(l[x]!=l[b]+1)
		{
			if(x!=rot) {gg=1; return;}
			if(!l2) l2=l[b]+1;
			else if(l2!=l[b]+1) {gg=1; return;}
		}
	}
	if(!l[x]) ++l[x];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		adde(a,b);
	}
	dfs(1);
	int ans;
	if(!rot) ans=l[1]-1;
	else
	{
		dfs2(rot);
		if(gg) {puts("-1"); return 0;}
		ans=l[rot]+l2-2;
	}
	while(ans%2==0) ans/=2;
	printf("%d\n",ans);
}