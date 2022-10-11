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

int par[105];
int find(int x) {
  return par[x] == x ? x : (par[x] = find(par[x]));
}
void merge(int x, int y) {
  par[find(x)] = find(y);
}

int perm[105];
int dist[105];
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    par[i] = i;
  }
  for(int i = 1; i <= n; i++) {
    scanf("%d", &perm[i]);
  }
  for(int i = 1; i <= n; i++) {
    scanf("%d", &dist[i]);
    if(i - dist[i] >= 1) merge(i, i-dist[i]);
    if(i + dist[i] <= n) merge(i, i+dist[i]);
  }
  for(int i = 1; i <= n; i++) {
    if(find(i) != find(perm[i])) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
}