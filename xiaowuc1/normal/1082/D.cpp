#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void die() {
  cout << "NO\n";
  exit(0);
}

void solve() {
  int n;
  cin >> n;
  vector<pii> v;
  v.resize(n);
  int nl = 0;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    v[i] = {t, i+1};
    if(t == 1) nl++;
  }
  sort(v.begin(), v.end());
  vector<pii> edges;
  while(v.size() > 1) {
    if(v[1].first > 1) {
      for(int i = 0; i + 1 < v.size(); i++) {
        edges.push_back({v[i].second, v[i+1].second});
      }
      break;
    }
    if(v[v.size()-1].first == 1 && v.size() > 2) {
      die();
    }
    edges.push_back({v[0].second, v[v.size()-1].second});
    if(v.size() == 2) break;
    v[v.size()-1].first--;
    if(v[v.size()-1].first == 1) {
      v[0] = v[v.size()-1];
      v.pop_back();
    }
    else {
      v.erase(v.begin());
    }
  }
  cout << "YES " << min(n-1, n - nl + 1) << "\n";
  cout << edges.size() << "\n";
  for(pii out: edges) {
    cout << out.first << " " << out.second << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}