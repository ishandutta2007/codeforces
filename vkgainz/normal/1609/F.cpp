#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define all(c) ((c).begin()), ((c).end())

int eval(long long x, long long y) {
    return __builtin_popcountll(x)
        == __builtin_popcountll(y);
}

long long solve(int l, int r, vector<long long> &a) {
    if (l == r) {
        return 1;
    } 
    if (l > r) {
        return 0;
    }
    int m = (l + r) / 2;
    vector<long long> pmin(m - l + 1), pmax(m - l + 1);
    vector<int> pwork(m - l + 1);
    pmin[m - l] = a[m], pmax[m - l] = a[m];
    pwork[m - l] = eval(pmin[m - l], pmax[m - l]);
    for (int i = m - 1; i >= l; i--) {
        pmin[i - l] = min(pmin[i - l + 1], a[i]);
        pmax[i - l] = max(pmax[i - l + 1], a[i]);
        pwork[i - l] = eval(pmin[i - l], pmax[i - l])
            + pwork[i - l + 1];
    }
    long long rmin = 1e18, rmax = 0LL;
    int ptrmin = m - l, ptrmax = m - l;
    long long add = 0LL;
    vector<int> flmin(60), flmax(60);
    vector<int> frmin(60), frmax(60);
    for (int i = m + 1; i <= r; i++) {
        rmin = min(rmin, a[i]);
        rmax = max(rmax, a[i]);
        while (ptrmin >= 0 && pmin[ptrmin] > rmin) {
            ++flmin[__builtin_popcountll(pmin[ptrmin])];
            ++flmax[__builtin_popcountll(pmax[ptrmin])];
            --ptrmin;
        }
        while (ptrmax >= 0 && pmax[ptrmax] < rmax) {
            ++frmin[__builtin_popcountll(pmin[ptrmax])];
            ++frmax[__builtin_popcountll(pmax[ptrmax])];
            --ptrmax;
        }
        if (min(ptrmin, ptrmax) >= 0) {
            add += pwork[0];
            if (min(ptrmin, ptrmax) < m - l) {
                add -= pwork[min(ptrmin, ptrmax) + 1];
            }
        }
        if (eval(rmin, rmax)) {
            add += m - l - max(ptrmin, ptrmax);
        }
        if (ptrmin < ptrmax) {
            int look = __builtin_popcountll(rmin);
            add += flmax[look] - frmax[look];
        } else if (ptrmax < ptrmin) {
            int look = __builtin_popcountll(rmax);
            add += frmin[look] - flmin[look];
        }
    }
    long long x = solve(l, m, a), y = solve(m + 1, r, a);
    return x + y + add;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(0, n - 1, a) << "\n";
}