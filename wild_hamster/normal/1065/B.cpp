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
#define MAXN 1000005
typedef long long ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom;

int main() {
    //freopen("input.txt", "r", stdin);
    //inp();
    cin >> n >> m;
    cout << max(0LL, n - m*2) << " ";
    for (int i = 0; i <= 500000; i++)
    if (1LL*i*(i-1)/2 >= m) {
        cout << n-i << endl;
        return 0;
    }
    return 0;
}