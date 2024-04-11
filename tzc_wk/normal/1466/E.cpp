#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MOD=1e9+7;
const int MAXN=5e5;
int n,sum[62][2];ll a[MAXN+5];
void solve(){
	scanf("%d",&n);fill0(sum);
	fz(i,1,n) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=60;j++){
			sum[j][(a[i]>>j&1)]++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ll s1=0,s2=0;
		for(int j=0;j<=60;j++){
			ll pw=(1ll<<j)%MOD;
			if(a[i]>>j&1){
				s1=(s1+1ll*sum[j][1]*pw%MOD)%MOD;
				s2=(s2+1ll*n*pw%MOD)%MOD;
			} else {
				s2=(s2+1ll*sum[j][1]*pw%MOD)%MOD;
			}
		}
//		printf("%d %d\n",s1,s2);
		ans=(ans+1ll*s1*s2%MOD)%MOD;
	}
	printf("%d\n",ans);
}
int main(){
	int T;scanf("%d",&T);while(T--) solve();
	return 0;
}