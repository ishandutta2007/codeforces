#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7, M = 1e9+7, MAXN = 1 * 2e5;



int A[MAXN], C[MAXN];
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t, s, x;
    cin >> t >> s >> x;

    if(x < t) {
        cout << "NO\n";
        return 0;
    }

    x -= t;
    if(x == 0) {
        cout << "YEs\n";
        return 0;
    }
    x -= s;
    if(x >= 0 && x % s <= 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}