#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 100010;

int n, dp[61][N];
struct dat{
	LL a,b;
}a[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	scanf("%d",&n);
	LL ma=0;
	rep(i,1,n)scanf("%lld",&a[i].a),ma=max(ma,a[i].a);
	rep(i,1,n)a[i].a=ma-a[i].a;
	rep(i,0,60)rep(j,0,n)dp[i][j]=1e8;
	dp[0][0]=0;
	rep(i,1,60){
		LL tmp = (1ll<<i-1)-1;
		rep(j,1,n)a[j].b=a[j].a&tmp;
		sort(a+1,a+n+1,[](dat x,dat y){return x.b>y.b;});
		int num1=0, cnt=0;
		rep(j,1,n) if(a[j].a&(1ll<<i-1)) ++num1;
		rep(j,0,n){
			if(a[j].a&(1ll<<i-1)) ++cnt;
			dp[i][cnt] = min(dp[i][cnt], num1+j-2*cnt+dp[i-1][j]);
			dp[i][num1+j-cnt] = min(dp[i][num1+j-cnt], n-num1-j+2*cnt+dp[i-1][j]);
		}
	}
	printf("%d\n",dp[60][0]);
	return 0;
}