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
typedef int ll;
using namespace std;
const int INF = 1000*1000*1000;
ll n,m,k,x,y;
ll a[1000500], b[2000500], ans[500500];
ll w[2005000];
set<pii> edges;
set<pii> wv;
vector<ll> g[500500];
void dom(ll v, ll to) {
    //cout << v << " " << to << endl;
    if (edges.find(mp(v, to)) != edges.end()) {
        edges.erase(mp(v,to));
        edges.erase(mp(to,v));
        wv.erase(mp(w[to], to));
        w[to]--;
        if (w[to] > 0)
            wv.insert(mp(w[to], to));
        wv.erase(mp(w[v], v));
        w[v]--;
        if (w[v] > 0)
            wv.insert(mp(w[v], v));
    }
}
void inp() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[i] = x;
        b[i] = y;
    }
}

void gen() {
    n = 20;
    m = n-5;
    k = 1;
    for (int i = 0; i < m; i++) {
        a[i] = i+1;
        b[i] = i+5;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    inp();
    //gen();
    for (int i = 0; i < m; i++) {
        int x = a[i], y = b[i];
        edges.insert(mp(x,y));
        edges.insert(mp(y,x));
        g[x].push_back(y);
        g[y].push_back(x);
        w[y]++;
        w[x]++;

    }
    for (int i = 1; i <= n; i++) {
        if (w[i] > 0)
            wv.insert(mp(w[i], i));
    }
    for (int i = m-1; i >= 0; i--) {
        //cout << i << endl;
        while (!wv.empty()) {
            auto itr = wv.begin();
            int val = (*itr).X;
            if (val >= k)
                break;
            int v = (*itr).Y;
            for (int i = 0; i < g[v].size(); i++) {
                int to = g[v][i];
                dom(v, to);
            }
        }
        ans[i] = wv.size();
        int v = a[i];
        int to = b[i];
        dom(v, to);
    }
    for (int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
	return 0;
}