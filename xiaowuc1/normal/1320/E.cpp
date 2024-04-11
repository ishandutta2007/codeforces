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
typedef vector<vector<ll>> matrix;

const int MAX_D = 18;
const int MAX_N = 200001;

vector<int> edges[MAX_N];
int depth[MAX_N];
int dfsstart[MAX_N];
int lca[MAX_N][MAX_D];
int n;

int getLCA(int a, int b) {
  if(depth[a] < depth[b]) swap(a, b);
  for(int d = MAX_D-1; d >= 0; d--) {
    if(depth[a] - (1<<d) >= depth[b]) {
      a = lca[a][d];
    }
  }
  for(int d = MAX_D-1; d > 0; d--) {
    if(lca[a][d] != lca[b][d]) {
      a = lca[a][d];
      b = lca[b][d];
    }
  }
  while(a != b) {
    a = lca[a][0];
    b = lca[b][0];
  }
  return a;
}

int vstartloc[MAX_N];
int vspeed[MAX_N];
int cities[MAX_N];
vector<int> important;
int virus, city;

bool sortbystart(int a, int b) {
  return dfsstart[a] < dfsstart[b];
}

vector<int> realEdges[MAX_N];
int dp[MAX_N];
int coveredby[MAX_N];

typedef pair<int, pii> vertex;

void dijkstra() {
  for(int out: important) {
    dp[out] = 1e9;
    coveredby[out] = 0;
  }
  priority_queue<vertex> q; // negative time, <negative virus index, city location>
  for(int i = 1; i <= virus; i++) {
    q.push(vertex(0, pii(-i, vstartloc[i])));
  }
  while(sz(q)) {
    vertex curr = q.top(); q.pop();
    int actualTime = -curr.first;
    int actualVirus = -curr.second.first;
    int currCity = curr.second.second;
    if(actualTime < dp[currCity] || (actualTime == dp[currCity] && actualVirus < coveredby[currCity])) {
      dp[currCity] = actualTime;
      coveredby[currCity] = actualVirus;
      for(int out: realEdges[currCity]) {
        int par = getLCA(out, vstartloc[actualVirus]);
        int dist = depth[vstartloc[actualVirus]] + depth[out] - 2 * depth[par];
        int nt = (dist + vspeed[actualVirus] - 1) / vspeed[actualVirus];
        q.push(vertex(-nt, {-actualVirus, out}));
      }
    }
  }
}

void solveqry() {
  cin >> virus >> city;
  important.clear();
  for(int i = 1; i <= virus; i++) {
    cin >> vstartloc[i] >> vspeed[i];
    important.push_back(vstartloc[i]);
  }
  for(int i = 0; i < city; i++) {
    cin >> cities[i];
    important.push_back(cities[i]);
  }
  sort(all(important), sortbystart);
  important.resize(unique(all(important)) - important.begin());
  int orig = sz(important);
  for(int i = 1; i < orig; i++) {
    important.push_back(getLCA(important[i-1], important[i]));
  }
  sort(all(important), sortbystart);
  important.resize(unique(all(important)) - important.begin());
  for(int out: important) realEdges[out].clear();
  stack<int> s;
  for(int out: important) {
    int parent = -1;
    while(sz(s)) {
      int candPar = s.top();
      if(getLCA(candPar, out) != candPar) {
        s.pop();
        continue;
      }
      parent = candPar;
      break;
    }
    if(parent >= 0) {
      realEdges[parent].push_back(out);
      realEdges[out].push_back(parent);
    }
    s.push(out);
  }
  dijkstra();
  for(int i = 0; i < city; i++) {
    if(i) cout << " "; cout << coveredby[cities[i]];
  } cout << "\n";
}

void dfs(int curr, int par, int& internal) {
  dfsstart[curr] = internal++;
  for(int out: edges[curr]) {
    if(out == par) continue;
    depth[out] = depth[curr] + 1;
    lca[out][0] = curr;
    dfs(out, curr, internal);
  }
}

void solve() {
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  {
    int internal = 0;
    dfs(1, -1, internal);
    lca[1][0] = 1;
  }
  for(int d = 1; d < MAX_D; d++) {
    for(int i = 1; i <= n; i++) {
      lca[i][d] = lca[lca[i][d-1]][d-1];
    }
  }
  int q;
  cin >> q;
  while(q--) solveqry();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}