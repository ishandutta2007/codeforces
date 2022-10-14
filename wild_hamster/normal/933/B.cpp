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
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[100500], b[100500];
vector<ll> f;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    i = 0;
    while (n >= k || n < 0) {
        x = -n/k;
        while (x * k + n < 0)
            x++;
        while (x * k + n >= k)
            x--;
        a[i++] = x * k + n;
        n = x;
    }
    if (n > 0)
        a[i++] = n;
    cout << i << endl;
    for (j = 0; j < i; j++)
        cout << a[j] << " ";
    return 0;
}