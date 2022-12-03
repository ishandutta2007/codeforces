#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

vi adj[50000];
int cnt[50000][501];
int n, k;
long long res = 0;

void rec(int x, int p = -1) {
    REP (i, sz (adj[x])) {
	int y = adj[x][i];
	if (y == p) continue;
	rec(y, x);
	REP (j, k) {
	    if (j <= k - j - 2) {
		if (j == k - j - 2)
		    res -= (long long) cnt[y][j] * (cnt[y][j] - 1) / 2;
		else 
		    res -= (long long) cnt[y][j] * cnt[y][k - j - 2];
	    }
	    cnt[x][j + 1] += cnt[y][j];
	}
    }
    cnt[x][0]++;
    REP (j, (k+1)/2) {
	res += (long long) cnt[x][j] * cnt[x][k - j];
    }
    
    if (k % 2 == 0)
	res += (long long) cnt[x][k / 2] * (cnt[x][k / 2] - 1) / 2;
    /*    cout << "x = " << x+1 << endl;
    REP (j, k+1)
	cout << cnt[x][j] << ' ';
	cout << endl;*/
}

int main () {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &k);
    int x, y;
    REP  (i, n-1) {
	scanf("%d%d", &x, &y);
	--x, --y;
	adj[x].pb(y);
	adj[y].pb(x);
    }
    rec(0);
    cout << res << endl;
    return 0;
}