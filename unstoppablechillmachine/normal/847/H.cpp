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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<ll> pref(n, 0), prefa = a;
    for (int i = 1; i < n; ++i) {
        if (prefa[i] > prefa[i - 1]) {
            pref[i] = pref[i - 1];
            continue;
        }
        pref[i] = pref[i - 1] + (prefa[i - 1] + 1 - prefa[i]);
        prefa[i] += (prefa[i - 1] + 1 - prefa[i]);
    }
    vector<ll> suff(n, 0), suffa = a;
    for (int i = n - 2; i >= 0; --i) {
        if (suffa[i] > suffa[i + 1]) {
            suff[i] = suff[i + 1];
            continue;
        }
        suff[i] = suff[i + 1] + (suffa[i + 1] + 1 - suffa[i]);
        suffa[i] += (suffa[i + 1] + 1 - suffa[i]);
    }
    ll ans = INF;
    for (int i = 0; i < n; ++i) {
        if (!i) {
            ans = min(ans, suff[i]);
            continue;
        }
        if (i == n - 1) {
            ans = min(ans, pref[i]);
            continue;
        }
        ll curans = pref[i - 1] + suff[i + 1];
        curans += max(0ll, max(prefa[i - 1], suffa[i + 1]) + 1 - a[i]);
        ans = min(curans, ans);
    }
    cout << ans;
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