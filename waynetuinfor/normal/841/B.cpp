#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn];
bool ok[2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    long long tot = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], tot += a[i];
    if (tot & 1) return cout << "First" << endl, 0;
    long long cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur += a[i];
        if (ok[(cur & 1) ^ 1]) return cout << "First" << endl, 0;
        ok[(cur & 1)] = true;
    }
    cout << "Second" << endl;
    return 0;
}