#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }

bool solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int x0, y0, x1, y1, x2, y2; cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
    x1 -= x0, x2 -= x0, y1 -= y0, y2 -= y0; x1 *= -1, y1 *= -1;
    if(b-a > x2 || a-b > x1) return false;
    if(d-c > y2 || c-d > y1) return false;
    return (!(a+b) || x1 || x2) && (!(c+d) || y1 || y2);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) cout << (solve() ? "Yes" : "No") << '\n';
}