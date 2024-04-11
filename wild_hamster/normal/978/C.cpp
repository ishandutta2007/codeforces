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
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum, ans;
ll a[200500],  b[200500];
ll dp[100500];
ll used[100500];
vector<ll> f;
set<ll> g;
int main() {
    //freopen("input.txt","r",stdin);
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll idx = 0;
    ll cur = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (i > 0)
            cur += b[i] - b[i-1];
        else
            cur = b[i];
        while (cur > a[idx]) {
            cur -= a[idx];
            idx++;
        }
        cout << idx+1 << " " << cur << endl;
    }
    return 0;
}