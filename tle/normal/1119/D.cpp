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
int n; ll s[SZ],g[SZ];
ll su[SZ];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",s+i);
	sort(s+1,s+1+n);
	for(int i=1;i<n;++i)
		g[i]=s[i+1]-s[i];
	sort(g+1,g+n);
	for(int i=1;i<n;++i)
		su[i]=su[i-1]+g[i];
	int q;
	scanf("%d",&q);
	while(q--)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		r=r-l+1; ll ans=r;
		auto w=lower_bound(g+1,g+n,r)-g;
		ans+=su[w-1]+(n-w)*r;
		printf("%lld ",ans);
	}
}