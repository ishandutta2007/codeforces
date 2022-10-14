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
ll n,i,j,k,z,m,q,r,timer,l, cnt,v,tot,x,y,xx, yy,INF, sz, sum;
ll a[200500];
ll mx[200500], mn[200500], nxt[200500], prv[200500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
        mx[i] = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        l = max(l, a[i]);
        if (a[i] > 0) {
            if (mx[a[i]] == -1) {
                mx[a[i]] = i;
                mn[a[i]] = i;
            } else {
                mx[a[i]] = max(mx[a[i]], i);
                mn[a[i]] = min(mn[a[i]], i);
            }
        }
    }
    if (mx[q] == -1) {
        ll flag = 0;
        for (int i = 1; i <= n; i++)
        if (a[i] == 0) {
            flag = 1;
            a[i] = q;
            mx[q] = i;
            mn[q] = i;
            break;
        }
        if (!flag) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (l == 0) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            printf("%d ", q);
        cout << endl;
        return 0;
    }
    for (int i = 0; i <= n; i++) {
        nxt[i] = i+1;
        prv[i+1] = i;
    }
    for (int i = q; i >= 1; i--) {
        if (mx[i] != -1) {
            ll l = mn[i];
            //cout << i << " " << l << " " << mx[i] << " " << nxt[l] << endl;
            while (l <= mx[i]) {
                if (a[l] != 0 && a[l] != i) {
                    cout << "NO" << endl;
                    return 0;
                } else
                if (a[l] == 0)
                    a[l] = i;

                l = nxt[l];
            }
            ll r = l;
            l = prv[mn[i]];
            while (r <= n && a[r] == 0) {
                a[r] = i;
                r = nxt[r];
            }
            while (l >= 1 && a[l] == 0) {
                a[l] = i;
                l = prv[l];
            }
            nxt[l] = r;
            prv[r] = l;
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}