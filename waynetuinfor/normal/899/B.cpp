#include <bits/stdc++.h>
using namespace std;

const int maxn = 30;
int a[maxn];
vector<int> m = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m.size(); ++i) {
        if (i + n - 1 >= m.size()) break;
        bool ok = true;
        for (int j = 0; j < n; ++j) if (a[j] != m[i + j]) ok = false;
        if (ok) return cout << "YES" << endl, 0;
    }
    cout << "NO" << endl;
}