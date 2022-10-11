#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define derr if(0) cerr
#define f first
#define s second
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

int x[5000];
int y[5000];
int z[5000];
double dist[5000];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];
  double ret = 1e18;
  for(int i = 1; i < n; i++) {
    int xx = x[i] - x[0];
    int yy = y[i] - y[0];
    int zz = z[i] - z[0];
    dist[i] = sqrt(xx*xx+yy*yy+zz*zz);
  }
  for(int i = 1; i < n; i++) {
    for(int j = 1; j < i; j++) {
      double a = dist[i];
      double b = dist[j];
      int xx = x[i] - x[j];
      int yy = y[i] - y[j];
      int zz = z[i] - z[j];
      double d = sqrt(xx*xx+yy*yy+zz*zz);
      if(a > b) swap(a, b);
      // a < b, d
      double take = b-a;
      a += take;
      d -= take;
      ret = min(ret, a + d/2);
    }
  }
  cout << fixed << setprecision(12) << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}