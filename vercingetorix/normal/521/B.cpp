#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <deque>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
ll mod=1000000009;

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  int m;
  cin>>m;
  map<pair<int,int>, int> cube;
  set<int> freecubes;
  vvi par(m+1);
  vvi ch(m+1);
  vi ans;
  vi parnum(m+1);
  vi chnum(m+1);
  vb fall(m+1, false);
  int x, y;
  for(int i=1; i<=m; i++) {
      cin>>x>>y;
      cube[mp(x,y)] = i;
      vector<pair<int,int>> a(3),b(3);
      a[0]=mp(x-1, y+1);
      a[1]=mp(x, y+1);
      a[2]=mp(x+1, y+1);
      b[0]=mp(x-1, y-1);
      b[1]=mp(x, y-1);
      b[2]=mp(x+1, y-1);
      for(int j=0; j<3; j++){
          if (cube[a[j]] > 0) {
            par[i].pb(cube[a[j]]);
            ch[cube[a[j]]].pb(i);
          }
      }
      for(int j=0; j<3; j++){
          if (cube[b[j]] > 0) {
            ch[i].pb(cube[b[j]]);
            par[cube[b[j]]].pb(i);
          }
      }
  }
  for(int i=1; i<=m; i++) {
      parnum[i] = par[i].size();
      chnum[i]=ch[i].size();
  }
  for(int i=1; i<=m; i++) {
      bool f = true;
      for(int j=0; j<parnum[i]; j++) {
          if (chnum[par[i][j]] == 1) f = false;
      }
      if (f) freecubes.insert(i);
  }
  for(int i=0; i<m; i++) {
      auto it = freecubes.begin();
      if (i%2 == 0) {
          it = freecubes.end(); 
          it--;
      }
      int del = *it;
      fall[del] = true;
      ans.pb(del-1);
      freecubes.erase(it);
      for(int j=0; j<par[del].size(); j++) {
          chnum[par[del][j]]--;
          if ((!fall[par[del][j]])&&(chnum[par[del][j]]==1)) {
              for (int k=0; k<ch[par[del][j]].size(); k++) {
                  int pot = ch[par[del][j]][k];
                  if (!fall[pot]) {
                      auto itt = freecubes.find(pot);
                      if (itt!=freecubes.end()) freecubes.erase(itt);
                  }
              }
          }
      }
      for(int j=0; j<ch[del].size(); j++) {
          int child = ch[del][j];
          if(fall[child]) continue;
          parnum[child]--;
          bool f = true;
          for(int j=0; j<par[child].size(); j++) {
              if ((!fall[par[child][j]])&&(chnum[par[child][j]] == 1)) f = false;
          }
          if (f) freecubes.insert(child);
      }
  }
  ll pm=1;
  ll anss = 0;
  for(int i=m-1; i>=0; i--) {
      anss = (anss + pm * ans[i]) % mod;
      pm = (pm * m) % mod;
  }
  cout << anss;
  return 0;
}