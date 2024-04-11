#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n, k, pos;
int h[N];

int main() {
    cin >> T;

    rep(cas, 1, T) {
        cin >> n >> k;
        rep(i, 1, n) cin >> h[i];
        rep(q, 1, k) {
            pos = -1;
            rep(i, 1, n - 1) if (h[i] < h[i + 1]) {
                pos = i;
                h[i]++;
                break;
            }
            if (pos == -1)
                break;
        }
        cout << pos << endl;
    }
    return 0;
}