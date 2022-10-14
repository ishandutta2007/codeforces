#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
#include <time.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k, y, z, l, i, j, p, x;
pii a[100500];
ll Abs(ll x) {
    return x>0?x:-x;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].X;
        l += a[i].X;
        a[i].Y = i+1;
        if (a[i].X >= 2) {
            p++;
        }
    }
    p = min(p, n-2);
    if (l < 2*n-2) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES " << p+1 << endl;
    cout << n-1 << endl;
    sort(a, a+n);
    l -= a[0].X + a[1].X - 2;
    a[0].X = a[1].X = 1;
    int id = n+1;
    for (int i = 0; i < n; i++) {
        if (a[i].X >= 2) {
            id = min(id, i);
            ll r = min(a[i].X - 2, l - 2*n + 2);
            a[i].X -= r;
            l -= r;
        }
    }
    ll prv = a[0].Y;
    for (int i = id; i < n; i++) {
        cout << a[i].Y << " " << prv << endl;
        prv = a[i].Y;
    }
    cout << prv << " " << a[1].Y << endl;
    int pnt = 2;
    for (int i = id; i < n; i++) {
        while (a[i].X > 2) {
            cout << a[i].Y << " " << a[pnt].Y << endl;
            a[i].X--;
            pnt++;
        }
    }
    return 0;
}