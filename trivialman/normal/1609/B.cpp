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

int T, n, q, x;
char s[N];

bool check(int i) { return s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c'; }

int main() {
    cin >> n >> q;
    cin >> (s + 1);

    int cnt = 0;
    rep(i, 1, n - 2) if (check(i)) cnt++;

    rep(i, 1, q) {
        char ch;
        cin >> x >> ch;
        if (check(x - (s[x] - 'a')))
            cnt--;
        s[x] = ch;
        if (check(x - (ch - 'a')))
            cnt++;
        cout << cnt << endl;
    }
    return 0;
}