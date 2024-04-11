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
int m;
vector<pair<ll,ll>> zip(int*a,int n) {
	ll x=0,y=0;
	vector<pair<ll,ll>> ans;
	for(int i=1;i<=n;++i) {
		ll p=a[i],q=1;
		while(p%m==0) p/=m,q*=m;
		if(x!=p) {
			ans.pb(mp(x,y));
			y=0;
		}
		x=p; y+=q;
	}
	ans.pb(mp(x,y));
	return ans;
}
int T,n,a[233333],u,v[233333];
void sol() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	scanf("%d",&u);
	for(int i=1;i<=u;++i)scanf("%d",v+i);
	puts((zip(a,n)==zip(v,u))?"Yes":"No");
}
int main()
{
	scanf("%d",&T);
	while(T--) sol();
}