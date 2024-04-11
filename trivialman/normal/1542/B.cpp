#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int N = 105;

int T;
LL n, a, b;

int main() {
    cin >> T;
    while (T--) {
        scanf("%lld%lld%lld", &n, &a, &b);
        bool ans;
        if (a == 1) {
            ans = (n - 1) % b == 0 ? true : false;
        } else {
            ans = false;
            LL x = 1;
            while (x <= n) {
                if ((n - x) % b == 0)
                    ans = true;
                x *= a;
            }
        }
        printf(ans ? "YES\n" : "NO\n");
    }
    return 0;
}