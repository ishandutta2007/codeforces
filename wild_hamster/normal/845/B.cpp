#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
typedef long long ll;
using namespace std;
ll n,i,j,k,x, a[505000], b[500000], ans[500500];
pii c[500500], d[500500];
string s;
int main() {
    cin >> s;
    for (i = 0; i < 6; i++)
        s[i] -= '0';
    ll ans = 10;
    for (i = 0; i < 1000000; i++)
    {
        vector<ll> f;
        for (j = 0, x = i; j < 6; j++)
        {
            f.push_back(x%10);
            x /= 10;
        }
        int x1 = 0, x2 = 0;
        for (j = 0; j < 3; j++)
            x1 += f[j];
        for (j = 3; j < 6; j++)
            x2 += f[j];
        if (x1 != x2)
            continue;
        ll tmp = 0;
        for (j = 0; j < 6; j++)
        {
            tmp += (f[j] != s[j]);
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}