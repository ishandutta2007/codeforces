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

int dp[8];
int n;

char buf[10];

int main() {
  scanf("%d", &n);
  for(int i = 1; i < 8; i++) {
    dp[i] = 1e9;
  }
  while(n--) {
    int s;
    scanf("%d %s", &s, buf);
    int m = 0;
    for(int i = 0; i < strlen(buf); i++) {
      m |= 1 << (buf[i] - 'A');
    }
    for(int i = 0; i < 8; i++) {
      dp[i|m] = min(dp[i|m], dp[i] + s);
    }
  }
  if(dp[7] == 1e9) dp[7] = -1;
  printf("%d\n", dp[7]);
}