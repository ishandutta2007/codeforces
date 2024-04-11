#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{ _
    int n, m; cin >> n >> m;

    vector<ll> dp(1000000);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;

    ll mod = 1000000000 + 7;

    for (int i = 5; i <= max(m, n); ++i)
        dp[i] = (dp[i-2] + 2 * dp[i-3] + dp[i-4]) % mod;

    cout << (2 * (dp[n] + dp[m] - 1)) % mod << endl;

    exit(0);
}