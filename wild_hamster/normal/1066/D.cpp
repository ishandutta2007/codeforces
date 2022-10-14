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
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c;
vector<pii> f, f1;
int a[1000500], b[1005000];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int sum = k;
    reverse(a, a+n);
    for (int i = 0; i < n; i++) {
        if (sum >= a[i]) {
            sum -= a[i];
        } else {
            if (m == 1) {
                cout << i << endl;
                return 0;
            } else
                m--, sum = k - a[i];
        }
    }
    cout << n << endl;
    return 0;
}