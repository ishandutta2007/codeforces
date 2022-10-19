#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 5;
const int mod = 1e9 + 7;

int dp[N], n, x, y, A[N], k, tot, num[N];
long long l;

namespace {
  int add(int x) {return (x >= mod) ? x - mod : x;}
  int sub(int x) {return (x < 0) ? x + mod : x;}
  void Add(int &x, int y) {x = add(x + y);}
  void Sub(int &x, int y) {x = sub(x - y);}
}

map <int, int> Map, C;

int calc(int x, int y) {
  return x * (tot + 1) + y;
}

int main() {
  cin >> n >> l >> k;
  for(int i = 0; i < n; ++ i) {
    scanf("%d", &A[i]); ++ Map[A[i]];
  }
  for(map < int, int > :: iterator it = Map.begin(); it != Map.end(); ++ it)
    C[it -> first] = ++ tot;
  for(int i = 0; i < n; ++ i) A[i] = C[A[i]], ++ num[A[i]];
  dp[calc(0, 0)] = 1;
  for(int i = 0; i < k; ++ i) {
    int Sum = 0;
    for(int j = 0; j <= tot; ++ j) {
      Add(Sum, dp[calc(i, j)]);
      Add(dp[calc(i + 1, j)], 1LL * num[j] * Sum % mod);
    }
  }
  long long All = l / n;
  int ans = 0;
  memset(num, 0, sizeof(num));
  int Len = l - (l / n) * n;
  for(int i = 0; i < Len; ++ i) ++ num[A[i]];
  for(int i = 1; i <= min(All + (!!(Len)), (long long)k); ++ i)  {
    int Sum = 0;
    for(int j = 0; j <= tot; ++ j) Add(Sum, dp[calc(i, j)]);
    Add(ans, 1LL * (All - i + 1) % mod * Sum % mod);
    //cerr << Sum <<" " << i << " " << All - i + 1 <<  endl;
    Sum = 0;
    //int AAA = 0;
    for(int j = 0; j <= tot; ++ j) {
      Add(Sum, dp[calc(i - 1, j)]);
      Add(ans, 1LL * num[j] * Sum % mod);
    }
    //cerr << ans << endl;
  }
  cout << ans << endl;
}