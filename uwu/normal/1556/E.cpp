#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vector<ll> a(N + 1);
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        a[i] -= x;
    }
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        a[i] += x;
    }
    for (int i = 1; i <= N; ++i){
        a[i] += a[i - 1];
    }

    const int L = 16;
    vector<vector<ll>> mn(N + 1, vector<ll>(L + 1));
    vector<vector<ll>> mx(N + 1, vector<ll>(L + 1));
    for (int i = 1; i <= N; ++i){
        mn[i][0] = mx[i][0] = a[i];
    }
    for (int b = 1; b <= L; ++b){
        for (int i = 1; i + (1 << b) - 1 <= N; ++i){
            mn[i][b] = min(mn[i][b - 1], mn[i + (1 << (b - 1))][b - 1]);
            mx[i][b] = max(mx[i][b - 1], mx[i + (1 << (b - 1))][b - 1]);
        }
    }

    while (Q--){
        int l, r; cin >> l >> r;
        int b = __lg(r - l + 1);
        ll lo = min(mn[l][b], mn[r - (1 << b) + 1][b]);
        if (a[l - 1] != a[r] || lo < a[l - 1]){
            cout << -1 << '\n';
        }
        else{
            ll hi = max(mx[l][b], mx[r - (1 << b) + 1][b]);
            cout << hi - a[l - 1] << '\n';
        }
    }
}