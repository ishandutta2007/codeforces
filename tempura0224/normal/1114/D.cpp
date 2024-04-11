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
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int dp[5050][5050];
int main(){
	int n;
	cin>>n;
	vector<int> a;
	int pre=-1;
	rep(i,n){
		int x;
		cin>>x;
		if(x!=pre){
			a.push_back(x);
			pre=x;
		}
	}
	n=a.size();
	vector<int> b=a;
	reverse(b.begin(),b.end());
	rep(i,n)rep(j,n){
		dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+(a[i]==b[j]));
        dp[i+1][j+1]=max(dp[i+1][j+1],dp[i+1][j]);
        dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j+1]);
	}
	int ma=0;
	rep(i,n+1){
		ma=max(dp[i][n-i],ma);
	}
	cout<<n-1-ma<<endl;
	return 0;
}