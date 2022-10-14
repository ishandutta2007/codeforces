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
#define MOD 998244353
#define ROW 5
#define N 1000005
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, v,tot,x,y,INF, sz,ans;
ll a[100500], c[1050], b[1500];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    for (int i = 0; i <= 100; i++) {
        if (b[i] == 1)
            k++;
        else if (b[i] > 2)
            l++;
    }
    if (k % 2 && l == 0) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
        if (b[a[i]] > 2)
            x = i;
    if (k % 2)
        c[x] = 1;
    k = k/2;
    for (int i = 0; i < n; i++) {
        if (b[a[i]] == 1 && k > 0)
            k--, c[i] = 1;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
        if (c[i])
            cout << "A";
        else
            cout << "B";
    cout << endl;
    return 0;
}