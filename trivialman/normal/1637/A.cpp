#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n, k;
string s, t;

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        int x = 0, lastx = 0;
        bool flag = true;
        rep(i, 1, n) {
            lastx = x;
            scanf("%d", &x);
            if (x < lastx)
                flag = false;
        }
        printf(!flag ? "YES\n" : "NO\n");
    }
    return 0;
}