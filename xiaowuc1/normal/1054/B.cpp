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

int main() {
  int n;
  scanf("%d", &n);
  set<int> small;
  for(int i = 0; i <= n+5; i++) {
    small.insert(i);
  }
  for(int i = 1; i <= n; i++) {
    int curr;
    scanf("%d", &curr);
    if(curr > *small.begin()) {
      printf("%d\n", i);
      return 0;
    }
    small.erase(curr);
  }
  printf("-1\n");
}