#include <bits/stdc++.h>
using namespace std;

typedef long long int64_t;
const long long inf = 2e18 + 1;

int main() {
    long long k, l, r; cin >> l >> r >> k;
    long long ret = 1LL;
    int cnt = 0;
    while (ret < inf) {
        if (ret >= l && ret <= r) cout << ret << ' ', ++cnt;
        if (ret > inf / k) break;
        ret *= k;
    }
    if (cnt == 0) cout << "-1" << endl;
    return 0;
}