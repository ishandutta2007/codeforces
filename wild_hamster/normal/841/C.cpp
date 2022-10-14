#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
typedef long long ll;
using namespace std;
ll n,i,j,k, a[505000], b[500000], ans[500500];
pii c[500500], d[500500];
string s;
int main() {
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        c[i] = mp(a[i], i);
    }
    sort(c, c+n);
    reverse(c,c+n);
    for (i = 0; i < n; i++)
    {
        cin >> b[i];
        d[i] = mp(b[i], i);
    }
    sort(d, d+n);
    for (i = 0; i < n; i++)
    {
        ans[d[i].Y] = c[i].X;
    }
    for (i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}