#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[300500];
ll t[1005000];
string s;
map<string,ll> f;

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    if (k == n) {
        cout << a[n-1] << endl;
        return 0;
    }
    if (k == 0) {
        if (a[0] == 1)
            cout << -1 << endl;
        else
            cout << a[0] - 1 << endl;
        return 0;
    }
    if (a[k-1] == a[k]) {
        cout << -1 << endl;
    } else {
        cout << a[k-1] << endl;
    }
    return 0;
}