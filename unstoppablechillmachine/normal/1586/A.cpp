#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

bool good(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return true;
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for (auto &x : a) {
            cin >> x;
            sum += x;
        }
        if (good(sum)) {
            cout << n << '\n';
            for (int i = 1; i <= n; i++) {
                cout << i << ' ';
            }
            cout << '\n';
        } else {
            for (int i = 0; i < n; i++) {
                if (good(sum - a[i])) {
                    cout << n - 1 << '\n';
                    for (int j = 0; j < n; j++) {
                        if (i != j) {
                            cout << j + 1 << ' ';
                        }
                    }
                    cout << '\n';
                    break;
                }
            }
        }
    }
}