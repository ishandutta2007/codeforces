#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    auto ask = [&](int x) {
        cout << "? " << x << endl;
        int ret;
        cin >> ret;
        return ret;
    };
    int lo = n - 1 + n, hi = n - 1 + 2000 * n;
    while(lo < hi) {
        int m = (lo + hi) / 2;
        if(ask(m) == 1) hi = m;
        else lo = m + 1;
    }
    int ans = 2e9, tot = lo;
    for(int i = 1; i <= n; ++i) {
        int p = ask(tot / i);
        if(p) ans = min(ans, p * (tot / i));
    }
    cout << "! " << ans << endl;
}