#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e9 + 1;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n, last[30];
char s[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> (s + 1);
        n = strlen(s + 1);
        rep(i, 0, 25) last[i] = n + 1;
        rrep(i, n, 1) if (last[s[i] - 'a'] == n + 1) last[s[i] - 'a'] = i;
        cout << (s + (*min_element(last, last + 26))) << "\n";
    }
    return 0;
}