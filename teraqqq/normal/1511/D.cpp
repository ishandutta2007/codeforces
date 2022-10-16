#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

const int W = 26;

int n, k;
bool g[26][26];
string tmp;

void build_string(char v = 0) {

    for (int i = 0; i < k; ++i) {
        if (!g[v][i]) {
            g[v][i] = g[i][v] = true;

            tmp.push_back('a' + i);
            build_string(i);
            if (i != v) tmp.push_back('a' + v);
        }
    }
}

void solve() {
    cin >> n >> k;
    build_string();

    while (tmp.size() < n) tmp += tmp;
    tmp = 'a' + tmp;
    tmp.resize(n);
    cout << tmp << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}