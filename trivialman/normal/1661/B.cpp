#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e9 + 1;
const int N = 32770;
mt19937 rng(time(0));

int T, x, f[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        vector<int> tmp;
        tmp.PB((x + 32767) % 32768);
        if (x % 2 == 0)
            tmp.PB(x / 2), tmp.PB((x + 32768) / 2);
        for (auto y : tmp)
            if (y && !f[y])
                f[y] = f[x] + 1, Q.push(y);
    }

    cin >> T;
    while (T--) {
        cin >> x;
        cout << f[x] << " ";
    }
    return 0;
}