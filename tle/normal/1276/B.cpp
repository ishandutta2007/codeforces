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
#include <assert.h>
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
#define SZ 1234567
int T,n,m,a,b,skip,u[SZ],v[SZ];
Edg
bool v1[SZ],v2[SZ];
void dfs(int x,bool*v)
{
	if(v[x]) return;
	v[x]=1;
	for esb(x,e,b)
		if(!v[b]&&b!=skip) dfs(b,v);
}
void sol()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	M=0;
	for(int i=1;i<=n;++i) fst[i]=v1[i]=v2[i]=0;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",u+i,v+i);
		adde(u[i],v[i]);
	}
	skip=b;dfs(a,v1);
	skip=a;dfs(b,v2);
	int cn[4];
	memset(cn,0,sizeof cn);
	for(int i=1;i<=n;++i)
		if(i!=a&&i!=b)
			++cn[v1[i]*2+v2[i]];
	ll ans=cn[0]*(ll)(cn[0]-1)/2+cn[0]*(ll)cn[1]+cn[1]*(ll)cn[2]
	+cn[0]*(ll)cn[2]+cn[0]*(ll)cn[3];
	cout<<ans<<"\n";
}
int main()
{
	scanf("%d",&T);
	while(T--) sol();
}