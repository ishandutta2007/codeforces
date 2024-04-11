#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<ll,ll>
#define X first
#define Y second
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c,z;
int a[200500], used[200500];
pii pref[200500], suf[200500];
void update(pii &p, char c) {
    if (c == 'U')
        p.Y++;
    if (c == 'D')
        p.Y--;
    if (c == 'R')
        p.X++;
    if (c == 'L')
        p.X--;
}

int Abs(int x) {
    return x>0?x:-x;
}
bool check(int moves, int x, int y) {
    int n = Abs(x) + Abs(y);
    //cout << moves << " " << n << " " << x << " " << y << endl;
    if (moves < n || moves % 2 != n % 2)
        return false;
    return true;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    string s;
    cin >> s;
    cin >> x >> y;
    if (!check(n, x, y)) {
        cout << -1 << endl;
        return 0;
    }
    int ans = MOD;
    pii p = mp(0, 0);
    for (int i = 0; i < n; i++) {
        update(p, s[i]);
        pref[i+1] = p;
    }
    if (pref[n] == mp(x, y)) {
        cout << 0 << endl;
        return 0;
    }
    p = mp(0, 0);
    for (int i = n-1; i >= 0; i--) {
        update(p, s[i]);
        suf[i] = p;
    }
    for (int i = 0; i < n; i++) {
        int l = i, r = n-1;
        if (!check(n-i, x-pref[i].X, y-pref[i].Y))
            continue;

        while (l < r) {
            int mid = (l+r)/2;
            if (check(mid-i+1, x-pref[i].X-suf[mid+1].X, y - pref[i].Y-suf[mid+1].Y))
                r = mid;
            else
                l = mid+1;
        }
        ans = min(ans, l-i+1);
    }
    cout << ans << endl;
    return 0;
}