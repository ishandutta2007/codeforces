#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define eb emplace_back

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int s = n * m;
        if (s % 3 == 0) {
            cout << s/3 << '\n';
        } else if (s % 3 == 1) {
            cout << (s+2) / 3 << '\n';
        } else {
            cout << (s+1) / 3 << '\n';
        }
    }
}