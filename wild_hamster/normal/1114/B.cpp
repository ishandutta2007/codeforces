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
ll n,m,k, y, z, l, i, j, x;
ll  q, ans, w[100500], d[100500], p[100500], a[200500];
pii b[200500];


int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = mp(a[i], i);
    }
    sort(b, b+n);
    for (int i = 0; i < n-k*m; i++)
        a[b[i].Y] = -MOD;
    ll cnt = 0;
    vector<ll> f;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != -MOD) {
            sum += a[i];
            cnt++;
        }
        if (cnt == m) {
            f.push_back(i+1);
            cnt = 0;
        }
    }
    cout << sum << endl;
    for (int i = 0; i < k-1; i++)
        cout << f[i] << " ";
    return 0;
}