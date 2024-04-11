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
  int x, y, z, t1, t2, t3;
  scanf("%d%d%d%d%d%d", &x, &y, &z, &t1, &t2, &t3);
  int stair = abs(x-y) * t1;
  int elev = abs(x-z) * t2 + t3 + t3 + abs(x-y) * t2 + t3;
  if(stair >= elev) printf("YES\n");
  else printf("NO\n");
}