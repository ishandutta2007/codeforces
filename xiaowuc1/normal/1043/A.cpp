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

int n;
int l[105];
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }
  sort(l, l+n);
  int k = l[n-1];
  while(true) {
    int lhs = 0;
    int rhs = 0;
    for(int i = 0; i < n; i++) {
      lhs += l[i];
      rhs += k - l[i];
    }
    if(rhs > lhs) {
      printf("%d\n", k);
      return 0;
    }
    k++;
  }
}