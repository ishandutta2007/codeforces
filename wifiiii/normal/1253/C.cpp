#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

vector<ll> solve(vector<int> a, int m) {
    int n = a.size();
    sort(a.begin(), a.end());
    vector<ll> dp(n), sum(n+1);
    for(int i = 0; i < n; ++i) sum[i+1] = sum[i] + a[i];
    for(int i = 0; i < n; ++i) {
        if(i - m >= 0) {
            dp[i] = dp[i - m] + sum[i + 1];
        } else {
            dp[i] = sum[i + 1];
        }
    }
    return dp;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<ll> ans = solve(a, m);
    for(ll i : ans) cout << i << " "; cout << endl;
}