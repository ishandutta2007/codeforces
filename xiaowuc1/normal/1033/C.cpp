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
int l[100005];
bool win[100005];
bool done[100005];
int main() {
  scanf("%d", &n);
  vector<pii> all;
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
    all.push_back(pii(l[i], i));
  }
  sort(all.begin(), all.end());
  reverse(all.begin(), all.end());
  for(pii out: all) {
    int idx = out.second;
    int diff = out.first;
    for(int a = 1; !win[idx] && idx + diff * a < n; a++) {
      int nd = idx + diff * a;
      if(!win[nd] && done[nd]) {
        win[idx] = true;
      }
    }
    for(int a = 1; !win[idx] && idx - diff * a >= 0; a++) {
      int nd = idx - diff * a;
      if(!win[nd] && done[nd]) {
        win[idx] = true;
      }
    }
    done[idx] = true;
  }
  for(int i = 0; i < n; i++) {
    if(win[i]) printf("A");
    else printf("B");
  }
  printf("\n");
}