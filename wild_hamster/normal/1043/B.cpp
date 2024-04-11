#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<ll,ll>
#define X first
#define Y second
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define INF 998244353
#define MAXN 1000005
typedef long long ll;
using namespace std;
ll i,j,k,q,x,y,n,m,  x1,y1,x2,y2,z;
ll a[200500], b[200500];
string s;
vector<ll> f;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    ll mx = 0;
    ll lst = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i]-lst;
        lst = a[i];
    }
    for (int i = 1; i <= n; i++) {
        int flag = 1;
        for (int j = 0; j < n; j++)
            if (b[j] != b[j%i])
                flag = 0;
        if (flag)
            f.push_back(i);
    }
    cout << f.size() << endl;
    for (int i = 0; i < f.size(); i++)
        cout << f[i] << " ";
    cout << endl;
    return 0;
}