#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    int a;
    int tot = 0, l = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        l +=  a;
        tot += min(l, 8);
        l -= min(l, 8);
        if (tot >= k) return cout << i + 1 << endl, 0;
    } 
    cout << "-1" << endl;
    return 0;
}