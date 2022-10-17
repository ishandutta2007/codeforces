#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n = 200;
    cout << "? " << n * n << endl;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << i << " " << j << " ";
        }
    }
    cout << endl;
    int tot;
    cin >> tot;
    int lo = 0, hi = 31 - __builtin_clz(n);
    vector<int> ans(hi + 2, -1);
    ans.back() = 0;
    while(lo < hi) {
        int mid = (lo + hi + 1) / 2, step = 1 << mid;
        cout << "? " << (n / step) * n << endl;
        for(int i = step; i <= n; i += step) {
            for(int j = 1; j <= n; ++j) {
                cout << i << " " << j << " " << endl;
            }
        }
        int res;
        cin >> res;
        ans[mid] = res;
        if(step * ans[mid] == tot) lo = mid;
        else hi = mid - 1;
    }
    assert(ans[lo + 1] != -1);
    int b = abs(2 * ans[lo + 1] - tot / (1 << lo)) - 1;
    int a = tot / (b + 1) - 1;
    cout << "! " << 2 * (a + b) << endl;
}