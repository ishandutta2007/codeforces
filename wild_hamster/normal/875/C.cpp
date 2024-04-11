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
#define SQ 320
#define LOW 1
#define HIGH 2
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll used[3000500], used2[3005000];
vector<ll> f[1000500], g[1000500], gr[1000500], ans;
vector<ll> ans2;
void go(ll l, ll r, ll pos) {
    while (l <= r && f[l].size() <= pos)
        l++;
    if (l > r)
        return;

    ll cur = l;
    for (int i = l; i < r; i++) {
        if (f[i+1].size() <= pos) {
            cout << "No" << endl;
            exit(0);
        }
        if (f[i][pos] != f[i+1][pos]) {
            g[f[i][pos]].push_back(f[i+1][pos]);
            gr[f[i+1][pos]].push_back(f[i][pos]);
            go(cur, i, pos+1);
            cur = i+1;
        }
    }
    go(cur, r, pos+1);
}
void dfs(ll v) {
    //cout << v << endl;
    if (used[v])
        return;
    bool low = false, high = false;
    for (int i = 0; i < g[v].size(); i++) {
        ll x = g[v][i]; //after v x
        if (v > x) {
            low = true;
        } else {
            if (used[x] == LOW)
                low = true;
        }
    }
    for (int i = 0; i < gr[v].size(); i++) {
        ll x = gr[v][i];//after x v
        if (v < x) {
            high = true;
        } else {
            if (used[x] == HIGH)
                high = true;
        }
    }
    if (low && high) {
        cout << "No" << endl;
        exit(0);
    }
    if (high)
        used[v] = HIGH;
    else
        used[v] = LOW;
}

void dfs2 (int v) {
	used2[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!used2[to])
			dfs2 (to);
	}
	ans2.push_back (v);
}

void topological_sort() {
	for (int i=1; i<=m; ++i)
		used2[i] = false;
	ans2.clear();
	for (int i=1; i<=m; ++i)
		if (!used2[i])
			dfs2 (i);
	reverse (ans2.begin(), ans2.end());
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d",&x);
        for (int j = 0; j < x; j++)
        {
            scanf("%d",&y);
            f[i].push_back(y);
        }
    }
    go(0, n-1, 0);
    /*for (int i = 1; i <= m; i++)
    {
        cout << i << endl;
        for (int j = 0; j < g[i].size(); j++)
            cout << g[i][j] << " ";
        cout << endl;
    }*/
    topological_sort();
    for (i = 1; i <= m; i++)
        if (!used[i])
            dfs(i);
    for (i = 1; i <= m; i++){
        for (j = 0; j < g[i].size(); j++) {
            ll x = g[i][j];
            if (x > i) {
                if (used[x] < used[i]) {
                    cout << "No" << endl;
                    return 0;
                }
            } else {
                if (used[i] != LOW || used[x] != HIGH) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
        if (used[i] == LOW)
            ans.push_back(i);
    }
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}