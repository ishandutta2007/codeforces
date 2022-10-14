#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum, ans;
ll a[100500],  w[100500];
ll dp[100500];
ll used[100500];
vector<ll> f;
set<ll> g;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    reverse(a, a+n);
    for (int i = 0; i < n; i++) {
        if (g.find(a[i]) == g.end()) {
            g.insert(a[i]);
            f.push_back(a[i]);
        }
    }
    cout << f.size() << endl;
    reverse(f.begin(), f.end());
    for (int i = 0; i < f.size(); i++)
        cout << f[i] << " ";
    return 0;
}