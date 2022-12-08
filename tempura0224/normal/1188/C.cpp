#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=998244353 ;

ll dp[1010][1010];

int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	rep(i,n){
		scanf("%d",&a[i]);
		++a[i];
	}
	sort(a,a+n);
	vector<int> x(101010,0);
	rep(i,n)x[a[i]]=i+1;
	rep(i,100000)x[i+1]=max(x[i],x[i+1]);
	ll ans = 0;
	int cur = 1;
	while(cur*(k-1)<=100000){
		rep(i,n+1)rep(j,min(i+1,k+1))dp[i][j]=0;
		dp[0][0]=1;
		rep(i,n)rep(j,min(i+2,k+1)){
			dp[i+1][j]=dp[i][j];
			if(j>0){
				dp[i+1][j]+=dp[x[max(a[i]-cur,0)]][j-1];
				if(dp[i+1][j]>mod)dp[i+1][j]-=mod;
			}
		}
		ans+=dp[n][k];
		++cur;
	}
	cout<<ans%mod<<endl;
	return 0;
}