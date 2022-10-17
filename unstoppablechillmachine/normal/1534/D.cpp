#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
 
mt19937 rnd(time(0));

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  auto ask = [n](int v) {
    cout << "? " << v << endl;
    vector<int> result(n);
    for (auto &it : result) {
      cin >> it;
    }
    return result;
  };
  auto guess = [](vector<pair<int, int>> &edges) {
    cout << "!" << endl;
    for (auto it : edges) {
      cout << it.first << ' ' << it.second << endl;
    }
  };
  vector<int> current = ask(1);
  vector<int> cnt(2);
  vector<pair<int, int>> edges;
  for (int i = 1; i < n; i++) {
    cnt[current[i] % 2]++;
    if (current[i] == 1) {
      edges.pb({1ll, i + 1});
    }
  }
  int par = 0;
  if (cnt[0] > cnt[1]) {
    par = 1;
  } 
  for (int i = 1; i < n; i++) {
    if (current[i] % 2 == par) {
      vector<int> kek = ask(i + 1);
      for (int j = 0; j < n; j++) {
        if (kek[j] == 1) {
          edges.pb({min(i + 1, j + 1), max(i + 1, j + 1)});
        }
      }
    }
  }
  sort(all(edges));
  edges.resize(unique(all(edges)) - edges.begin());
  guess(edges);
}