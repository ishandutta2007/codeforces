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

const int L = 1000000;
const int maxsg = 4;
int sg[L];
int saw[L];
int countsg[L][maxsg + 1];

long long myexp4(long long x) {
  long long y = pow(x, 0.25);
  if (y * y * y * y < x) ++y;
  return y;
}

long long myexp2(long long x) {
  long long y = sqrt(x + 0.0);
  if ((y + 1) * (y + 1) <= x) ++y;
  return y;
}


int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
#endif
  for (int i = 1; i < L; ++i) {
    ll x = myexp4(i);
    ll y = min(myexp2(i), (long long) (i - 1));
    FOR (j, x, y + 1)
      saw[sg[j]] = i;
    while (saw[sg[i]] == i) sg[i]++;
    REP (j, maxsg + 1)
      countsg[i][j] = countsg[i-1][j];
    countsg[i][sg[i]]++;
    // static int maxsg = 0;
    // if (sg[i] > maxsg) {
    //   maxsg = sg[i];
    //   cout << maxsg << endl;
    // }
    // if (sg[i] == 3) cout << i << endl;
  }
  int n;
  cin >> n;
  int xorres = 0;
  REP (j, n) {
    ll i;
    cin >> i;
    ll x = myexp4(i);
    ll y = myexp2(i);
    y = min(y, i-1);
    if (x <= y) {
      int sgi = 0;
      while (countsg[y][sgi] != countsg[x-1][sgi]) ++sgi;
      xorres ^= sgi;
    }
  }
  //  cout << xorres << endl;
  if (xorres) cout << "Furlo" << endl; else cout << "Rublo" << endl;
  return 0;
}