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

const int mod = 1000000007;
int cnk[1024][1024];

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
#endif
  REP (i, 1024) {
    cnk[i][0] = cnk[i][i] = 1;
    FOR (j, 1, i) cnk[i][j] = (cnk[i-1][j] + cnk[i-1][j-1]) % mod;
  }
  int k;
  cin >> k;
  vi a(k);
  REP (i, k) cin >> a[i];
  int total = 0;
  long long res = 1;
  REP (i, k) {
    res *= cnk[total+a[i]-1][a[i]-1];
    res %= mod;
    total += a[i];
  }
  cout << res << endl;
  return 0;
}