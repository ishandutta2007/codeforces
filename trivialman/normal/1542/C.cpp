#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL P = 1e9 + 7;
const int N = 505;

int T;
LL n;

int factor(int x) {
    int p = x;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) {
            p = i;
            break;
        }
    while (x % p == 0)
        x /= p;
    return x == 1 ? p : 1;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        LL mul = 1, ans = 0, i = 2;
        while (mul <= n) {
            (ans += (n / mul - n / mul / factor(i)) * i) %= P;
            mul *= factor(i), i++;
        }
        cout << ans << endl;
    }
    return 0;
}