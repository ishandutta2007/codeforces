#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

bool p[1000001];

int main() {
    memset(p, 1, sizeof(p));
    for (int i = 2; i <= 1000000; i++) {
        if (p[i]) {
            for (int j = i; j <= 1000000 / i; j++) {
                p[i * j] = 0;
            }
        }
    }
    int t; cin >> t;
    while (t--) {
        int n, e; cin >> n >> e;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                a[i] = 0;
            } else if (p[a[i]]) {
                a[i] = 1;
            } else {
                a[i] = 2;
            }
        }
        vector<int> l(n), r(n);
        long long ans = 0LL;
        for (int i = n - 1; i >= 0; i--) {
            l[i] = r[i] = i + e;
            if (a[i] == 0) {
                if (i + e < n) {
                    l[i] = l[i + e];
                    r[i] = r[i + e];
                }
            } else if (a[i] == 1) {
                l[i] = i;
                if (i + e < n) {
                    r[i] = l[i + e];
                }
            } else {
                l[i] = r[i] = i;
            }
            ans += (r[i] - l[i]) / e;
            if (a[i] == 1) {
                --ans;
            }
        }
        cout << ans << "\n";
    }
}