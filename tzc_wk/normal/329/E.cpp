#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
const int MAXN=1e5;
int n,x[MAXN+5],y[MAXN+5],xx[MAXN+5],yy[MAXN+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		xx[i]=x[i];yy[i]=y[i];
	} sort(xx+1,xx+n+1);sort(yy+1,yy+n+1);
	int md=(n+1>>1),mnx=xx[md+1]-xx[md],mny=yy[md+1]-yy[md];
	if(n&1) chkmin(mnx,xx[md]-xx[md-1]),chkmin(mny,yy[md]-yy[md-1]);
	bool v1=0,v2=0,v3=0;ll res=0;
	for(int i=1;i<=n;i++) res+=abs(x[i]-xx[md])+abs(y[i]-yy[md]);
	for(int i=1;i<=n;i++){
		if(x[i]>xx[md]&&y[i]>yy[md]) v1=1;
		if(x[i]>xx[md]&&y[i]<=yy[md]) v2=1;
		if(x[i]==xx[md]&&y[i]==yy[md]) v3=1;
	} //printf("%lld %d %d\n",res,mnx,mny);
	if(n%2==0&&v1&&v2) res-=min(mnx,mny);
	else if(v1&&v2&&v3) res-=min(mnx,mny);
	printf("%lld\n",res<<1);
	return 0;
}