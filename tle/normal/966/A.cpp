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
int n,m,cl,ce,v;
set<int> A,B;
ll go(set<int>&s,int mv,int x1,int y1,int x2,int y2)
{
	if(x1>x2) swap(x1,x2),swap(y1,y2);
	if(y1==y2) return abs(x1-x2);
	ll my=((ll)abs(y2-y1)+mv-1)/mv;
	auto t=s.lower_bound(x1);
	if(t!=s.begin()) --t;
	ll ans=3e18;
	for(int j=0;j<4&&t!=s.end();++j,++t)
		ans=min(ans,abs(x1-*t)+(ll)abs(x2-*t)+my);
	return ans;
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
	for(int i=1,x;i<=cl;++i)
		scanf("%d",&x),A.insert(x);
	for(int i=1,x;i<=ce;++i)
		scanf("%d",&x),B.insert(x);
	int q; scanf("%d",&q);
	while(q--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
		printf("%lld\n",
		min(go(A,1,x1,y1,x2,y2),
		go(B,v,x1,y1,x2,y2)));
	}
}