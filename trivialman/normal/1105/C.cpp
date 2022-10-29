#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 2e5+5;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

LL dp[N][3];
int n, l, r;

int main(){
	//freopen("test.in","r",stdin);
	cin>>n>>l>>r;
	dp[0][0] = 1;
	LL m1, m2, m0;
	m0 = r/3 - (l-1)/3, m1 = (r+2)/3 - (l+1)/3, m2 = r-l+1 - m0 - m1;
	//cout<<m0<<" "<<m1<<" "<<m2<<endl;
	rep(i,1,n){
		dp[i][0] = (dp[i-1][0] * m0 % P + dp[i-1][1] * m2 % P + dp[i-1][2] * m1 % P) % P;
		dp[i][1] = (dp[i-1][0] * m1 % P + dp[i-1][1] * m0 % P + dp[i-1][2] * m2 % P) % P;
		dp[i][2] = (dp[i-1][0] * m2 % P + dp[i-1][1] * m1 % P + dp[i-1][2] * m0 % P) % P;
	}
	cout<<dp[n][0]<<endl;
	return 0;
}