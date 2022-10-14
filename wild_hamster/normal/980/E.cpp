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
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,mx,l,sum;
ll used[1005000];
vector <ll> g[1005000];
ll tin[1005000], tout[1005000];
ll timer;
ll top;
ll up[1005000][23];

void dfs (int v, int p = n) {
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i=1; i<=l; ++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (to != p)
			dfs (to, v);
	}
	tout[v] = ++timer;
}

bool upper (int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int main() {
    //freopen("input.txt","r",stdin);
    l = 21;
    cin >> n >> k;
    k = n-k;
    for (int i = 0; i < n-1; i++) {
        ll x, y;
        scanf("%d %d",&x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(n);
    used[n] = 1;
    top = n;
    ll left = k-1;
    for (int i = n-1; i >= 1; i--) {
        if (!used[i]) {
            ll x = i;
            ll sum = 0;
            for (int j = l; j >= 0; j--) {
                if (!used[up[x][j]]) {
                    sum += (1<<j);
                    x = up[x][j];
                }
            }
            if (sum+1 <= left) {
                left -= sum+1;
                ll cnt = sum+1;
                x = i;
                while (cnt--) {
                    used[x] = 1;
                    x = up[x][0];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (!used[i])
            cout << i << " ";
    cout << endl;
    return 0;
}