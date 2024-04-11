#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int l[20];

void solve() {
  int n;
  cin >> n;
  int ret = 0;
  map<int, int> good;
  map<int, int> bad;
  int zero = 0;
  while(n--) {
    string s;
    cin >> s;
    int down = 0;
    int curr = 0;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == '(') curr++;
      else curr--;
      down = min(down, curr);
    }
    if(down < 0 && down < curr) {
      continue;
    }
    if(curr == 0) zero++;
    else if(curr > 0) good[curr]++;
    else bad[-curr]++;
  }
  for(auto x: good) {
    ret += min(x.second, bad[x.first]);
  }
  ret += zero/2;
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}