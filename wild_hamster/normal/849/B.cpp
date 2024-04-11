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
#define N 310
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,Q,w,h;
ll a[100500], b[100500];
vector<ll> f, g;
int main() {
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < 2; i++)
        for (j = i+1; j < n; j++)
        {
            if (a[j]-a[i] == (j-i)*(a[1]-a[0]) && i+j > 1)
                continue;
            for (k = 0; k < n; k++)
                b[k] = 0;
            b[i] = 1;
            b[j] = 1;
            ll p = a[j] - a[i], q = j-i;
            for (k = j+1; k < n; k++)
                if ((a[k]-a[j])*q == p*(k-j))
                    b[k] = 1;
            f.clear();
            for (k = 0; k < n; k++)
                if (!b[k])
                    f.push_back(k);
            int flag = 1;
            for (k = 0; k+1 < f.size(); k++)
            {
                if ((a[f[k+1]] - a[f[k]])*q != p*(f[k+1]-f[k]))
                    flag = 0;
            }
            if (flag && !f.empty())
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    cout << "NO" << endl;
    return 0;
}