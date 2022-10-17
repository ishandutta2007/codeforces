#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

bool cmp(int a, int b) {
    int a2 = a, b2 = b;
    while (a2 % 2 == 0) {
        a2 /= 2;
    }
    while (b2 % 2 == 0) {
        b2 /= 2;
    }
    return a2 < b2 || (a2 == b2 && a < b);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << 2 << '\n';
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        sort(a.begin(), a.end(), cmp);
        for (auto it : a) {
            cout << it << ' ';
        }
        cout << '\n';
    }
    return 0;
}