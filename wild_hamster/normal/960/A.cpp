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
ll b[100500];
double a[100];
string s;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> s;
    n = s.size();
    for (i = 0; i < n; i++)
    if (s[i] != 'a') {
        x = i;
        break;
    }
    for (; i < n; i++)
    if (s[i] != 'b') {
        y = i-x;
        break;
    }
    for (; i < n; i++)
    if (s[i] != 'c') {
        break;
    }
    z = n-x-y;
    if (i != n || x == 0 || y == 0 || (x != z && y != z)) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}