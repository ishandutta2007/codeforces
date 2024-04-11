#include <bits/stdc++.h>

#define F first
#define S second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

const int N = 2e5+7;

int n, m, ans;
set<int, greater<int>> s[N];

int alive(int i) {
    return (s[i].empty() || *s[i].begin() < i) ? 1 : 0;
}

void add(int a, int b) {
    ans -= alive(a) + alive(b);
    s[a].insert(b);
    s[b].insert(a);
    ans += alive(a) + alive(b);
}

void del(int a, int b) {
    ans -= alive(a) + alive(b);
    s[a].erase(b);
    s[b].erase(a);
    ans += alive(a) + alive(b);
}

void solve() {
    int n, m; cin >> n >> m;
    ans = n;
    while (m--) {
        int a, b; cin >> a >> b;
        add(a-1, b-1);
    }

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int a, b; cin >> a >> b;
            add(a-1, b-1);
        }
        if (t == 2) {
            int a, b; cin >> a >> b;
            del(a-1, b-1);
        }
        if (t == 3) {
            cout << ans << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t; 
    while(t--) solve();
}