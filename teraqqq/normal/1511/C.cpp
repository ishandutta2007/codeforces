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

const int C = 50;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n), top, fc(C, true);

    for (int& x : a) cin >> x, --x;
    while (q--) {
        int x; cin >> x; --x;
        if (fc[x]) {
            auto it = find(begin(a), end(a), x);
            cout << size(top) + (it - begin(a)) + 1 << '\n';
            top.insert(top.begin(), x);
            a.erase(it);
            fc[x] = false;
        } else {
            auto it = find(begin(top), end(top), x);
            cout << (it - begin(top)) + 1 << '\n';
            top.erase(it);
            top.insert(top.begin(), x);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}