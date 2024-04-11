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
#define SQ 2000
#define N 2000000
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,w,h,l,timer;
ll a[100500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        k += a[i];
    }
    m = max(k, n-k);
    for (i = 0; i < n; i++)
    {
        ll tmp = 0;
        for (j = 0; j < i; j++)
            tmp += 1-a[j];
        for (j = i; j < n; j++)
            tmp += a[j];
        m = max(m, tmp);
    }
    cout << m << endl;
    return 0;
}