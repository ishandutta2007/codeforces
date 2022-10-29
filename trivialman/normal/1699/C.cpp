#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 1e9 + 7;
const LL INF = 9e18;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n;
int a[N], id[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        set<int> st;
        rep(i, 1, n) cin >> a[i], id[a[i]] = i, st.insert(a[i]);
        if (n == 1) {
            cout << "1\n";
            continue;
        }

        int l = id[0], r = id[1];
        if (l > r)
            swap(l, r);
        int num = 2, k = r - l - 1;
        rep(i, l, r) st.erase(a[i]);
        LL ans = 1;
        while (st.size()) {
            int x = *st.begin(), pos = id[x];
            for (; num < x; num++, k--)
                ans = ans * k % P;
            num++, k += pos < l ? l - pos - 1 : pos - r - 1;
            rep(i, pos, l - 1) st.erase(a[i]);
            rep(i, r + 1, pos) st.erase(a[i]);
            l = min(l, pos), r = max(r, pos);
        }
        for (; num < n; num++, k--)
            ans = ans * k % P;
        cout << ans << "\n";
    }
    return 0;
}