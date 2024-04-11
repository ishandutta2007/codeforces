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
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum, ans, cnt;
vector<ll> f;
vector<ll> g[100500];
ll a[100500], w[100500];
ll t[100500];
vector<int> leafs;
set<int> endpoints;
void dfs(ll v, ll p = -1) {
    if (w[v] > 2) {
        cnt = v;
        return;
    }
    for (int i = 0; i < g[v].size(); i++) {
        ll to = g[v][i];
        if (to != p) {
            dfs(to, v);
        }
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
        w[x]++;
        w[y]++;
    }
    for (int i = 1; i <= n; i++)
        if (w[i] == 1)
            leafs.push_back(i);
    if (leafs.size() == 2) {
            cout << "Yes" << endl;
        cout << 1 << endl;
        cout << leafs[0] << " " << leafs[1] << endl;
        return 0;
    }
    for (int i = 0; i < leafs.size(); i++) {
        dfs(leafs[i]);
        endpoints.insert(cnt);
    }
    if (endpoints.size() > 1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << (int)(leafs.size()) << endl;
    auto itr = endpoints.begin();
    int v = (*itr);
    for (int i = 0; i < leafs.size(); i++) {
        printf("%d %d\n", v, leafs[i]);
    }
    return 0;
}