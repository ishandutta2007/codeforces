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
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T> void read(T &x){
	x=0;char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
}
const int MAXN=1e5;
const ll INF=1e18;
ll pw[MAXN+5];
bool is[MAXN+5];
void solve(){
	int n;ll k;scanf("%d%lld",&n,&k);
	if(k>pw[n-1]) return puts("-1"),void();
	for(int i=1;i<n;i++) is[i]=0;--k;
	for(int i=60;~i;i--) if(k>>i&1) is[n-1-i]=1;
	is[n]=1;
	for(int l=1,r;l<=n;l=r+1){
		r=l;while(is[r]&&r<n) r++;
		for(int j=r;j>=l;j--) printf("%d ",j);
	} printf("\n");
}
int main(){
	pw[0]=1;for(int i=1;i<=MAXN;i++) pw[i]=min(pw[i-1]*2,INF);
	int qu;scanf("%d",&qu);while(qu--) solve();
	return 0;
}