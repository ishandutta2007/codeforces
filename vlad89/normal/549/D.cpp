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
#include <queue>

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

long long a[128][128];
long long b[128][128];

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  REP (i, n) {
    string s;
    cin >> s;
    REP (j, m) {
      a[i][j] = s[j] == 'B' ? 1 : -1;
    }
  }
  int res = 0;
  for (int i = n-1; i >= 0; --i) {
    for (int j = m-1; j >= 0; -- j) {
      if (a[i][j] != b[i][j]) {
	long long add = a[i][j] - b[i][j];
	REP (q, i+1) {
	  REP (w, j+1) {
	    b[q][w] += add;
	  }
	}
	res++;
      }
    }
  }
  cout << res << endl;
  return 0;
}