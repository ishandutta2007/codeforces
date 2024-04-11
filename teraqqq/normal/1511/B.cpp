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

void solve() {
    int a, b, c; cin >> a >> b >> c;

    if (a <= b) {
        cout << string(a+1-c, '1') << string(c-1, '0') << " ";
        cout << string(a-c, '1') << "2" << string(b-a+c-1, '0') << '\n';
    } else {
        swap(a, b);
        cout << string(a-c, '1') << "2" << string(b-a+c-1, '0') << '\n';
        cout << string(a+1-c, '1') << string(c-1, '0') << " ";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}