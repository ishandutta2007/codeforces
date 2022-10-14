#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y, b[500000], ans[500500];
pii a[500500];
vector<pii> f1, f2;
string s;
int main() {
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[i] = mp(x,y);
    }
    sort(a, a+n);
    for (i = 0; i < n; i++)
    {
        if (f1.empty())
            f1.push_back(a[i]);
        else
        if (a[i].X > f1.back().Y)
            f1.push_back(a[i]);
        else
        if (f2.empty())
            f2.push_back(a[i]);
        else
        if (a[i].X > f2.back().Y)
            f2.push_back(a[i]);
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}