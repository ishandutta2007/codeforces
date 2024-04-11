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

const int A = 26 + 26 + 10;
const int B = A * A;

int cton(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 26 + 26;
    assert(false);
}

char ntoc(int x) {
    if (x < 26) return x + 'a';
    if (x < 52) return x - 26 + 'A';
    return x - 52 + '0';
}

vector<int> g[B], ans;
int deg_in[B], deg_out[B];

void euler_path(int v) {
    while (!g[v].empty()) {
        const int u = g[v].back(); g[v].pop_back();
        euler_path(u);
    }
    ans.push_back(v);
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int a = cton(s[0]), b = cton(s[1]), c = cton(s[2]);
        int v = a + b * A, u = b + c * A;
        g[u].push_back(v);
        deg_in[u]++;
        deg_out[v]++;
    }

    bool ok = true;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < B; ++i) {
        if (deg_in[i] == deg_out[i] + 1) if (cnt1++) ok = false;
        if (deg_in[i] + 1 == deg_out[i]) if (cnt2++) ok = false; 
        if (deg_in[i] > deg_out[i] + 1) ok = false;
        if (deg_out[i] > deg_in[i] + 1) ok = false;
    }

    if (ok) {
        int v0 = -1;
        for (int i = 0; i < B; ++i) if (deg_in[i] == deg_out[i] + 1) v0 = i;
        if (v0 < 0) {
            for (int i = 0; i < B; ++i) if (deg_in[i] > 0) v0 = i;
        }
        
        if (v0 >= 0) euler_path(v0);
    }

    if (ans.size() != n + 1 || !ok) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        string res(n + 2, '?');
        for (int i = 0; i <= n; ++i) {
            int a = ans[i] % A, b = ans[i] / A;
            res[i] = ntoc(a);
            res[i+1] = ntoc(b);
        }
        cout << res << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t; 
    while(t--) solve();
}