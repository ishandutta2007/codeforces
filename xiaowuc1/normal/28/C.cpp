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

int total;
int n;
double choose[55][55][55];
int l[51];

double dp[51][51];

double solve(int maxLen) {
  for(int a = 0; a <= n; a++) {
    for(int b = 0; b <= total; b++) {
      dp[a][b] = 0;
    }
  }
  dp[0][total] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= total; j++) {
      for(int k = 0; k <= j; k++) {
        int num = k;
        int denom = l[i];
        if((num+denom-1)/denom > maxLen) break;
        dp[i+1][j-k] += dp[i][j] * choose[n-i][j][k];
      }
    }
  }
  return dp[n][0];
}

void init() {
  for(int x = 1; x <= n; x++) {
    choose[x][0][0] = 1;
    for(int a = 0; a <= 50; a++) {
      for(int b = 0; b <= a; b++) {
        choose[x][a+1][b+1] += choose[x][a][b] * (1.0/x);
        choose[x][a+1][b] += choose[x][a][b] * ((x-1.)/x);
      }
    }
  }
}

int main() {
  scanf("%d%d", &total, &n);
  init();
  set<double> poss;
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }
  double ret = 0;
  double lastP = 0;
  for(int i = 1; i <= total; i++) {
    double pp = solve(i);
    ret += i * (pp - lastP);
    lastP = pp;
  }
  printf("%.12f\n", ret);
}