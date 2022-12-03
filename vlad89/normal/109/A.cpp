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

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    REP (i, n/4 + 1)
	if ((n - 4 * i) % 7 == 0 && n - 4 * i >= 0) {
	    REP (j, i)
		printf("4");
	    REP (j, (n - 4 * i) / 7)
		printf("7");
	    printf("\n");
	    return 0;
	}
    printf("-1\n");
    return 0;
}