#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
//typedef __int128 LLL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 2e5 + 5, MAX = 1e6;
mt19937 rng(time(0));

int T, n, e;
int a[N << 1];
bool p[MAX + 5];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    rep(i, 2, MAX) p[i] = true;
    p[1] = false;
    rep(i, 2, sqrt(MAX)) if (p[i]) {
        for (int j = i * i; j <= MAX; j += i)
            p[j] = false;
    }

    cin >> T;
    while (T--) {
        cin >> n >> e;
        rep(i, 1, n) cin >> a[i];
        rep(i, n + 1, n + e) a[i] = 4;

        LL res = 0;
        rep(i, 1, e) {
            int cnt = 0, cnt_last = 0;
            bool p1 = false;
            for (int j = i; j <= n + e; j += e) {
                if (a[j] == 1) {
                    cnt++;
                } else {
                    if (p1) {
                        res += cnt;                  // begin with p
                        res += 1ll * cnt * cnt_last; //middle with p
                    }

                    if (p[a[j]]) {
                        p1 = true;
                        res += cnt; // end with p
                    } else {
                        p1 = false;
                    }
                    cnt_last = cnt, cnt = 0;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}