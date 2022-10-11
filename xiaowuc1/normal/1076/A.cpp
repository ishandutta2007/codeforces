#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
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

void solve() {
  string s;
  cin >> s >> s;
  bool flag = true;
  for(int i = 0; i < s.size(); i++) if(!flag || (flag = (i < s.size()-1 && s[i] <= s[i+1]))) cout << s[i];
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}