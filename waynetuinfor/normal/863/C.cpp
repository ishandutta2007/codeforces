#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6;
int aa[4][4], bb[4][4];
map<pair<int, int>, int> m;
int sa[maxn], sb[maxn];

int win(int a, int b) {
    if (a == b) return 0;
    if (a == 1 && b == 3) return 1;
    if (a == 2 && b == 1) return 1;
    if (a == 3 && b == 2) return 1;
    return 0;
} 

int32_t main() {
    long long k; int a, b; cin >> k >> a >> b;
    for (int i = 1; i <= 3; ++i) for (int j = 1; j <= 3; ++j) cin >> aa[i][j];
    for (int i = 1; i <= 3; ++i) for (int j = 1; j <= 3; ++j) cin >> bb[i][j];
    int rnd = 1;
    while (rnd <= k) {
        if (m.count(make_pair(a, b))) {
            int oc = m[make_pair(a, b)];
            k -= oc - 1;
            long long pa = sa[oc - 1], pb = sb[oc - 1];
            long long t = k / (rnd - oc);
            pa += (sa[rnd - 1] - sa[oc - 1]) * t;
            pb += (sb[rnd - 1] - sb[oc - 1]) * t;
            int ind = oc;
            int rm = k % (rnd - oc);
            while (rm--) {
                pa += sa[ind] - sa[ind - 1];
                pb += sb[ind] - sb[ind - 1];
                ++ind;
            }
            cout << pa << ' ' << pb << endl;
            return 0;
        }   
        m[make_pair(a, b)] = rnd;
        sa[rnd] = sa[rnd - 1] + win(a, b);
        sb[rnd] = sb[rnd - 1] + win(b, a);
        int ta = a, tb = b;
        a = aa[ta][tb]; b = bb[ta][tb];
        ++rnd;
    }
    cout << sa[k] << ' ' << sb[k] << endl;
    return 0;
}