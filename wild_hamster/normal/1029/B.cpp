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
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer, cnt,v,tot,x,y,xx, yy,INF, sz;
vector<ll> mag;
int a[200500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int j = 0;
    for (int i = 0; i < n; i++) {
        j = max(j, i);
        while (j+1 < n && a[j+1] <= 2*a[j])
            j++;
        k = max(k, j-i+1);
        //cout << k << endl;
    }
    cout << k << endl;
    return 0;
}