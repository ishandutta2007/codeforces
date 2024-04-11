#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

map<ll, ll> tldp[25][25];
map<ll, ll> brdp[25][25];
bool blocked[25][25];
int r, c;
ll k;
ll g[25][25];

void solve() {
  cin >> r >> c >> k;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> g[i][j];
      if(i+j == r-1) blocked[i][j] = true;
    }
  }
  tldp[0][0][g[0][0]]++;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(blocked[i][j]) break;
      for(auto x: tldp[i][j]) {
        if(i+1 < r) tldp[i+1][j][x.first ^ g[i+1][j]] += x.second;
        if(j+1 < c) tldp[i][j+1][x.first ^ g[i][j+1]] += x.second;
      }
    }
  }
  brdp[r-1][c-1][g[r-1][c-1]]++;
  for(int i = r-1; i >= 0; i--) {
    for(int j = c-1; j >= 0; j--) {
      if(blocked[i][j]) break;
      for(auto x: brdp[i][j]) {
        if(i-1 >= 0) brdp[i-1][j][x.first ^ g[i-1][j]] += x.second;
        if(j-1 >= 0) brdp[i][j-1][x.first ^ g[i][j-1]] += x.second;
      }
    }
  }
  ll ret = 0;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(blocked[i][j]) {
        for(auto x: tldp[i][j]) {
          if(brdp[i][j].count(x.first^g[i][j]^k)) {
            ret += x.second * brdp[i][j][x.first^g[i][j]^k];
          }
        }
      }
    }
  }
  cout << ret << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}