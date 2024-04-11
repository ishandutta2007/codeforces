#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int INF = 1e6;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n;
char s[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> (s + 1);
        n = strlen(s + 1);
        bool flag = s[1] == 'A' && s[n] == 'B';
        int cnt = 0;
        rep(i, 1, n) {
            cnt += s[i] == 'A' ? 1 : -1;
            if (cnt < 0)
                flag = false;
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}