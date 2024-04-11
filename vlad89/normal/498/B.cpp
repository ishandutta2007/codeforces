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

const int N = 5555;
int p[N], t[N];
double d[N][N];
double prob[N];

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    int n, total_t;
    cin >> n >> total_t;
    REP (i, n) {
      cin >> p[i] >> t[i];
      prob[i] = p[i] / 100.0;
    }
    d[0][0] = 1;
    double res = 0;
    REP (j, n) {
      double x = pow(1-prob[j], t[j]-1);
      if (t[j] > 1) {
    double acc = 0;
    FOR (i, 1, total_t+1) {
      acc += d[i-1][j];
      if (i >= t[j]) acc -= d[i-t[j]][j] * x;
      d[i][j+1] += acc * prob[j];
      acc *= 1-prob[j];
      if (acc < 1e-12) acc = 0;
    }
      }
      if (x > 1e-9) {
    REP (i, total_t-t[j]+1) {
      d[i+t[j]][j+1] += d[i][j] * x;
    }
      }
      double c = 1;
      for (int i = total_t-1; i > total_t - t[j] && c > 1e-9; --i) {
    c *= 1-prob[j];
    if (c < 1e-9) break;
    d[total_t][j] += d[i][j] * c;
      }
    }
    REP (j, n+1) {
      res += j * d[total_t][j];
    }
    REP (i, total_t) {
      res += n * d[i][n];
    }
    printf("%.9lf\n", res);
    return 0;
}