#pragma GCC optimize("O3")
#pragma GCC target("arch=corei7-avx")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif
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
int b[2005], a[2005];
ll d[5250500];
int main() {
    //freopen("input.txt","r",stdin);
    int n;
    ll m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    m *= 2;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[(i<<11)+j] = (ll)a[i] * b[j] - (ll)a[j]*b[i];
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++) {
                ll huy1 = m - d[(i<<11)+j];
                ll huy2 = -m-d[(i<<11)+j];
                for (int k = j+1; k < n; k++) {
                    ll S = d[(j<<11)+k] - d[(i<<11)+k];
                    if (S == huy1 || S == huy2) {
                        cout << "Yes" << endl;
                        cout << a[i] << " " << b[i] << endl;
                        cout << a[j] << " " << b[j] << endl;
                        cout << a[k] << " " << b[k] << endl;
                        return 0;
                    }
                }
            }
        cout << "No" << endl;
        return 0;
}