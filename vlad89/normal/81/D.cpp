#include <iostream>
#include <cstring>
#include <bitset>
#include <cstdio>
#include <sstream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UNIQUE(a) sort(ALL(a)),(a).resize(unique(ALL(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back

#define X first
#define Y second

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef long long ll;

int a[1234];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    scanf ("%d%d", &n, &m);    
    vpii yo;
    int ma = 0;
    REP (i, m) {
        scanf ("%d", a + i);
        a[i] = min (a[i], n/2);
        yo.pb(pii (a[i], i));        
    }
    sort(all(yo));
    reverse(all(yo));
    vector<vector<int> > G (yo[0].X);
    int cur = 0;
    int fc = 0;        
    REP (i, sz (yo)) {
        REP (j, yo[i].X) {
            if (fc == n) {
                goto out;
            }
            G[cur].pb(yo[i].Y);
            ++fc;
            cur++;
            cur %= sz (G);
        }            
    }
out:;
    vector<int> ans;
    REP (i, sz (G))
        REP (j, sz (G[i]))
            ans.pb (G[i][j]);
    if (sz (ans) != n) {
        cout << -1 << endl;
        return 0;
    }
    REP (i, sz (ans))
        if (ans[i] == ans[(i+1)%sz(ans)]) {
            cout << -1 << endl;
            return 0;
        }            
    REP (i, sz(ans)) {
        if (i)
            cout << ' ';
        cout << ans[i]+1;
    }
    cout << endl;
	return 0;
}