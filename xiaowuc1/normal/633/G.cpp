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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef vector<int> vi;
typedef bitset<1000> bs;

// NO SAD
const int NUM_TERMS = 1 << 17;
bs ragetree[2 * NUM_TERMS];
int ragetreelazy[2 * NUM_TERMS];
int startIdx[100005];
int treesz[100005];
vector<int> edges[100005];
int n, m;

void apply(int idx, int val) {
  val %= m;
  bs temp = (ragetree[idx] << val) | (ragetree[idx] >> (m - val));
  ragetree[idx] = temp;
  if(idx < NUM_TERMS) {
    ragetreelazy[idx] += val;
    ragetreelazy[idx] %= m;
  }
}
void build(int idx) {
  assert(idx >= NUM_TERMS);
  while(idx > 1) {
    idx /= 2;
    bs curr = (((ragetree[2*idx] | ragetree[2*idx+1]) >> (m-ragetreelazy[idx]))) | ((ragetree[2*idx] | ragetree[2*idx+1]) << ragetreelazy[idx]);
    curr |= curr >> m;
    ragetree[idx] = curr;
  }
}
void push(int idx) {
  assert(idx >= NUM_TERMS);
  for(int i = 17; i > 0; i--) {
    int curr = idx >> i;
    if(ragetreelazy[curr]) {
      apply(2*curr, ragetreelazy[curr]);
      apply(2*curr+1, ragetreelazy[curr]);
      ragetreelazy[curr] = 0;
    }
  }
}
void ragetreeinc(int l, int r, int v) {
  l += NUM_TERMS;
  r += NUM_TERMS;
  int origl = l;
  int origr = r;
  while(l <= r) {
    if(l == r) {
      apply(l, v);
      break;
    }
    if(l%2) apply(l++, v);
    if(r%2 == 0) apply(r--, v);
    l /= 2;
    r /= 2;
  }
  build(origl);
  build(origr);
}
bs ragetreeqry(int l, int r) {
  l += NUM_TERMS;
  r += NUM_TERMS;
  push(l);
  push(r);
  bs ret;
  while(l <= r) {
    if(l == r) {
      ret |= ragetree[l];
      break;
    }
    if(l%2) ret |= ragetree[l++];
    if(r%2 == 0) ret |= ragetree[r--];
    l /= 2;
    r /= 2;
  }
  return ret;
}

void dfs(int curr, int par, int& idx) {
  startIdx[curr] = idx++;
  treesz[curr] = 1;
  for(int out: edges[curr]) {
    if(out == par) continue;
    dfs(out, curr, idx);
    treesz[curr] += treesz[out];
  }
}

bool comp[1005];

void solve() {
  cin >> n >> m;
  for(int i = 2; i * i <= m; i++) {
    if(comp[i]) continue;
    for(int j = i*i; j <= m; j += i) comp[j] = true;
  }
  bs primes;
  for(int i = 2; i < m; i++) {
    if(!comp[i]) {
      primes.set(i);
    }
  }
  for(int i = 1; i < 2*NUM_TERMS; i++) {
    ragetree[i].set(0);
  }
  {
    vector<int> init;
    for(int i = 0; i < n; i++) {
      int t;
      cin >> t;
      init.push_back(t);
    }
    for(int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b; a--; b--;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
    int idx = 0;
    dfs(0, -1, idx);
    for(int i = 0; i < n; i++) {
      ragetreeinc(startIdx[i], startIdx[i], init[i]);
    }
  }
  int qq;
  cin >> qq;
  while(qq--) {
    int t;
    cin >> t;
    if(t == 1) {
      int v, x;
      cin >> v >> x;
      v--;
      ragetreeinc(startIdx[v], startIdx[v] + treesz[v] - 1, x);
    }
    else {
      int v;
      cin >> v;
      v--;
      cout << (primes&ragetreeqry(startIdx[v], startIdx[v] + treesz[v] - 1)).count() << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}