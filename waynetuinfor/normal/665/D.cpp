#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, maxv = 2e6 + 10;
int a[maxn];
bool p[maxv];

void init() {
    vector<int> prime;
    for (int i = 2; i < maxv; ++i) {
        if (!p[i]) prime.push_back(i);
        for (int j = 0; i * prime[j] < maxv; ++j) {
            p[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, cnt = 0; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i], cnt += (a[i] == 1);
    init();
    if (cnt > 1) {
        for (int i = 0; i < n; ++i) if (a[i] != 1 && !p[a[i] + 1]) {
            cout << cnt + 1 << endl;
            while (cnt--) cout << 1 << ' '; cout << a[i] << endl;
            return 0;
        }
        cout << cnt << endl;
        while (cnt--) cout << 1 << ' '; cout << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) if (!p[a[i] + a[j]]) {
                cout << 2 << endl;
                cout << a[i] << ' ' << a[j] << endl;
                return 0;
            }
        }
        cout << 1 << endl;
        cout << a[0] << endl;
    }
    return 0;
}