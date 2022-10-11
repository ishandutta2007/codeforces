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
typedef pair<pii, pii> ppiipii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<ll>> matrix;

int n;
int l[5005];
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &l[i]);
  int r = 0;
  for(int i = 0; i < n; i++) {
    int c = 0;
    for(int j = i+1; j <= n; j++) {
      c += l[j-1];
      if(c > 100*(j-i)) {
        r = max(r, j-i);
      }
    }
  }
  printf("%d\n", r);
}