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

mt19937 rng(7);

#define rr uniform_int_distribution<ll>

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> s >> n;
    if ((s == "ABC" && n >= 2000) || (s == "ARC" && n >= 2800) || (s == "AGC" && n <= 1199)) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
    }

    return 0;
}