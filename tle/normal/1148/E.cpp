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
#define SZ 666666
int n,t[SZ];
pii s[SZ];
bool by_s(int x,int y) {return s[x]<s[y];}
struct sc
{
bool operator () (int x,int y) const
{if(s[x]!=s[y]) return s[x]<s[y]; return x<y;}
};
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&s[i].fi),s[i].se=i;
	for(int i=1;i<=n;++i)
		scanf("%d",t+i);
	sort(s+1,s+1+n);
	sort(t+1,t+1+n);
	for(int i=1;i<=n;++i)
		s[i].fi-=t[i];
	vector<vector<int>>op;
	int a=1,b=1;
	while(1)
	{
		while(a<=n&&s[a].fi>=0) ++a;
		while(b<=n&&s[b].fi<=0) ++b;
		if(a>n) break;
		if(a>b||b>n)
		{
			puts("NO");
			return 0;
		}
		int d=min(-s[a].fi,s[b].fi);
		op.pb({s[a].se,s[b].se,d});
		s[a].fi+=d; s[b].fi-=d;
		if(op.size()>5*n)
		    throw "??";
	}
	for(int i=1;i<=n;++i)
		if(s[i].fi)
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	printf("%d\n",int(op.size()));
	for(auto t:op)
	{
		for(auto x:t) printf("%d ",x);puts("");
	}
}