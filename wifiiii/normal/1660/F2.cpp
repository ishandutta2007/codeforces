#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct fenwick {
    vector<T> a;
    int n;
    fenwick(int n): n(n), a(n) {}
    void add(int x, T v) {
        assert(0 <= x && x < n);
        for(int i = x + 1; i <= n; i += i & -i) a[i - 1] += v;
    }
    T qry(int x) {
        T ret = 0;
        for(int i = min(x + 1, n); i > 0; i -= i & -i) ret += a[i - 1];
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll ans = 0;
        string s;
        cin >> s;
        int cur = n;
        vector<fenwick<int>> fen(3, fenwick<int>(2 * n + 1));
        fen[cur % 3].add(cur, 1);
        for(char c : s) {
            if(c == '+') {
                --cur;
            } else {
                ++cur;
            }
            ans += fen[cur % 3].qry(cur);
            fen[cur % 3].add(cur, 1);
        }
        cout << ans << '\n';
    }
}