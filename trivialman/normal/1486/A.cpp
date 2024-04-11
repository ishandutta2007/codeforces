#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 3e5 + 5;
mt19937 rng(time(0));

int T, n, k;
LL a[N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) cin >> a[i];
        a[0] = -1;
        bool flag = true;
        rep(i, 1, n) {
            if (a[i] <= a[i - 1])
                flag = false;
            a[i + 1] += a[i] - (a[i - 1] + 1), a[i] = a[i - 1] + 1;
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}