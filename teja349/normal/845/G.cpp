//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx


using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);  
 
const int N = 200010;
 
vector <int> g[N];
int from[N], to[N], cost[N];
int comp[N], to_root[N];
vector <int> cycles[N];
vector < pair <int, int> > base[N];
 
void dfs(int v) {
  int sz = g[v].size();
  for (int j = 0; j < sz; j++) {
    int id = g[v][j];
    int u = from[id] + to[id] - v;
    if (comp[u] != -1) {
      continue;
    }
    comp[u] = comp[v];
    to_root[u] = to_root[v] ^ cost[id];
    dfs(u);
  }
}
 
vector < pair <int, int> > fix(vector <int> &cycles) {
  int sz = cycles.size();
  vector < pair <int, int> > base;
  for (int bit = 30; bit >= 0; bit--) {
    for (int i = 0; i < sz; i++) {
      if (cycles[i] & (1 << bit)) {
        base.push_back(make_pair(1 << bit, cycles[i]));
        for (int j = 0; j < sz; j++) {
          if (j != i && cycles[j] & (1 << bit)) {
            cycles[j] ^= cycles[i];
          }
        }
        cycles[i] = 0;
        break;
      }
    }
  }
  return base;
}
 
int main() {
  int n, m, tt=1;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", from + i, to + i, cost + i);
    from[i]--; to[i]--;
    g[from[i]].push_back(i);
    g[to[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    comp[i] = -1;
  }
  int nc = 0;
  for (int i = 0; i < n; i++) {
    if (comp[i] != -1) {
      continue;
    }
    comp[i] = nc;
    to_root[i] = 0;
    dfs(i);
    cycles[nc].clear();
    nc++;
  }
  for (int i = 0; i < m; i++) {
    int cur = cost[i] ^ to_root[from[i]] ^ to_root[to[i]];
    if (cur != 0) {
      cycles[comp[from[i]]].push_back(cur);
    }
  }
  for (int i = 0; i < nc; i++) {
    base[i] = fix(cycles[i]);
  }
  while (tt--) {
    int x=1, y=n;

    
    x--; y--;
    if (comp[x] != comp[y]) {
      puts("XIT");
      continue;
    }
    int need = to_root[x] ^ to_root[y];
    int c = comp[x];
    for (int i = 0; i < (int) base[c].size(); i++) {
      pair <int, int> p = base[c][i];
      if (need & p.first) {
        need ^= p.second;
      }
    }
    printf("%d\n", need);
  }
  return 0;
}