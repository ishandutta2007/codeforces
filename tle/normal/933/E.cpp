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
int n,p[SZ];
vector<int> v;
void go(int x)
{
	int dt=min(p[x],p[x+1]);
	if(!dt) return;
	v.pb(x); p[x]-=dt; p[x+1]-=dt;
}
ll f[SZ]; int g[SZ];
int ss[SZ],sn=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",p+i);
	for(int i=1;i<=n;++i)
	{
		ll one=f[max(i-2,0)]+p[i],
		two=f[max(i-3,0)]+max(p[i-1],p[i]);
		if(one<two) f[i]=one,g[i]=2;
		else f[i]=two,g[i]=3;
	}
	ll ans=min(f[n-1],f[n]);
	for(int i=n-(ans==f[n-1]);i>0;i-=g[i]) ss[++sn]=i;
	reverse(ss+1,ss+1+sn);
	for(int i=1;i<=sn;++i)
	{
		int x=ss[i];
		if(g[x]==3) go(x-1);
		go(ss[i-1]+1); go(x);
	}
	printf("%d\n",int(v.size()));
	for(auto x:v) printf("%d\n",x);
}