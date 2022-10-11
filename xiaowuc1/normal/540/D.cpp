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

double dp[105][105][105];
double solve(int a, int b, int c) {
  if(dp[a][b][c] >= 0) return dp[a][b][c];
  if(a == 0) return 0;
  if(b == 0 && c == 0) return 1;
  ll tot = (a*b)+(b*c)+(c*a);
  dp[a][b][c] = 0;
  if(a && b) dp[a][b][c] += solve(a, b-1, c) * (a*b) / tot;
  if(c && b) dp[a][b][c] += solve(a, b, c-1) * (c*b) / tot;
  if(a && c) dp[a][b][c] += solve(a-1, b, c) * (a*c) / tot;
  return dp[a][b][c];
}
void solve() {
  for(int i = 0; i <= 100; i++) for(int j = 0; j <= 100; j++) for(int k = 0; k <= 100; k++) dp[i][j][k] = -1;
  int a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(12);
  cout << solve(a, b, c) << " ";
  cout << solve(b, c, a) << " ";
  cout << solve(c, a, b) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}