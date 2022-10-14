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
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l, cnt,s;
vector<ll> g[100500], ff;
ll a[1000500], t[4000500];
map<ll,ll> f;

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        f[x] = i+1;
    }
    if (m > f.size()) {
        cout << "NO" << endl;

    } else {
        cout << "YES" << endl;
        auto itr = f.begin();
        for (int i = 0; i < m; i++) {
            cout << (*itr).Y << " ";
            itr++;
        }
    }
    return 0;
}