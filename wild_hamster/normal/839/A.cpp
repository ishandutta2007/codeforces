#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
#define N 8388607
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,l,timer;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        k += x;
        m -= min(k,8);
        k -= min(k,8);
        if (m <= 0)
        {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}