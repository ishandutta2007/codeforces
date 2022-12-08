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
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


int dp[5050][5050];
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	rep(i,n)cin>>a[i];
	sort(a,a+n);
	rep(i,n){
		int idx=lower_bound(a,a+n,a[i]-5)-a;
		int cnt=i-idx+1;
		rep(j,k+1){
			dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
			dp[i+1][j+1]=max(dp[i+1][j+1],dp[idx][j]+cnt);
		}
	}
	int ans=0;
	rep(i,k+1)ans=max(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}