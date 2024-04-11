#include <iostream>
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
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back
#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second
#define INF 1000000000
#define INFLL 1000000000000000000LL

typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long ll;

vector<string> path;

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    string q, w;
    cin >> n;
    REP (i, n) {
        cin >> q;
        if (q[0] == 'p') {
            cout << '/';
            REP (i, SZ (path)) {
                cout << path[i] << '/';
            }
            cout << endl;
            continue;
        }        
        cin >> w;
        if (w[0] == '/') path.clear(); 
        REP (i, SZ (w))
            if (w[i] == '/') w[i] = ' ';
        istringstream str(w);
        string x;
        while (str >> x) {
            if (x == "..") {
                path.pop_back();
            } else {
                path.push_back(x);
            }
        }
    }    
	return 0;	
}