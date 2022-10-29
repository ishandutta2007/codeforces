#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 998244353;
const LL INF = 5e15 + 5;
const int N = 305;
mt19937 rng(time(0));

int T, n, k;

int ask(int x) {
    int res;
    cout << "? " << x << endl;
    cin >> res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int l = 1, r = 5e6, len;
    while (l <= r) {
        int w = l + r >> 1;
        int h = ask(w);
        if (h == 0 || h > 1)
            l = w + 1;
        else
            len = w - n + 1, r = w - 1;
    }
    int ans = len + n - 1;
    rep(i, 2, n) {
        int h = ask((ans - 1) / i);
        if (h == i)
            ans = (ans - 1) / i * i;
    }
    cout << "! " << ans << endl;
    return 0;
}