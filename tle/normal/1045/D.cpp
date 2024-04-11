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
int n,q,fa[SZ]; ld a[SZ],sc[SZ],ans=0; Edg
void dfs(int x,int f=0)
{
	fa[x]=f;
	for esb(x,e,b) if(b!=f)
		sc[x]+=a[b],dfs(b,x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lf",a+i),a[i]=1-a[i];
	for(int i=1,a,b;i<n;++i)
		scanf("%d%d",&a,&b),
		++a,++b,adde(a,b);
	dfs(1);
	for(int i=1;i<=n;++i)
		ans+=a[i]-a[i]*sc[i];
	scanf("%d",&q);
	while(q--)
	{
		int x; ld u;
		scanf("%d%lf",&x,&u); u=1-u;
		++x; u=u-a[x];
		ans+=u*(1-sc[x]);
		if(fa[x])
			ans-=a[fa[x]]*u,
			sc[fa[x]]+=u;
		a[x]+=u; printf("%.10lf\n",ans);
	}
}