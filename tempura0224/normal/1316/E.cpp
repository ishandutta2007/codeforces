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
constexpr int inf=1e9+7;
constexpr ll longinf=1LL<<60 ;
constexpr ll mod=1e9+7 ;


ll dp[101010][128];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,p,t;
	cin>>n>>p>>t;
	vector<int> a(n);
	rep(i,n)cin>>a[i];
	vector<vector<int>> s(n,vector<int>(p));
	rep(i,n)rep(j,p)cin>>s[i][j];
	vector<int> ord(n);
	rep(i,n)ord[i]=i;
	sort(ord.begin(),ord.end(),[&](int x,int y){
		return a[x]>a[y];
	});
	rep(i,n)rep(j,1<<p)dp[i][j]=-longinf;
	dp[0][0]=0;
	rep(i,n){
		int idx = ord[i];
		rep(j,1<<p){
			if(dp[i][j]==-longinf)continue;
			int c = __builtin_popcount(j);
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			rep(k,p){
				if((j>>k)&1)continue;
				ll add = s[idx][k] ;
				if(i-c<t)add += a[ord[t+c]]-a[idx];
				dp[i+1][j+(1<<k)]=max(dp[i+1][j+(1<<k)],dp[i][j]+add);
			}
		}
	}
	ll ans = dp[n][(1<<p)-1];
	rep(i,t)ans += a[ord[i]];
	cout<<ans<<endl;
	return 0;
}