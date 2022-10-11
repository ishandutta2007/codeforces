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

int a[2005];
int b[2005];
int an, bn;

ll aBest[2005];
ll bBest[2005];

int main() {
  scanf("%d%d", &an, &bn);
  for(int i = 0; i < an; i++) {
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < bn; i++) {
    scanf("%d", &b[i]);
  }
  for(int i = 1; i <= 2000; i++) {
    aBest[i] = 1LL << 30;
    bBest[i] = 1LL << 30;
  }
  ll goal;
  scanf("%lld", &goal);
  for(int i = 0; i < an; i++) {
    ll curr = 0;
    for(int j = i; j < an; j++) {
      curr += a[j];
      aBest[j-i+1] = min(aBest[j-i+1], curr);
    }
  }
  for(int i = 0; i < bn; i++) {
    ll curr = 0;
    for(int j = i; j < bn; j++) {
      curr += b[j];
      bBest[j-i+1] = min(bBest[j-i+1], curr);
    }
  }
  int bestArea = 0;
  for(int i = 1; i <= an; i++) {
    for(int j = 1; j <= bn; j++) {
      if(aBest[i] * bBest[j] <= goal) {
        bestArea = max(bestArea, i*j);
      }
    }
  }
  printf("%d\n", bestArea);
}