#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 1005;
mt19937 rng(time(0));

int T, n, m;
char s[N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m >> (s + 1);
        s[0] = s[n + 1] = 0;
        while (m--) {
            vector<int> tmp;
            rep(i, 1, n) if (s[i] == '0' && ((s[i - 1] == '1') + (s[i + 1] == '1') == 1)) tmp.PB(i);
            if (!tmp.size())
                break;
            for (auto x : tmp)
                s[x] = '1';
        }
        cout << (s + 1) << endl;
    }
    return 0;
}