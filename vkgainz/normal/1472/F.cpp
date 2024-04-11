#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 5e5+5;

int main() {
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> in;
    for(int i=0;i<m;i++) {
      int r, c; cin >> r >> c;
      in.push_back({c, r});
    }
    in.push_back({0, 1});
    in.push_back({0, 2});
    in.push_back({n+1, 1});
    in.push_back({n+1, 2});

    sort(in.begin(), in.end());
    int top = n+2, bot = n+2;
    bool work = true;
    while(!in.empty() && work) {
      int currcol = in.back().f;
      int currrow = in.back().s;
      in.pop_back();
      if(in.size() > 0 && in.back().f==currcol) {
        work = work&&(top%2 == bot%2);
        top = currcol - 1, bot = currcol - 1;
        in.pop_back();
      }
      else {
        if(currrow == 1) {
          if(top%2 == bot%2) {
            bot = currcol;
          }
          else {
            work = work&&(top%2 == currcol%2);
            if(bot%2 == currcol%2) bot = currcol;
            else bot = currcol - 1;
          }
          top = currcol - 1;
        }
        else {
          if(top%2 == bot%2) {
            top = currcol;
          }
          else {
            work = work&&(bot%2 == currcol%2);
            if(top%2 == currcol%2) top = currcol;
            else top = currcol - 1;
          }
          bot = currcol - 1;
        }
      }
    }
    if(work) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
}