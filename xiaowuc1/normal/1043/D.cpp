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
typedef pair<int, ll> pill;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<ll>> matrix;

int g[15][100005];
map<int, int> outdeg[100005];

vector<int> edges[100005];
int par[100005];
int q[100005];
int dp[100005];
int main() {
  int n, r;
  scanf("%d%d", &n, &r);
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%d", &g[i][j]);
      if(j) {
        outdeg[g[i][j-1]][g[i][j]]++;
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    for(auto out: outdeg[i]) {
      if(out.second == r) {
        edges[i].push_back(out.first);
        par[out.first]++;
      }
    }
  }
  int ql = 0;
  int qr = 0;
  for(int i = 1; i <= n; i++) {
    if(par[i] == 0) {
      q[qr++] = i;
    }
  }
  ll ret = 0;
  while(ql < qr) {
    int curr = q[ql++];
    ret += ++dp[curr];
    for(int out: edges[curr]) {
      dp[out] = dp[curr];
      q[qr++] = out;
    }
  }
  printf("%lld\n", ret);
}