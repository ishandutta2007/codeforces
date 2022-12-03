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

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
#endif
  long double a, b, c, d;
  cin >> a >> b >> c >> d;
  long double b1 = 0, b2 = 1e100;
  REP (it, 10000) {
    long double p = (b1 + b2) / 2;

    vector<long double> A, B;
    A.pb((a - p) * (d - p));
    A.pb((a + p) * (d - p));
    A.pb((a - p) * (d + p));
    A.pb((a + p) * (d + p));
    sort(all(A));

    B.pb((b - p) * (c - p));
    B.pb((b + p) * (c - p));
    B.pb((b - p) * (c + p));
    B.pb((b + p) * (c + p));
    sort(all(B));

    if (A[0] - B.back() <= 0 && A.back() - B[0] >= 0) b2 = p; else b1 = p;
  }
  printf("%.12lf\n", (double) (b1+b2)/2);
  return 0;
}