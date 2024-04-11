#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

void solve() {
    int n; cin >> n;

    if (n % 7 == 0) {
        cout << n << '\n';
    } else {
        for (int d = 1; d <= 9; ++d) {
            int x = n - n % 10 + d;
            if (x % 7 == 0) {
                cout << x << '\n';
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1; 
    cin >> t;
    while (t--) solve();
}