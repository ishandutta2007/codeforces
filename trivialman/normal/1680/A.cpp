#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 25;
mt19937 rng(time(0));

int T, l1, r1, l2, r2;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> l1 >> r1 >> l2 >> r2;
        if (l1 > l2)
            swap(l1, l2), swap(r1, r2);
        int ans1 = l1 + l2, ans2 = r1 >= l2 ? l2 : 1000;
        cout << min(ans1, ans2) << "\n";
    }
    return 0;
}