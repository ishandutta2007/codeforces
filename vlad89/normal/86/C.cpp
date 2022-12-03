#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset((a),(b),sizeof(a))

#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

string a[10];
int d[1024][612][12];
int go[612][4];
int redeem[612][4];
const int mod = 1000000009;

string G = "ACGT";

bool ends(string s, string g) {
    if (sz (g) > sz(s)) return false;
    return (s.substr(sz(s) - sz(g)) == g);
}

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<string> b;
    REP (i, m) {
        cin >> a[i];
        REP (j, sz(a[i])) {
            string s;            
            FOR (k, j, sz(a[i])) {
                s += a[i][k];
                b.pb(s);
            }            
        }            
    }
    b.pb("");
    sort(all(b));
    b.resize(unique(all(b)) - b.begin());
    map<string, int> Q;
    REP (i, sz (b)) Q[b[i]] = i;
    REP (i, sz(b)) {
        REP (j, 4) {
            string s = b[i] + G[j];
            REP (t, m)
                if (ends(s, a[t]))
                    redeem[i][j] = max(redeem[i][j], sz(a[t]));
//            if (redeem[i][j])
//                cout << s << ' ' << redeem[i][j] << endl;
            while (true) {
                if (Q.count(s)) {                 
                    go[i][j] = Q[s];
//                    cout << b[i]+G[j] << ' ' << b[Q[s]] << endl;
                    break;
                }
                s.erase(0, 1);
            }
        }        
    }
    int k = sz(b);
    d[0][0][0] = 1;
    int ni, nj, nadd;
    REP (i, n) {
        REP (j, k)
            REP (add, 10) if (d[i][j][add]) {
                REP (alpha, 4) {
                    ni = i+1;
                    nj = go[j][alpha];
                    nadd = redeem[j][alpha] >= (add+1) ? 0 : add+1;
                    d[ni][nj][nadd] += d[i][j][add];
//                    cout << "go to " << ni << ' ' << nj << ' ' << nadd << endl;
                    if (d[ni][nj][nadd] >= mod)
                        d[ni][nj][nadd] -= mod;
                }
            }
    }
    long long res = 0;
    REP (j, k)
        res += d[n][j][0];
    res %= mod;
    cout << res << endl;
	return 0;
}