#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxv = 1e6, bit = 30;
int a[maxn];

void go(const vector<int>& ans) {
    cout << "YES" << endl;
    for (int i : ans) cout << i << ' ';
    cout << endl;
    exit(0);
}

int main() {
    int n, x; cin >> n >> x;
    if (n == 1) return cout << "YES\n" << x << endl, 0;
    if (n == 2 && x == 0) return cout << "NO" << endl, 0;
    if (n == 2) return cout << "YES\n" << x << ' ' << 0 << endl, 0;
    int k = 0;
    vector<int> ans;
    for (int i = 1; i <= n - 3; ++i) ans.push_back(i), k ^= i;
    int t = 1; while (t <= n) t <<= 1; t <<= 1;
    if (k == x) {
        ans.push_back(t); ans.push_back(t << 1);
        ans.push_back(t ^ (t << 1));
        go(ans);
    } else {
        ans.push_back(0);
        ans.push_back(t);
        ans.push_back(t ^ x ^ k);
        go(ans);
    }
    cout << "NO" << endl;
    return 0; 
}