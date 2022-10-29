#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int INF = (1 << 30) - 1;
const int N = 25;
mt19937 rng(time(0));

int T, n, a[N];

bool check(vector<int> &b) {
    int m = b.size();
    rep(mask, 0, (1 << m) - 1) {
        int sum = 0;
        rep(i, 0, m - 1) sum += (mask >> i & 1) ? b[i] : -b[i];
        if (sum == 0)
            return true;
    }
    return false;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 0, n - 1) cin >> a[i];
        //rep(i, 0, n-1) cerr << a[i] << " ";
        //cerr << endl;
        bool flag = false;
        rep(mask, 1, (1 << n) - 1) {
            vector<int> b;
            rep(i, 0, n - 1) if (mask >> i & 1) b.PB(a[i]);
            if (check(b)) {
                flag = true;
                break;
            }
        }
        printf(flag ? "YES\n" : "NO\n");
    }
    return 0;
}