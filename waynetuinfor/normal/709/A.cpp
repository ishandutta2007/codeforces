#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

int main() {
    int n, b, d; cin >> n >> b >> d;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ind = 0, ans = 0;
    while (ind < n) {
        int tot = 0;
        while (ind < n) {
            if (a[ind] <= b) {
                tot += a[ind];
                ++ind;
                if (tot > d) break;
            } else ++ind;
        }
        if (tot > d) ++ans;
    }
    cout << ans << endl;
    return 0;
}