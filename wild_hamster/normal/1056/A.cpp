#include <bits/stdc++.h>
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
ll n,m,k,a[100500],x, rt[35], y, z, l, i, j, p;
map<ll, ll> f;
int main() {
     //freopen("input.txt","r",stdin);
     cin >> n ;
     for (int i = 0; i < n; i++) {
        cin >> x;
        for (int j = 0; j < x; j++) {
            cin >> y;
            f[y]++;
        }
     }
     for (auto x : f) {
        if (x.second == n) {
            cout << x.first << " ";
        }
     }
    return 0;
}