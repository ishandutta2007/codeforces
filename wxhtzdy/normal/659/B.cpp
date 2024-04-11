#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, m;
  cin >> n >> m;
  map<int, vector<pair<string, int>>> mp;
  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;
    int a, b;
    cin >> a >> b;
    mp[a].push_back({name, b});
  }
  for (int i = 1; i <= m; i++) {
    sort(mp[i].begin(), mp[i].end(), [&](pair<string, int> x, pair<string, int> y) {
      return x.second > y.second;
    });
    if ((int) mp[i].size() >= 3 && mp[i][1].second == mp[i][2].second) {
      cout << "?" << '\n';
    } else {
      cout << mp[i][0].first << " " << mp[i][1].first << '\n';
    }
  }
}