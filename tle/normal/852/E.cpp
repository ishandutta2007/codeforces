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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
//orz kczno1    POD only
template<typename T>
struct vec{T *a;int n;void clear(){n=0;}
void pb(const T &x){if((n&-n)==n)a=(T*)realloc(a,(n*2)*sizeof(T));a[n++]=x;}
inline T* begin(){return a;}inline T* end() {return a+n;}};
const int MOD=1e9+7;
Edg
int n,po2[SZ],d[SZ];
int main()
{
	po2[0]=1;
	for(int i=1;i<SZ;++i) po2[i]=po2[i-1]*2%MOD;
	scanf("%d",&n);
	if(n==1)
	{
		puts("1");
		return 0;
	}
	for(int i=1;i<n;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		adde(a,b); ++d[a]; ++d[b];
	}
	int cur=0;
	for(int i=1;i<=n;++i) if(d[i]!=1) ++cur;
	ll ans=0;
	for(int i=1;i<=n;++i)
		ans+=po2[cur+(d[i]==1)];
	ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",int(ans));
}