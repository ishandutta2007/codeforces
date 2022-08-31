#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define pb push_back
#define INF 100000000
#define mp make_pair

ll n,k,d,m = 1000000007;
ll dp[1001][2];
ll solve(ll val, int is){
    if (dp[val][is] != -1) return dp[val][is];
    if (val > n) return 0;
    if (val == n && is) return 1;
    ll ans = 0;
    for (int i = 1; i <= k; i++){
        if (i >= d){
            ans += solve(val+i,1);
        }
        else{
            ans += solve(val+i,is);
        }
        ans %= m;
    }
    return dp[val][is] = ans;
}

int main() {
	
	ios::sync_with_stdio(false);
    for (int i = 0; i <= 1000; i++){
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
	cin >> n >> k >> d;
    cout << solve(0,0) << endl;
}