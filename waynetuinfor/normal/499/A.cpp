#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5;
struct Seg { int l, r;  } s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x; cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> s[i].l >> s[i].r;
    int ind = 0;
    long long ans = 0;
    for (int i = 1; i <= 100000 && ind < n; ) {
        cerr << "time: " << i << '\n';
        if (i == s[ind].l) {
            ans += s[ind].r - s[ind].l + 1;
            i = s[ind].r + 1;
            ++ind;
        } else if (i < s[ind].l) {
            if (i + x <= s[ind].l) i += x;
            else ++ans, ++i;
        } 
    }
    cout << ans << endl;
    return 0;
}