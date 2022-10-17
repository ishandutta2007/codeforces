#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct fenwick {
    vector<T> a;
    int n;
    fenwick(int n): n(n), a(n, -1) {}
    void add(int x, T v) {
        assert(0 <= x && x < n);
        for(int i = x + 1; i <= n; i += i & -i) a[i - 1] = max(a[i - 1], v);
    }
    T qry(int x) {
        T ret = -1;
        for(int i = min(x + 1, n); i > 0; i -= i & -i) ret = max(ret, a[i - 1]);
        return ret;
    }
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<vector<int>> sum(n + 1, vector<int>(3));
        for(int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i];
            sum[i + 1][s[i] - 'a'] += 1;
        }
        int ans = -1;
        // sum[r + 1][2] - sum[r + 1][0] < sum[l][2] - sum[l][0]
        auto chk = [&](int l, int r) {
            if(sum[r + 1][2] - sum[l][2] < sum[r + 1][0] - sum[l][0]
               && sum[r + 1][1] - sum[l][1] < sum[r + 1][0] - sum[l][0]
               && sum[r + 1][0] - sum[l][0] > 1) {
                int len = r - l + 1;
                if(ans == -1) ans = len;
                else ans = min(ans, len);
            }
        };
        fenwick<int> f1(2 * n + 1), f2(2 * n + 1);
        int j = 0;
        for(int i = 0; i < n; ++i) {
            while(j < n && sum[i + 1][0] - sum[j][0] > 1) {
                f1.add(n - (sum[j][2] - sum[j][0]), j);
                f2.add(n - (sum[j][1] - sum[j][0]), j);
                ++j;
            }
            int p1 = f1.qry(n - (sum[i + 1][2] - sum[i + 1][0]) - 1);
            int p2 = f2.qry(n - (sum[i + 1][1] - sum[i + 1][0]) - 1);
            if(p1 != -1) chk(p1, i);
            if(p2 != -1) chk(p2, i);
        }
        cout << ans << '\n';
    }
}