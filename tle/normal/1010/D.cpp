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
#define SZ 2333333
int n,fa[SZ],good[SZ];
char ss[SZ][4];
int ch[SZ][2],vv[SZ];
int calc(int x)
{
	if(ss[x][0]=='I') return vv[x];
	if(ss[x][0]=='A')
		return vv[ch[x][0]]&&vv[ch[x][1]];
	if(ss[x][0]=='O')
		return vv[ch[x][0]]||vv[ch[x][1]];
	if(ss[x][0]=='X')
		return vv[ch[x][0]]^vv[ch[x][1]];
	if(ss[x][0]=='N')
		return !vv[ch[x][0]];
	return -1;
}
void dfs(int x)
{
	for(int i=0;i<2;++i)
		if(ch[x][i])
			fa[ch[x][i]]=x, dfs(ch[x][i]);
	vv[x]=calc(x);
}
void dfs2(int x)
{
	if(x!=1)
	{
		vv[x]^=1;
		if(calc(fa[x])==vv[fa[x]])
		{vv[x]^=1; return;}
		vv[x]^=1;
	}
	good[x]=1;
	for(int i=0;i<2;++i)
		if(ch[x][i]) dfs2(ch[x][i]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",ss[i]);
		if(ss[i][0]=='I')
			scanf("%d",vv+i);
		else if(ss[i][0]=='N')
			scanf("%d",ch[i]);
		else
			scanf("%d%d",ch[i],ch[i]+1);
	}
	dfs(1); dfs2(1);
	for(int i=1;i<=n;++i)
		if(ss[i][0]=='I') printf("%d",good[i]^vv[1]);
}