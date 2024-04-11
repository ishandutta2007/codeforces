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
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,Q, mx,a[200500];
int main() {
    //freopen("input.txt", "r", stdin);
    ll d,r;
    cin >> d >> r;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d %I64d %I64d",&x,&y,&z);
        if (x*x+y*y >= (d-r+z)*(d-r+z) && x*x+y*y <= (d-z)*(d-z))
            k++;
    }
    cout << k << endl;
    return 0;
}