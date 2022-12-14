#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod=220000607;
const int N=1e6+10;

int n;
ll dp[N][3];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    dp[0][0]=dp[0][1]=-inf;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        dp[i][0]=max(dp[i-1][0],dp[i-1][2]-a);
        dp[i][1]=max(dp[i-1][1],dp[i-1][2]+a);
        dp[i][2]=max(max(dp[i-1][0]+a,dp[i-1][1]-a),dp[i-1][2]);
    }
    cout<<dp[n][2];
	return 0;
}