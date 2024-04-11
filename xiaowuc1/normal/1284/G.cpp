#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>
 
#include <unordered_map>
 
using namespace std;
 
// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD
 
typedef long long ll;
typedef pair<int, int> pii;
 
/*
matroid intersection!
 
LHS matroid is tree matroid - an edge is included if and only if it does not cause a cycle
RHS matroid is degree matroid - an edge is included if and only if degree <= 2 is preserved
*/
 
int r, c;
char g[45][45]; // if i%4 == j%4 then deg >= 2
int edgelabels[45][45];
int ufpar[2025];
int currdeg[45][45];
int dx[4]{1,0,-1,0};
int dy[4]{0,1,0,-1};
int numedges;
vector<pii> connectlocs;
 
void flip(pii out) {
  int aa, bb, cc, dd;
  assert((out.first%2!=0) ^ (out.second%2!=0));
  if(out.first%2) {
    aa = out.first-1; bb = out.second;
    cc = out.first+1; dd = out.second;
  }
  else {
    aa = out.first; bb = out.second-1;
    cc = out.first; dd = out.second+1;
  }
  if(g[out.first][out.second] == 'O') {
    g[out.first][out.second] = ' ';
    currdeg[aa][bb]--;
    currdeg[cc][dd]--;
  }
  else {
    assert(g[out.first][out.second] == ' ');
    g[out.first][out.second] = 'O';
    currdeg[aa][bb]++;
    currdeg[cc][dd]++;
  }
}
 
int find(int x) {
  return ufpar[x] == x ? x : (ufpar[x] = find(ufpar[x]));
}
bool merge(int x, int y) {
  x = find(x);
  y = find(y);
  if(x == y) return false;
  ufpar[x] = y;
  return true;
}
 
bool nocycle() {
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      ufpar[i*c+j] = i*c+j;
    }
  }
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(g[i][j] != 'O') continue;
      if(i+1 < r && g[i+1][j] == 'O') if(!merge(i*c+j, (i+1)*c+j)) return false;
      if(j+1 < c && g[i][j+1] == 'O') if(!merge(i*c+j, i*c+j+1)) return false;
    }
  }
  return true;
}
 
vector<int> matroidedges[1500];
 
int par[1500];
bool augment() {
  memset(par, -1, sizeof(par));
  queue<int> q;
  q.push(numedges);
  par[numedges] = -2;
  while(sz(q) && par[numedges+1] < 0) {
    int curr = q.front(); q.pop();
    for(int out: matroidedges[curr]) {
      if(par[out] == -1) {
        par[out] = curr;
        q.push(out);
      }
    }
  }
  if(par[numedges+1] < 0) return false;
  int curr = numedges+1;
  while(par[curr] != numedges) {
    curr = par[curr];
    pii loc = connectlocs[curr];
    flip(loc);
  }
  return true;
}
 
void analyze() {
  assert(nocycle());
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) cout << g[i][j];
    cout << "\n";
  }
  for(int i = 0; i < r; i += 2) {
    for(int j = 0; j < c; j += 2) {
      cout << currdeg[i][j] << " ";
    }
    cout << endl << endl;
  } cout << endl;
}
 
bool findpath() {
  // analyze();
  for(int i = 0; i < numedges + 2; i++) matroidedges[i].clear();
  assert(nocycle());
  for(int i = 0; i < r; i += 2) {
    for(int j = 0; j < c; j += 2) {
      if((i==0 && j==0) || g[i][j] == 'X') continue;
      for(int k = 0; k < 2; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if(g[nx][ny] == 'O') continue;
        int nnx = i + 2 * dx[k];
        int nny = j + 2 * dy[k];
        if(g[nnx][nny] == 'X') continue;
        g[nx][ny] = 'O';
        if(find(i*c+j) != find(nnx*c+nny)) {
          matroidedges[edgelabels[nx][ny]].push_back(numedges+1);
        }
        g[nx][ny] = ' ';
        bool good = true;
        good &= (i % 4 != j % 4) || currdeg[i][j] < 2;
        good &= (nnx%4 != nny%4) || currdeg[nnx][nny] < 2;
        if(good) {
          matroidedges[numedges].push_back(edgelabels[nx][ny]);
        }
      }
    }
  }
  for(int i = 0; i < r; i += 2) {
    for(int j = 0; j < c; j += 2) {
      if((i==0 && j==0) || g[i][j] == 'X') continue;
      for(int k = 0; k < 2; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if(g[nx][ny] != 'O') continue;
        int nnx = i + 2 * dx[k];
        int nny = j + 2 * dy[k];
        if(g[nnx][nny] == 'X') continue;
        assert(edgelabels[nx][ny] >= 0);
        g[nx][ny] = ' '; currdeg[i][j]--; currdeg[nnx][nny]--;
        assert(nocycle());
        for(int a = 0; a < sz(connectlocs); a++) {
          pii out = connectlocs[a];
          if(g[out.first][out.second] == 'O') continue;
          assert(g[out.first][out.second] == ' ');
          int aa, bb, cc, dd;
          assert((out.first%2!=0) ^ (out.second%2!=0));
          if(out.first%2) {
            aa = out.first-1; bb = out.second;
            cc = out.first+1; dd = out.second;
          }
          else {
            aa = out.first; bb = out.second-1;
            cc = out.first; dd = out.second+1;
          }
          if(find(aa*c+bb) != find(cc*c+dd)) {
            matroidedges[a].push_back(edgelabels[nx][ny]);
          }
          bool good = true;
          if(aa == 0 && bb == 0) continue;
          if(cc == 0 && dd == 0) continue;
          good &= (aa % 4 != bb % 4) || currdeg[aa][bb] < 2;
          good &= (cc % 4 != dd % 4) || currdeg[cc][dd] < 2;
          if(good) {
            matroidedges[edgelabels[nx][ny]].push_back(a);
          }
        }
        g[nx][ny] = 'O'; currdeg[i][j]++; currdeg[nnx][nny]++;
      }
    }
  }
  return augment();
}
 
void initedges() {
  for(int i = 0; i < r; i += 2) {
    for(int j = 0; j < c; j += 2) {
      for(int k = 0; k < 4; k++) {
        if(g[i][j] == 'X') continue;
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        int nnx = i + 2 * dx[k];
        int nny = j + 2 * dy[k];
        if(g[nnx][nny] == 'X') continue;
        if(edgelabels[nx][ny] < 0) {
          edgelabels[nx][ny] = numedges++;
          connectlocs.push_back({nx, ny});
        }
      }
    }
  }
}
 
void rsolve() {
  memset(edgelabels, -1, sizeof(edgelabels));
  memset(currdeg, 0, sizeof(currdeg));
  connectlocs.clear();
  numedges = 0;
  memset(g, ' ', sizeof(g));
  cin >> r >> c;
  int want = 0;
  for(int i = 0; i < r; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < c; j++) {
      g[2*i][2*j] = s[j];
      if((2*i)%4 == (2*j)%4 && ((i != 0 || j != 0) && g[2*i][2*j] == 'O')) want++;
    }
  }
  r = 2*r-1;
  c = 2*c-1;
  initedges();
  int num = 0;
  while(findpath()) num++;
  if(num != 2*want) {
    cout << "NO\n";
    return;
  }
  assert(num == 2 * want);
  // fix - build spanning tree
  assert(nocycle());
  for(int i = 0; i < r; i+=2) {
    for(int j = 0; j < c; j+=2) {
      if(g[i][j] == 'X') continue;
      for(int k = 0; k < 2; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c || g[nx][ny] == 'O') continue;
        assert(g[nx][ny] == ' ');
        int nnx = i + 2 * dx[k];
        int nny = j + 2 * dy[k];
        if(g[nnx][nny] == 'X') continue;
        if(find(i*c+j) != find(nnx*c+nny)) {
          g[nx][ny] = 'O';
          merge(i*c+j, nnx*c+nny);
        }
      }
    }
  }
  cout << "YES\n";
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cout << g[i][j];
    }
    cout << "\n";
  }
}
 
void solve() {
  int t;
  cin >> t;
  while(t--) rsolve();
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}