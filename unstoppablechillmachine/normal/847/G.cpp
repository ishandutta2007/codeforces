//GLEBAS
#include <bits/stdc++.h>

using namespace std;

#define TASK "cifrul"

typedef long long ll;
typedef pair<ll, ll> par;

#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define pw(x) (1ll << (x))

const ll INF = ll(1e18);
const ll MOD = ll(1e9) + 7;

int source() {
    ll n;
    cin >> n;
    vector<ll> ans(7);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 7; ++j) {
            ans[j] += s[j] - '0';
        }
    }
    ll anss = 0;
    for (int i = 0; i < 7; ++i) anss = max(anss, ans[i]);
    cout << anss;
    return 0;
}

int main() {
#ifdef OLYMP
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    source();

    return 0;
}