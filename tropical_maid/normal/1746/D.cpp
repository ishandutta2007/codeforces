#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> E[200005];
map<int, ll> V[200005];
int S[200005];

ll dp(int x, int k) {
    if (E[x].empty()) return 1ll * S[x] * k;
    auto it = V[x].find(k);
    if (it != V[x].end()) return it->second;
    int c = E[x].size();
    int d = k / c;
    vector<ll> D;
    ll sum = 1ll * S[x] * k;
    for (int i : E[x]) {
        ll value = dp(i, d);
        sum += value;
        ll diff = 0;
        if (d * c < k) diff = dp(i, d + 1) - value;
        D.push_back(diff);
    }
    sort(D.rbegin(), D.rend());
    for (int i = 0; i < k - d * c; ++i) sum += D[i];
    return V[x][k] = sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) E[i].clear(), V[i].clear();
        for (int i = 2; i <= n; ++i) {
            int p;
            cin >> p;
            E[p].push_back(i);
        }
        for (int i = 1; i <= n; ++i) cin >> S[i];
        printf("%lld\n", dp(1, k));
    }
    return 0;
}