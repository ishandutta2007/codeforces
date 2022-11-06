#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10;
vector<int> vec;

struct fenwick {
    int arr[maxn];
    inline int lowbit(int x){ return x & -x;}
    void add(int x, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) arr[i] += v;
    }
    int qry(int x) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret += arr[i];
        return ret;
    }
} bit;
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int last = 0, sum = 0;
    vec.push_back(0);
    int sz = 1;
    while (n--) {
        int t; cin >> t;
        if (t == 1) {
            int x, a; cin >> x >> a;
            bit.add(1, a); bit.add(x + 1, -a);
            sum += x * a;
        }
        if (t == 2) {
            int k; cin >> k;
            // vec.push_back(k);
            // sum += k;
            ++sz;
            sum += k;
            bit.add(sz, k); bit.add(sz + 1, -k);
        }
        if (t == 3) {
                int k = bit.qry(sz);
            sum -= k;
            bit.add(sz, -k); bit.add(sz + 1, k);
            --sz;

        }
        cout << fixed << setprecision(20) << (long double)sum / (long double)sz << endl;
    }
    return 0;
}