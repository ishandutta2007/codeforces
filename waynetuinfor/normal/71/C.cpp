#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x == 0) a.push_back(i);
    }
    for (int i = 1; i <= n; ++i) if (n % i == 0 && n / i >= 3) {
        memset(v, false, sizeof(v));
        for (int j : a) v[j % i] = true;
        for (int j = 0; j < i; ++j) if (!v[j]) return cout << "YES" << endl, 0;
    }
    cout << "NO" << endl;
    return 0;
}