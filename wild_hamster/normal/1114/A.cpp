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
ll  q, ans, w[100500], d[100500], p[100500];



int main() {
    //freopen("input.txt", "r", stdin);
    ll x,y,z,a,b,c;
    cin >> x >> y >> z >> a >> b >> c;
    if (a >= x && a+b >= x + y && a+b+c >= x+y+z) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}