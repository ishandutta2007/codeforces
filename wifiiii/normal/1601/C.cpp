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
// 0 <= x < n
ll calc(vector<int> a) {
    int n = a.size();
    int mx = *max_element(a.begin(), a.end()) + 1;
    fenwick<int> fen(mx + 1);
    ll ans = 0;
    for(int i : a) {
        ans += fen.qry(mx) - fen.qry(i);
        fen.add(i, 1);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < m; ++i) cin >> b[i];
        sort(b.begin(), b.end());
        vector<int> aa;
        for(int i : a) aa.push_back(i);
        for(int i : b) aa.push_back(i);
        sort(aa.begin(), aa.end());
        aa.resize(unique(aa.begin(), aa.end()) - aa.begin());
        auto f = [&](int x) {return lower_bound(aa.begin(), aa.end(), x) - aa.begin();};
        for(int &i : a) i = f(i);
        for(int &i : b) i = f(i);
        ll ans = calc(a);
        priority_queue<int> q;
        q.push(0);
        for(int i : a) {
            int l = lower_bound(b.begin(), b.end(), i) - b.begin();
            int r = upper_bound(b.begin(), b.end(), i) - b.begin();
            if(r < q.top()) {
                ans += q.top() - r;
            }
            q.push(l);
            q.push(r);
            q.pop();
        }
        cout << ans << '\n';
    }
}