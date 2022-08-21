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
#define SZ 555555
#define ws wsss
int n,m;Edg 
vector<int> ws[SZ];
pii rs[SZ]; int rn=0,ty[SZ];
void dfs(int x)
{
	for esb(x,e,b)
	{
		if(ty[b]!=-1) continue;
		ty[b]=1; dfs(b);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,a,b;i<=m;++i) ty[i]=-1;
	for(int i=1,a,b;i<=n;++i)
	{
		scanf("%d",&a);
		while(a--) scanf("%d",&b),ws[i].pb(b);
	}
	for(int i=2;i<=n;++i)
	{
		int na=-1,nb=-1;
		for(int j=0;j<ws[i-1].size()&&j<ws[i].size();++j)
		{
			if(ws[i-1][j]!=ws[i][j])
			{
				na=ws[i-1][j]; nb=ws[i][j];
				break;
			}
		}
		if(na==-1)
		{
			if(ws[i-1].size()>ws[i].size())
			{
				puts("No");
				return 0;
			}
			continue;
		}
		if(na<nb)
		{
			//nb->na
			ad_de(nb,na);
			rs[++rn]=pii(nb,na);
		}
		else
		{
			#define sett(x,y) \
			if(ty[x]==1-y)\
			{\
				puts("No");\
				return 0;\
			}\
			ty[x]=y;
			//nanb 
			sett(na,1); sett(nb,0);
		}
	}
	for(int i=1;i<=m;++i)
		if(ty[i]==1) dfs(i);
	for(int i=1;i<=m;++i)
		if(ty[i]==-1) ty[i]=0;
	for(int i=1;i<=rn;++i)
	{
		if(ty[rs[i].fi]==1&&ty[rs[i].se]==0)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	vector<int> vv;
	for(int i=1;i<=m;++i)
		if(ty[i]==1) vv.pb(i);
	printf("%d\n",int(vv.size()));
	for(auto p:vv) printf("%d ",p);
}