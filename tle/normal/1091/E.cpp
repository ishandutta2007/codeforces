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
int n,a[SZ],b[SZ];
ll sb[SZ];
ll F()
{
	ll mx=0; int B=n+1;
	for(int i=1;i<=n;++i) b[i]=a[i],sb[i]=sb[i-1]+b[i];
	for(int i=1;i<=n;++i)
	{
		while(b[B-1]<=i&&B>i+1) --B;
		B=max(B,i+1);
		//[B,u] <=i
		ll uu=sb[i]-i*ll(i-1)-(sb[n]-sb[B-1])-(B-1-i)*ll(i);
		mx=max(mx,uu);
	}
	return mx;
}
bool ok(int s)
{
	int u=0;
	for(int i=1;i<=n;++i)
		if(a[i]>s) b[++u]=a[i];
	b[++u]=s;
	for(int i=1;i<=n;++i)
		if(a[i]>s);else b[++u]=a[i];
	for(int i=1;i<=u;++i) sb[i]=sb[i-1]+b[i];
	int B=u+1;
	for(int i=1;i<=u;++i)
	{
		while(b[B-1]<=i&&B>i+1) --B;
		B=max(B,i+1);
		//[B,u] <=i
		ll uu=sb[i]-i*ll(i-1)-(sb[u]-sb[B-1])-(B-1-i)*ll(i);
		if(uu>0) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	sort(a+1,a+1+n,greater<int>());
	int sw=0;
	for(int i=1;i<=n;++i) sw+=a[i]&1;
	ll rq=F();
	if((sw+rq)&1) ++rq;
	if(!ok(rq))
	{
		puts("-1");
		return 0;
	}
	int l=0,r=n;
	while(l<r)
	{
		int m=(l+r+1)>>1;
		if(!ok(rq+m*2)) r=m-1; else l=m;
	}
	for(int i=0;i<=l;++i)
		printf("%lld ",rq+i*2);
}