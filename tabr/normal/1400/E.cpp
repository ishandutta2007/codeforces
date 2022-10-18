#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int f(vector<int> a) {
    int n = a.size();
    int mn = *min_element(a.begin(), a.end());
    int res = mn;
    vector<int> b(1, -1);
    for (int i = 0; i < n; i++) {
        if (a[i] == mn) {
            b.emplace_back(i);
        }
    }
    b.emplace_back(n);
    for (int i = 1; i < b.size(); i++) {
        if (b[i - 1] + 1 == b[i]) {
            continue;
        }
        vector<int> c;
        for (int j = b[i - 1] + 1; j < b[i]; j++) {
            c.emplace_back(a[j] - mn);
        }
        res += f(c);
    }
    return min(res, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << f(a) << '\n';
    return 0;
}