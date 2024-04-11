#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e9 + 1;
const int N = 505;
mt19937 rng(time(0));

struct dat {
    int val, id;
} a[N];
int T, n, m, b[N];
char s[N];

int ask(char s[]) {
    int x;
    cout << "? " << (s + 1) << endl;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(q, 1, m) {
        rep(i, 1, m) s[i] = i == q ? '1' : '0';
        s[m + 1] = 0;
        a[q] = {ask(s), q};
    }
    sort(a + 1, a + m + 1, [](dat x, dat y) { return x.val < y.val; });

    int ans = 0;
    rep(q, 1, m) {
        rep(i, 1, m) s[i] = '0';
        rep(i, 1, q) s[a[i].id] = '1';
        s[m + 1] = 0;
        b[q] = ask(s);
        ans += b[q] == b[q - 1] + a[q].val ? a[q].val : 0;
    }
    cout << "! " << ans << endl;
    return 0;
}