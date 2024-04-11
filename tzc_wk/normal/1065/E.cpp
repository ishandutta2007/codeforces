#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
const int MAXN=2e5;
const int MOD=998244353;
int n,m,k,a[MAXN+5],ans=1;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	ans=qpow(k,n-a[m]);ans=1ll*ans*qpow(qpow(2,m),MOD-2)%MOD;
	for(int i=m;i;i--) a[i]-=a[i-1];
	for(int i=1;i<=m;i++) ans=1ll*ans*(1+qpow(k,a[i]))%MOD;
	printf("%d\n",ans);
	return 0;
}