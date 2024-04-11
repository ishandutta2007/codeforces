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

int n;
int lhs[1005];
int rhs[1005];

vector<pii> order;

int ret[1005];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &lhs[i]);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", &rhs[i]);
  }
  for(int i = 0; i < n; i++) {
    order.push_back({lhs[i] + rhs[i], i});
  }
  sort(order.begin(), order.end());
  int last = order[0].first;
  int val = n;
  for(pii out: order) {
    if(out.first != last) val--;
    last = out.first;
    ret[out.second] = val;
  }
  for(int i = 0; i < n; i++) {
    int lll = 0;
    int rrr = 0;
    for(int a = 0; a < n; a++) {
      if(ret[a] > ret[i]) {
        if(a < i) lll++;
        if(a > i) rrr++;
      }
    }
    if(lll != lhs[i] || rrr != rhs[i]) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  for(int i = 0; i < n; i++) {
    printf("%d", ret[i]);
    if(i != n-1) printf(" ");
    else printf("\n");
  }
}