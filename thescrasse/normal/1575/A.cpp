#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 1000010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
pair<string, ll> s[maxn];

bool cmp(pair<string, ll> a, pair<string, ll> b) {
    ll i;
    for (i = 0; i < m; i++) {
        if (a.first[i] == b.first[i]) continue;
        return ((a.first[i] < b.first[i]) ^ (i % 2));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> s[i].first; s[i].second = i;
    }

    sort(s + 1, s + n + 1, cmp);

    for (i = 1; i <= n; i++) cout << s[i].second << ' ';
    cout << nl;

    return 0;
}