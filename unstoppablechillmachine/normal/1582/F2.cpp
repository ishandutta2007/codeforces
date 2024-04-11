#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int M = 1 << 13;
vector<int> can[M];
int min_pushed[M];
bool ok[M];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 0; i < M; i++) {
        can[i] = {0};
        min_pushed[i] = M;
    }
    ok[0] = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (auto it : can[x]) {
            int value = x ^ it;
            ok[value] = 1;
            for (int i = x + 1; i < min_pushed[value]; i++) {
                can[i].pb(value);
            }
            min_pushed[value] = min(min_pushed[value], x);
        }
        can[x] = {};
    }
    int cnt = accumulate(ok, ok + M, 0);
    cout << cnt << '\n';
    for (int i = 0; i < M; i++) {
        if (ok[i]) {
            cout << i << ' ';
        }
    }
    cout << '\n';
}