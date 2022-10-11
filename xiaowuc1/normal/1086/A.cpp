#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;

pii l[3];

int median(int a, int b, int c) {
  return a + b + c - min(a, min(b, c)) - max(a, max(b, c));
}

void solve() {
  cin >> l[0].first >> l[0].second;
  cin >> l[1].first >> l[1].second;
  cin >> l[2].first >> l[2].second;
  int xmed = median(l[0].first, l[1].first, l[2].first);
  int ymed = median(l[0].second, l[1].second, l[2].second);
  set<pii> all;
  for(int i = 0; i < 3; i++) {
    for(int x = min(l[i].first, xmed); x <= max(l[i].first, xmed); x++) {
      all.insert({x, l[i].second});
    }
    for(int y = min(l[i].second, ymed); y <= max(l[i].second, ymed); y++) {
      all.insert({xmed, y});
    }
  }
  cout << all.size() << endl;
  for(pii out: all) {
    cout << out.first << " " << out.second << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}