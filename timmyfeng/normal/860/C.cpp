#include <bits/stdc++.h>
using namespace std;

const int N = 300'000;

string str[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  set<int> free;
  set<int> example;
  set<int> regular;

  map<string, int> mp;
  for (int i = 1; i <= n; ++i) {
    str[i] = str[i / 10] + char(i % 10 + '0');
    mp[str[i]] = i;
    free.insert(i);
  }

  for (int i = 0; i < n; ++i) {
    string name;
    bool special;
    cin >> name >> special;

    int id = 0;
    if (mp.count(name) == 0) {
      int nxt = mp.size() + 1u;
      str[nxt] = name;
      mp[name] = nxt;
    }
    id = mp[name];

    if (special) {
      example.insert(id);
    } else {
      regular.insert(id);
    }
    free.erase(id);
  }

  if (free.empty() && (!regular.empty() && *regular.begin() <= int(example.size()))) {
    str[n + 1] = "timmyf";
    mp["timmyf"] = n + 1;
    free.insert(n + 1);
  }

  vector<array<int, 2>> ans;
  while (!free.empty()) {
    int ndx = -1;
    if (*free.begin() <= int(example.size())) {
      ndx = *example.upper_bound(int(example.size()));
      example.insert(*free.begin());
      example.erase(ndx);
    } else {
      ndx = (*regular.begin() <= int(example.size()) ? *regular.begin() : *(--regular.end()));
      regular.insert(*free.begin());
      regular.erase(ndx);
    }

    ans.push_back({ndx, *free.begin()});
    free.erase(free.begin());
    if (ndx <= n) {
      free.insert(ndx);
    }
  }

  cout << ans.size() << "\n";
  for (auto [a, b] : ans) {
    cout << "move " << str[a] << " " << str[b] << "\n";
  }
}