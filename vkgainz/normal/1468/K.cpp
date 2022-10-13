#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;
  while(t--) {
    string s; cin >> s;
    int sx = 0, sy = 0;
    vector<pair<int, int>> test;
    for(int i = 0; i < s.length(); i++) {
      if(s[i]=='R') ++sx;
      if(s[i]=='L') --sx;
      if(s[i]=='U') ++sy;
      if(s[i]=='D') --sy;
      test.push_back({sx, sy});
    }
    bool found = false;
    for(auto &obstacle : test) {
      int sx = 0, sy = 0;
      for(int i = 0; i < s.length(); i++) {
        int nx = sx, ny = sy;
        if(s[i]=='R') ++nx;
        if(s[i]=='L') --nx;
        if(s[i]=='U') ++ny;
        if(s[i]=='D') --ny;
        if(nx == obstacle.first && ny == obstacle.second)
          continue;
        sx = nx, sy = ny;
      }
      if(sx == 0 && sy == 0) {
        found = true;
        cout << obstacle.first << " " << obstacle.second << "\n";
        break;
      }
    }
    if(!found) cout << 0 << " " << 0 << "\n";
  }
}