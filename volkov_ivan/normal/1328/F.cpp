#include <iostream>
#include <map>
#define int long long

using namespace std;

const int INF = 1e18;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    map <int, int> cnt;
    map <int, int> kek;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (++cnt[x] == k) {
            cout << 0 << endl;
            return 0;
        }
    }
    int res = INF;
    int mini, val = (*cnt.begin()).first;
    int cost = 0, c = cnt[val];
    mini = val;
    for (auto elem : cnt) {
        if (elem.first == mini) {
            kek[elem.first] = 0;
            continue;
        }
        int ncost = cost + c * (elem.first - val);
        int nc = c + elem.second;
        if (c < k && nc >= k) {
            res = min(res, ncost - (nc - k));
        }
        cost = ncost;
        c = nc;
        kek[elem.first] = cost; 
        val = elem.first;
    }
    auto uk = cnt.end();
    uk--;
    int maxi = (*uk).first;
    cost = 0, c = cnt[maxi];
    val = maxi;
    //cout << res << endl;
    for (auto x = uk;; x--) {
        auto elem = *x;
        if (elem.first == maxi) {
            continue;
        } 
        int need = c - (n - k);
        int nc = c + elem.second;
        int ncost = cost + c * (val - elem.first);
        if (need >= 0) {
            res = min(res, kek[elem.first] + ncost - (c - need));
        }
        if (c < k && nc >= k) {
            res = min(res, ncost - (nc - k));
        }
        if (x == cnt.begin()) break;
        c = nc;
        cost = ncost;
        val = elem.first;
    }
    cout << res << endl;
    return 0;
}