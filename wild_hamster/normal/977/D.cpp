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
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[300500];
ll b[1005000], t[1005000];
string s;
set<ll> is_here;

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        is_here.insert(a[i]);
    }
    sort(a, a+n);

    i = 0;
    t[i++] = a[0];
    while (i < n) {
        if (is_here.find(t[i-1]*3) != is_here.end()) {
            t[i] = t[i-1]*3, i++;
        } else if (t[i-1]%2 == 0 && is_here.find(t[i-1]/2) != is_here.end()) {
            t[i] = t[i-1]/2, i++;
        } else
        break;
    }

    for (int j = i-1; j >= 0; j--)
        cout << t[j] << " ";

    i = 0;
    b[i++] = a[0];
    while (i < n) {
        if (is_here.find(b[i-1]*2) != is_here.end()) {
            b[i] = b[i-1]*2, i++;
        } else if (b[i-1]%3 == 0 && is_here.find(b[i-1]/3) != is_here.end()) {
            b[i] = b[i-1]/3, i++;
        } else
        break;
    }
    for (int j = 1; j < i; j++)
        cout << b[j] << " ";
    return 0;
}