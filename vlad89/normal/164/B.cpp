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

int a[1000001];
int b[2000000];

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    int n, m, g;
    scanf("%d%d", &n, &m);   
    memset(a, -1, sizeof(a));
    memset(b, -1, sizeof(b));
    REP (i, n) {
	scanf("%d", &g);
	a[g] = i;
    }    
    REP (i, m) {
	scanf("%d", &g);
	if (a[g] != -1)
	    b[a[g]] = i;
    }
    REP (i, n)
	b[n+i] = b[i];
    int j = 0;
    int cycle = -1;
    int res = 0;
    REP (i, n) if (b[i] != -1) {
	if (j < i)
	    j = i;
	if (i == cycle) cycle = -1;
    ulala:
	while (b[j+1] != -1 && b[j+1] > b[j] && (cycle == -1 || b[j+1] < b[i])) {
	    ++j;
	}
	if (cycle == -1 && b[j+1] != -1 && b[j+1] < b[i]) {
	    cycle = j+1;
	    ++j;
	    goto ulala;
	}
	res = max(res, j-i+1);
    }
    cout << res << endl;
    return 0;
}