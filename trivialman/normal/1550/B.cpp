#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int N = 105;

int T, n, a, b;
char s[N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> a >> b;
        cin >> (s + 1);
        if (b >= 0) {
            cout << (a + b) * n << endl;
        } else {
            int cnt = 0;
            rep(i, 2, n) cnt += (s[i] != s[i - 1]);
            cnt = (cnt + 3) / 2;
            cout << a * n + b * cnt << endl;
        }
    }
    return 0;
}