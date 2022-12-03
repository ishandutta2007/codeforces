#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
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
#define DEBUG(x) cout << #x << " = " << x << endl;

#define INF 1000000000

typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long ll;

int d[256][256];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    int y = 128, x = 128;
    int c = 0;    
    d[y][x] = ++c;
    REP (i, SZ (s)) {
        if (s[i] == 'U') --y;
        if (s[i] == 'D') ++y;
        if (s[i] == 'L') --x;
        if (s[i] == 'R') ++x;        
        if (d[y][x]) {
            puts ("BUG");
            return 0;
        }
        d[y][x] = ++c;
        
        REP (dir, 4) {
            int q = y + dy[dir];
            int w = x + dx[dir];
            if (d[q][w] && d[q][w] < d[y][x]-1) {
                puts ("BUG");
                return 0;
            }
        }
    }
    puts ("OK");
	return 0;
}