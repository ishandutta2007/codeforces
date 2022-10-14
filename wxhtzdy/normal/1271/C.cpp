#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1234567
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b)  {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
int n, sx, sy;
int x[maxn], y[maxn];
int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
int check(int X, int Y) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (dist(x[i], y[i], X, Y) + dist(X, Y, sx, sy) == dist(x[i], y[i], sx, sy)) {
            cnt++;
        }
    }
    return cnt;
}
int main() {
    scanf("%d%d%d", &n, &sx, &sy);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    pair<int, pi> ans = mp(-1, mp(0, 0));
    function<void(int, int)> upd = [&](int X, int Y) {
        int cc = check(X, Y);
        if (cc > ans.fi) ans = mp(cc, mp(X, Y));
    };
    upd(sx + 1, sy);
    upd(sx - 1, sy);
    upd(sx, sy + 1);
    upd(sx, sy - 1);
    printf("%d\n%d %d", ans.fi, ans.se.fi, ans.se.se);
    return 0;
}