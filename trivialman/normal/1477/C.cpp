#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 5005;
mt19937 rng(time(0));

int n;
LL x[N], y[N];
bool v[N];

int main() {
    cin >> n;
    int idx = 1;
    rep(i, 1, n) {
        cin >> x[i] >> y[i];
        if (x[i] < x[idx])
            idx = i;
    }

    memset(v, 0, sizeof v);
    v[idx] = true;
    cout << idx << " ";
    rep(i, 2, n) {
        LL maxdist = 0, maxi = 0;
        rep(j, 1, n) if (!v[j]) {
            LL dx = x[j] - x[idx], dy = y[j] - y[idx];
            LL dist = dx * dx + dy * dy;
            if (dist > maxdist) {
                maxdist = dist;
                maxi = j;
            }
        }
        idx = maxi;
        v[idx] = true;
        cout << idx << " ";
    }

    return 0;
}