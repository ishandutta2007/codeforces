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

int to[1000000];
int n;
int main() {
  scanf("%d", &n);
  for(int i = 2; i <= n; i++) {
    scanf("%d", &to[i]);
  }
  vector<int> ret;
  int curr = n;
  while(curr) {
    ret.push_back(curr);
    curr = to[curr];
  }
  reverse(ret.begin(), ret.end());
  for(int out: ret) {
    printf("%d ", out);
  }
  printf("\n");
}