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

const int mod = 777777777;
const int N = 1<<17;

int trans[4][3][3];
int n, m;
int t[3][3];
int tree[2*N][3][3];
	      
void mult(int a[3][3], int b[3][3], int c[3][3]) {
  static int d[3][3];
  REP (i, 3) REP (j, 3) d[i][j] = 0;
  REP (k, 3) {
    REP (i, 3) {
      REP (j, 3) {
	d[i][j] = (d[i][j] + (ll) b[i][k] * c[k][j]) % mod;
      }
    }
  }
  REP (i, 3) REP (j, 3) a[i][j] = d[i][j];
}

inline void calc(int i) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  mult(tree[i], tree[l], t);
  mult(tree[i], tree[i], tree[r]);
}

void build(int p, int l, int r) {
  if (l + 1 == r) {
    memcpy(tree[p], trans[0], sizeof(tree[p]));
    return;
  }
  build(2*p+1, l, (l + r) / 2);
  build(2*p+2, (l + r) / 2, r);
  calc(p);
}

void change(int pos, int val, int node, int l, int r) {
  if (l + 1 == r) {
    memcpy(tree[node], trans[val], sizeof(tree[node]));
    return;
  }
  if (pos < (l + r) / 2) {
    change(pos, val, 2 * node + 1, l, (l + r) / 2);
  } else {
    change(pos, val, 2 * node + 2, (l + r) / 2, r);
  }
  calc(node);
}

void gen_test() {
  freopen("input.txt", "w", stdout);
  cout << N << ' ' << N << endl;
  REP (i, 3) {
    REP (j, 3) {
      cout << rand()%2 << ' ';
    }
    cout << endl;
  }
  REP (i, N) {
    cout << (rand() % N + 1) << ' ' << rand()%4 << endl;
  }
  exit(0);
}

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  //  gen_test();
  cin >> n >> m;
  REP (i, 3) REP (j, 3) cin >> t[i][j];
  REP (i, 3) trans[0][i][i] = 1;
  REP (k, 3) {
    trans[k+1][k][k] = 1;
  }
  build(0, 0, n);
  REP (i, m) {
    int pos, val;
    cin >> pos >> val;
    pos--;
    change(pos, val, 0, 0, n);
    long long res = 0;
    REP (q, 3) REP (w, 3) res += tree[0][q][w];
    cout << (res%mod) << endl;
  }
  return 0;
}