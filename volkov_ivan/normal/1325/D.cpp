#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>
#define int long long

using namespace std;

const int K = 62;
int cnt[K + 1];

signed main() {
    //cout << (1ll << (K - 1)) << endl;
    int xr, summ;
    cin >> xr >> summ;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < K; i++) {
        int sm = min(((1ll << i) & summ), 1ll);
        int x = min(((1ll << i) & xr), 1ll);
        //if (i > 1) cout << cnt[i] << ' ' << cnt[i - 1] << ' ' << cnt[i - 2] << endl;
        if (sm == 0 && x == 1) {
            if (i == 0) {
                cout << -1 << endl;
                return 0;
            }
            if (cnt[i] == -1) {
                cnt[i] += 2;
                cnt[i + 1]--;
            } else {
                cnt[i - 1] += 2;
                cnt[i]++;
                cnt[i + 1]--;
            }
        }
        if (sm == 1 && x == 0) {
            if (i == 0) {
                cout << -1 << endl;
                return 0;
            }
            if (cnt[i] != 0) {
                cnt[i] = 0;
                continue;
            }
            else {
                cnt[i - 1] += 2;
            }
        }
        if (sm == 0 && x == 0) {
            if (cnt[i] == 0) continue;
            cnt[i - 1] += 2;
            cnt[i]++;
            cnt[i + 1]--;
        }
        if (sm == 1 && x == 1) {
            cnt[i]++;
            if (cnt[i] == 0) {
                cnt[i]++;
                cnt[i - 1] += 2;
                cnt[i + 1]--;
            }
        }
    }
    if (cnt[K] == -1) {
        cout << -1 << endl;
        return 0;
    }
    int maxi = -1;
    for (int i = 0; i < K; i++) maxi = max(maxi, cnt[i]);
    vector <int> res(maxi, 0);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            res[j] += (1ll << i);
        }
    }
    //assert(res.size() <= 3);
    int s = 0, xx = 0;
    for (int elem : res) {
        s += elem;
        xx ^= elem;
    }
    cout << res.size() << endl;
    for (int elem : res) cout << elem << ' ';
    cout << endl;
    assert(s == summ && xx == xr);
}