#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#define int long long

using namespace std;

const int M = 998244353;
map <pair <int, int>, int> cnt_p;

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n;
    int bad = 0;
    cin >> n;
    int cnt_f[n + 1], cnt_s[n + 1];
    memset(cnt_f, 0, sizeof(cnt_f));
    memset(cnt_s, 0, sizeof(cnt_s));
    int fact[n + 1];
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % M;
    }
    pair <int, int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        cnt_f[a[i].first]++;
        cnt_s[a[i].second]++;
        cnt_p[a[i]]++;
    }
    int bad_1 = 1, bad_2 = 1, bad_3 = 1;
    for (int i = 0; i <= n; i++) {
        bad_1 = (bad_1 * fact[cnt_f[i]]) % M;
        bad_2 = (bad_2 * fact[cnt_s[i]]) % M;
    }
    for (auto elem : cnt_p) {
        bad_3 = (bad_3 * fact[elem.second]) % M;
    }
    sort(a, a + n);
    for (int i = 1; i < n; i++) {
        if (a[i].second < a[i - 1].second) {
            bad_3 = 0;
            break;
        }
    }
    //cout << bad_1 << ' ' << bad_2 << ' ' << bad_3 << endl;
    bad = (bad_1 + bad_2 - bad_3) % M;
    if (bad < 0) bad += M;
    int res = (fact[n] - bad) % M;
    if (res < 0) res += M;
    cout << res << endl;
    return 0;
}