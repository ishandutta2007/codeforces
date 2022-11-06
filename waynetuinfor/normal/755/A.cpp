#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
bool pr[maxn * maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> p;
    for (int i = 2; i < maxn * maxn; ++i) {
        if (!pr[i]) p.push_back(i);
        for (int j = 0; i * p[j] < maxn * maxn; ++j) {
            pr[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
    int n; cin >> n;
    for (int m = 1; m <= 1000; ++m) {
        if (pr[n * m + 1]) return cout << m << '\n', 0;
    }
    return 0;
}