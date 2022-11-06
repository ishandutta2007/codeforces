#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "input";

typedef long long base;

base n;

base f(base a) {
    base p = pow(a, 1.0 / 3);
    return p;
}

base ans1 = 1, ans2 = 1;

pair <int, int> ans[1000001];

pair <int, base> res(base m) {
    if (m == 0) return {0, 0};
    if (m <= 1e6 && ans[m] != make_pair(0, 0)) {
        return ans[m];
    }
    int p = f(m);
    pair <int, base> Pr = {0, 0};
    Out(i, p + 1, max(p - 9, 1)) {
        base j = i;
        base S = (j + 1) * (j + 1) * (j + 1) - 1;
        base L = j * j * j;
        For(k, 1, min(S / L, m / L) + 1) {
            auto ans = res(min(S, m) - L * k);
            ++ans.x; ans.y += L * k;
            Pr = max(Pr, ans);
        }
    }
    if (m <= 1e6) ans[m] = Pr;
    return Pr;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    auto ans = res(n);
    cout << ans.x << ' ' << ans.y << endl;
}