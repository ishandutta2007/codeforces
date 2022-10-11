#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void die() {
  cout << ":(\n";
  exit(0);
}

void solve() {
  string s;
  cin >> s;
  int leftover = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == 'a') continue;
    leftover++;
  }
  if(leftover%2) die();
  string ret = s.substr(0, (-leftover/2)+(int)s.size());
  vector<char> v;
  for(int i = 0; i < ret.size(); i++) v.push_back(ret[i]);
  for(int i = 0; i < ret.size(); i++) if(ret[i] != 'a') v.push_back(ret[i]);
  if(v.size() != s.size()) die();
  for(int i = 0; i < v.size(); i++) {
    if(v[i] != s[i]) die();
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}