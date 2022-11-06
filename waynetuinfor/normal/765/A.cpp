#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
map<pair<int, int>, int> mm;
int N, it;
string ss[105], home;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  cin >> home;
  m[home] = ++it;
  for (int i = 0; i < N; ++i) {
    cin >> ss[i];
    string s = ss[i];
    if (m.find(s.substr(0, 3)) == m.end()) m[s.substr(0, 3)] = ++it;
    if (m.find(s.substr(5, 3)) == m.end()) m[s.substr(5, 3)] = ++it;
    mm[make_pair(m[s.substr(0, 3)], m[s.substr(5, 3)])]++;
  }
  for (int i = 0; i < N; ++i) {
    if (mm[make_pair(m[ss[i].substr(0, 3)], m[ss[i].substr(5, 3)])]) {
      if (mm[make_pair(m[ss[i].substr(5, 3)], m[ss[i].substr(0, 3)])]) {
        mm[make_pair(m[ss[i].substr(0, 3)], m[ss[i].substr(5, 3)])]--;
        mm[make_pair(m[ss[i].substr(5, 3)], m[ss[i].substr(0, 3)])]--;
      } else return cout << "contest\n", 0;
    }
  }
  cout << "home\n";
  return 0;
}