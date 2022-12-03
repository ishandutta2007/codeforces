#define _CRT_SECURE_NO_DEPRECATE
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) SORT(a),(a).resize(unique(all(a))-a.begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset (a, b, sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const int inf = -1u/4;
int n, m, g, s;
pair<pii, pii> a[123456];
vector<pii> adj[256];
int best, bestx, besty;

bool search (int x, int pred, int to) {
    if (x == to) {
        return true;
    }
    REP (i, sz (adj[x])) {
        int y = adj[x][i].X;
        if (y == pred) continue;
        if (search (y, x, to)) {
            if (adj[x][i].Y > best) {
                best = adj[x][i].Y;
                bestx = x;
                besty = y;
            }
            return true;
        }
    }        
    return false;
}

int main() {
    #ifdef LocalHost
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    scanf ("%d%d", &n, &m);
    scanf ("%d%d", &g, &s);
    REP (i, m) {
        scanf ("%d%d%d%d", &a[i].Y.X, &a[i].Y.Y, &a[i].X.X, &a[i].X.Y);
        --a[i].Y.X;
        --a[i].Y.Y;
    }
    sort(a, a+m);
    long long ans = -1ull/4;
    int Count = 0;
    REP (i, m) if (a[i].Y.X != a[i].Y.Y) {
        best = -inf;
        int x = a[i].Y.X;
        int y = a[i].Y.Y;
        if (search (x, -1, y)) {
            if (best > a[i].X.Y) {
                adj[bestx].erase(find(all(adj[bestx]), pii (besty, best)));
                adj[besty].erase(find(all(adj[besty]), pii (bestx, best)));
                --Count;
            } else
                continue;
        }        
        adj[x].pb (pii (y, a[i].X.Y));
        adj[y].pb (pii (x, a[i].X.Y));        
        ++Count;
        
        long long S = 0;
        REP (q, n)
            REP (w, sz (adj[q])) {
//                cout << q+1 << ' ' << adj[q][w].X+1 << ' ' << adj[q][w].Y << endl;
                if (adj[q][w].Y > S)
                    S = adj[q][w].Y;
                }
//        cout << a[i].X.X << ' ' << S << endl;
//        cout << endl;        
        if (Count == n-1)
            ans = min (ans, (long long) a[i].X.X * g + S*s);        
    }    
    if (ans == -1ull/4)
        ans = -1;
    cout << ans << endl;
    return 0;
}