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
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,v,tot,x,y,xx, yy,INF, sz;
ll a[400500], b[400500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        x = max(x, a[i]);
    }
    ll flag = 0;
    for (int i = 0; i < n; i++) {
        if (x != a[i] && a[i] != 0)
            flag = 1;
    }
    if (!flag) {
        if (x != 0) {
            ll cnt = 0;
            for (int i = 0; i < n; i++)
                if (a[i] != 0) {
                    cnt++;
                    k = i;
                }
            if (cnt == n) {
                cout << "NO" << endl;
                return 0;
            }
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
                if (a[i] == x && a[(n+i-1)%n] == 0)
                    k = i;
            b[k] = x;
            b[(n+k-1)%n] = 2*x;
            for (int i = n+k-2; i >= k+1; i--)
                b[i%n] = b[(i+1)%n] + a[i%n];
            for (int i = 0; i < n; i++)
                printf("%I64d ", b[i]);
            return 0;
        }
        else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
                printf("1 ");
            cout << endl;
        }
        return 0;
    }
    for (int i = 0; i < n; i++)
        if (a[i] < x && a[i] != 0) {
            k = i;
            break;
        }
    while (a[k] != x) {
        k = (k+1)%n;
    }
    b[k] = x;
    for (int i = n+k-1; i >= k+1; i--)
        b[i%n] = b[(i+1)%n] + a[i%n];
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
        printf("%I64d ", b[i]);
    return 0;
}