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
int a[1005];

int x[1005];
int y[1005];
bool valid(int cand) {
  for(int i = 1; i <= cand; i++) {
    x[i-1] = a[i] - a[i-1];
  }
  for(int i = cand+1; i <= n; i++) {
    if(a[i] - a[i-1] != x[(i-1)%cand]) return false;
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  vector<int> ret;
  for(int i = 1; i <= n; i++) {
    if(valid(i)) ret.push_back(i);
  }
  printf("%d\n", ret.size());
  for(int i = 0; i < ret.size(); i++) {
    printf("%d", ret[i]);
    if(i + 1 == ret.size()) printf("\n");
    else printf(" ");
  }
}