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

int l[105];
int n;

int main() {
  scanf("%d", &n);
  int add; scanf("%d", &add);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }
  sort(l, l+n);
  int maxRet = l[n-1] + add;
  while(add--) {
    l[0]++;
    sort(l, l+n);
  }
  printf("%d %d\n", l[n-1], maxRet);
}