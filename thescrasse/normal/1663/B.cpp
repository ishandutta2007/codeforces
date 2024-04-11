#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
vector<ll> v = {1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    sort(v.begin(), v.end());
    res = (*upper_bound(v.begin(), v.end(), n));
    cout << res << nl;

    return 0;
}