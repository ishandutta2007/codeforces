#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <time.h>
#include <fstream>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
typedef long long ll;
using namespace std;

ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[100500], leaf[100500];
vector<ll> g[100500];
void dfs(ll v, ll p = -1) {
    if (leaf[v]) {
        return;
    }
    ll x = 0;
    for (int i = 0; i < g[v].size(); i++) {
        ll to = g[v][i];
        if (to != p) {
            x += leaf[g[v][i]];
            dfs(to, v);
        }
    }
    if (x < 3) {
        cout << "No" << endl;
        exit(0);
    }
}
int main() {
    // cout << setprecision(20);
    // ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 2; i <= n; i++) {
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    for (i = 1; i <= n; i++)
        if (g[i].size() == 1) {
            leaf[i] = 1;
        }
    dfs(1);
    cout << "Yes" << endl;
    return 0;
}