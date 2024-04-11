#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 998244353;
const int N = 200010;

LL dp[2][N>>1],a[2][N>>1], k;
int seg[N>>1], num[N>>1], x, n;

LL calc(LL a[], int n){
	rep(i,2,n)if(a[i]!=-1&&a[i]==a[i-1])return 0ll; 
	int cnt=0;
	rep(i,1,n)if(a[i]!=-1)seg[++cnt]=i,num[cnt]=a[i];
	if(cnt==0){
		LL res = k;
		rep(i,2,n) res = res * (k-1) % MOD;
		return res;
	}
	LL res = 1;
	rep(i,1,seg[1]-1) res = res * (k-1) % MOD;
	rep(i,seg[cnt]+1,n) res = res * (k-1) % MOD;
	rep(i,1,cnt-1){
		int len=seg[i+1]-seg[i]-1;
		res = res * dp[num[i]!=num[i+1]][len] % MOD;
	}
	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
    scanf("%d%lld",&n,&k);
    dp[0][0] = dp[1][0] = 1;
    dp[0][1]=k-1;dp[1][1]=k-2;//0:same; 1:different
    rep(i,2,n/2+1){
    	dp[0][i] = dp[1][i-1] * (k-1) % MOD;
    	dp[1][i] = dp[0][i-1] + dp[1][i-1] * (k-2) % MOD;
    	//cout<<i<<" "<<dp[0][i]<<" "<<dp[1][i]<<endl;
	}
	
    rep(i,2,n+1){
    	scanf("%d",&x);
    	a[i%2][i/2] = x;
	}
	//rep(i,1,(n+1)/2)cout<<a[0][i]<<" ";cout<<endl;
	//rep(i,1,n/2)cout<<a[1][i]<<" ";cout<<endl;
	//cout<<calc(a[0], (n+1)/2)<<" "<<calc(a[1], n/2)<<endl;
	printf("%lld\n",calc(a[0], (n+1)/2)*calc(a[1], n/2) % MOD);
	return 0;
}