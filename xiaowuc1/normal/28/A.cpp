#include <bits/stdc++.h>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);

ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/
using namespace std;

const double PI = 2 * acos(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<ll>> matrix;

int x[505];
int y[505];
int lens[505];
int n;

int dist(int a, int b) {
  return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}

void solve(map<int, vector<int>> dp, int start) {
  vector<int> ret;
  for(int i = 0; i < n; i++) ret.push_back(-1);
  for(int i = start; i < n; i += 2) {
    int lhs = (i+n-1)%n;
    int rhs = (i+1)%n;
    int want = dist(lhs, i) + dist(i, rhs);
    if(!dp.count(want)) return;
    ret[i] = dp[want][dp[want].size()-1];
    if(dp[want].size() == 1) dp.erase(want);
    else dp[want].pop_back();
  }
  printf("YES\n");
  for(int i = 0; i < ret.size(); i++) {
    printf("%d", ret[i]);
    if(i+1 == ret.size()) printf("\n");
    else printf(" ");
  }
  exit(0);
}

int main() {
  int m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  map<int, vector<int>> dp;
  for(int i = 1; i <= m; i++) {
    int l;
    scanf("%d", &l);
    dp[l].push_back(i);
  }
  solve(dp, 0);
  solve(dp, 1);
  printf("NO\n");
}