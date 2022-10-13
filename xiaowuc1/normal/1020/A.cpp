#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  int n, h, a, b, k;
  cin >> n >> h >> a >> b >> k;
  while(k--) {
    int ta, fa, tb, fb;
    cin >> ta >> fa >> tb >> fb;
    int ret = abs(ta - tb);
    if(ta != tb) {
      if(fa > b) {
        ret += fa-b;
        fa = b;
      }
      else if(fa < a) {
        ret += a - fa;
        fa = a;
      }
    }
    ret += abs(fa - fb);
    cout << ret << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}