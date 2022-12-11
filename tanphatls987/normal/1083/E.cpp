#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;


#define X first
#define Y second

const double EPS = 1e-9;
const int BASE = 1e9 + 10;
const int N = 1e6 + 10;

pll dq[N];
bool better(pll a, pll b, pll c) {
    return ((long double)a.Y - b.Y + .0) / (b.X - a.X) + EPS 
        > ((long double)a.Y - c.Y + .0) / (c.X - a.X);
}
ll get(pll a, long long x) {
    return a.X * x + a.Y;
}
struct info{
    ll x, y, wei;
    bool operator < (const info& oth) const {
        return x < oth.x;
    }
}a[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        ll x, y, wei;
        cin >> x >> y >> wei;
        a[i] = {x, y, wei};
    }
    sort(a + 1, a + n + 1);
    int top = 1, bot = 1;
    dq[1] = pll(0, 0);
    long long ans = 0;

    for(int i = 1; i <= n; i++) {
        if (i > 1) 
            assert(a[i].x > a[i - 1].x && a[i].y < a[i - 1].y);
        while (top < bot && get(dq[top], a[i].y) <= get(dq[top + 1], a[i].y))
            top++;
        long long res = get(dq[top], a[i].y) - a[i].wei + a[i].x * a[i].y;
        ans = max(ans, res);
        pll cur = pll(-a[i].x, res);
        while (top < bot && better(dq[bot - 1], cur, dq[bot])) bot--;
        dq[++bot] = cur;
    }
    cout << ans;
}