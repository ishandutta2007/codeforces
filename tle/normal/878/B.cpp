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
int n,k,m,a[2333333];
pii ps[2333333];
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	a[n+1]=-1; int h=0,t=0;
	for(int i=1;i<=n;++i)
	{
		if(t&&ps[t-1].fi==a[i]) ++ps[t-1].se;
		else ps[t++]=pii(a[i],1);
		if(ps[t-1].se==k) --t;
	}
	ll s=0;
	for(int i=h;i<t;++i) s+=ps[i].se;
	s*=m;
	if(m==1||s==0) return !printf("%lld\n",s);
	while(h+1<t)
	{
		if(ps[h].fi!=ps[t-1].fi)
			return !printf("%lld\n",s);
		if(ps[h].se+ps[t-1].se>=k) s-=(ll)(m-1)*k;
		if(ps[h].se+ps[t-1].se==k) ++h, --t;
		else return !printf("%lld\n",s);
	}
	if(h>=t) return !printf("0\n");
	ll g=ps[h].se; g*=m;
	if(g%k) printf("%lld\n",s-g/k*k);
	else puts("0");
}