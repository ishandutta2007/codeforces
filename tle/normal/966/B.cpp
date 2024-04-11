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
#define x1 xx1
#define x2 xx2
int n,x1,x2;
pii c[SZ];
pair<ll,int> mi[SZ];
void prt(vector<int> a,vector<int> b)
{
	puts("Yes");
	printf("%d %d\n",int(a.size()),int(b.size()));
	for(auto t:a) printf("%d ",c[t].se); puts("");
	for(auto t:b) printf("%d ",c[t].se); puts("");
	exit(0);
}
int main()
{
	scanf("%d%d%d",&n,&x1,&x2);
	for(int i=1;i<=n;++i) scanf("%d",&c[i].fi),c[i].se=i;
	sort(c+1,c+1+n);
	mi[0]=mp(1e18,0);
	for(int i=1;i<=n;++i)
		mi[i]=min(mi[i-1],mp((x2+c[i].fi*(ll)i)/(ll)c[i].fi,i));
	for(int i=n;i>=1;--i)
	{
		//c[i]*>=x1
		ll g=x1/c[i].fi;
		while(g*c[i].fi<x1) ++g;
		if(i+g-1>n) continue;
		if(c[i+g].fi*(ll)(n-i-g+1)>=x2)
		{
			vector<int> a,b;
			for(int s=0;s<g;++s) a.pb(i+s);
			for(int s=i+g;s<=n;++s) b.pb(s);
			prt(a,b);
		}
		if(i==1) continue;
		int r=mi[i-1].se;
		if(c[r].fi*(ll)(n-r+1-g)>=x2)
		{
			vector<int> a,b;
			for(int s=0;s<g;++s) a.pb(i+s);
			for(int s=r;s<=n;++s)
				if(s>=i&&s<i+g);else b.pb(s);
			prt(a,b);
		}
	}
	puts("No");
}