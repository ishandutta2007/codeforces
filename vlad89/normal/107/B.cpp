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

const int N = 1024;

int a[N];

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int n, m, h;
    scanf ("%d%d%d", &n, &m, &h);
    int S = 0;
    REP (i, m) {
	scanf ("%d", a+i);
	S += a[i];
    }
    --h;
    a[h]--;
    if (S < n) {
	printf("-1\n");
	return 0;
    }
    --S;
    --n;
    double v = 0.0;
    if (S - a[h] >= n) {
	v = 1.0;
	REP (i, a[h]) {
	    v *= S - n - i;
	    v /= S - i;
	}
    }
    v = 1 - v;
    printf("%.9lf\n", v);
    return 0;
}