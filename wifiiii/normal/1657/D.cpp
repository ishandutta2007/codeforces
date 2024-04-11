#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    int n, c;
    cin >> n >> c;
    vector<ll> best(c + 1);
    for(int i = 0; i < n; ++i) {
        int c, a, b;
        cin >> c >> a >> b;
        best[c] = max(best[c], 1ll * a * b);
    }
    vector<pair<ll,int>> a;
    for(int i = 1; i <= c; ++i) {
        if(best[i] == 0) continue;
        for(int j = 1; j * i <= c; ++j) {
            best[i * j] = max(best[i * j], best[i] * j);
        }
    }
    for(int i = 1; i <= c; ++i) best[i] = max(best[i], best[i - 1]);
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        x *= y;
        int p = upper_bound(best.begin(), best.end(), x) - best.begin();
        if(p == c + 1) cout << -1 << ' ';
        else cout << p << ' ';
    }
    cout << '\n';
}