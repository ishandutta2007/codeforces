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
const int MAXN=100;
const int INF=0x3f3f3f3f;
int n,dp[MAXN+5][MAXN+5][2],ans=0;
pii a[MAXN+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].fi,&a[i].se);
	sort(a+1,a+n+1);a[0].fi=-INF;
	for(int i=0;i<=n;i++) for(int j=0;j<=i;j++) for(int k=0;k<2;k++){
		int rj=a[j].fi+a[j].se*k,mx=-INF,id=0,dir=0;
		for(int l=i+1;l<=n;l++) for(int o=0;o<2;o++){
			int rl=a[l].fi+a[l].se*o;
			if(rl>mx) mx=rl,id=l,dir=o;
			chkmax(dp[l][id][dir],dp[i][j][k]+mx-rl+min(rl-rj,a[l].se));
		} chkmax(ans,dp[i][j][k]);
	} printf("%d\n",ans);
	return 0;
}