#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 300500
#define OFF 200001
#define MOD 1000000007
ll N;
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll a[3][205000], b[200500], w[200500];
pii f[205];
ll Abs(ll x) {
    return x > 0 ? x : -x;
}
ll dst(ll x, ll y, ll z, ll w) {
    return Abs(x-z) + Abs(y-w);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll pshe = 2LL*(ll)1e+16 + 1;
    ll ax, bx, ay, by, xs, ys, t;
    cin >> f[0].X >> f[0].Y >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    ll sz = 0;
    for (int i = 1; i < 100; i++) {
        f[i].X = f[i-1].X * ax + bx;
        f[i].Y = f[i-1].Y * ay + by;
        if (f[i].X > pshe || f[i].Y > pshe) {
            sz = i;
            break;
        }
    }
    ll ans = 0;
    for (int i = 0; i < sz; i++) {
        ll dt = dst(f[i].X, f[i].Y, xs, ys);
        ll tt = t;

        //cout << i << " " << dt << "\n";
        tt -= dt;
        if (tt < 0) {
            continue;
        }
        bool fin = false;
        for (int j = i - 1; j >= 0; j--) {
            tt -= dst(f[j+1].X, f[j+1].Y, f[j].X, f[j].Y);
            if (tt < 0) {
                fin = true;
                ans = max(ans, 0LL + (i - j));
                break;
            }
        }
        if (fin) {
            continue;
        }
        if (i == sz - 1) {
            cout << sz << "\n";
            return 0;
        }
        tt -= dst(f[0].X, f[0].Y, f[i+1].X, f[i+1].Y);
        if (tt < 0) {
            ans = max(ans, 0LL + i + 1);
            continue;
        }
        for (int j = i + 1; j + 1 < sz; j++) {
            tt -= dst(f[j+1].X, f[j+1].Y, f[j].X, f[j].Y);
            if (tt < 0) {
                fin = true;
                ans = max(ans, 0LL + j + 1);
                break;
            }
        }
        if (!fin) {
            cout << sz << "\n";
            return 0;
        }
    }
    cout << ans << "\n";


    return 0;

}