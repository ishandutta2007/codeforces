#include <bits/stdc++.h>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);

ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/
using namespace std;

const double PI = 2 * acos(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<ll>> matrix;

int n, m;
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1;

inline int get_value() {
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}

map<vector<int>, int> cache;
int get_size(vector<int> v) {
  sort(v.begin(), v.end());
  if(cache.count(v)) return cache[v];
  if(v.size() <= 1) return 0;
  printf("? %d\n", v.size());
  for(int out: v) {
    printf("%d ", out);
  }
  printf("\n");
  return cache[v] = get_value();
}

int dp[605];
int par[605];

void die(int a, int b) {
  vector<int> ra;
  vector<int> rb;
  while(a != b) {
    ra.push_back(a);
    rb.push_back(b);
    a = par[a];
    b = par[b];
  }
  int root = a;
  vector<int> ret;
  for(int i = ra.size()-1; i >= 0; i--) {
    ret.push_back(ra[i]);
  }
  for(int out: rb) {
    ret.push_back(out);
  }
  ret.push_back(root);
  printf("N %d\n", ret.size());
  for(int out: ret) {
    printf("%d ", out);
  }
  printf("\n");
  fflush(stdout);
  exit(0);
}

void analyze(vector<int>& v, int x) {
  for(int out: v) {
    if(out == x) continue;
    int m = get_size({out, x});
    if(m) die(out, x);
  }
  assert(false);
}

void die(vector<int>& v) {
  for(int sz = v.size()-1; sz >= 0; sz--) {
    vector<int> temp;
    for(int i = 0; i < sz; i++) {
      temp.push_back(v[i]);
    }
    int vv = get_size(temp);
    if(vv) continue;
    analyze(v, v[sz]);
  }
  assert(false);
}

void check() {
  int maxV = 0;
  for(int i = 1; i <= n; i++) {
    maxV = max(maxV, dp[i]);
  }
  for(int a = 1; a <= maxV; a++) {
    vector<int> v;
    for(int i = 1; i <= n; i++) {
      if(dp[i] == a) {
        v.push_back(i);
      }
    }
    int m = get_size(v);
    if(m == 0) continue;
    die(v);
  }
}

vector<int> getCands(vector<int>& cands, int s) {
  int m1 = get_size(cands);
  cands.push_back(s);
  int m2 = get_size(cands);
  cands.pop_back();
  vector<int> ret;
  if(m2 - m1 == cands.size()) {
    for(int out: cands) {
      ret.push_back(out);
    }
    return ret;
  }
  else if(m2 == m1) {
    return ret;
  }
  int expect = m2 - m1;
  vector<int> a, b;
  for(int i = 0; i < cands.size(); i++) {
    if(i%2) a.push_back(cands[i]);
    else b.push_back(cands[i]);
  }
  for(int out: getCands(a, s)) {
    ret.push_back(out);
  }
  if(ret.size() != expect) {
    for(int out: getCands(b, s)) {
      ret.push_back(out);
    }
  }
  return ret;
}

void bfs() {
  queue<int> q;
  q.push(1);
  dp[1] = 0;
  for(int i = 2; i <= n; i++) {
    dp[i] = 1 << 25;
  }
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    vector<int> cands;
    for(int i = 1; i <= n; i++) {
      if(dp[i] != 1 << 25) continue;
      cands.push_back(i);
    }
    // shuffle(cands.begin(), cands.end(), g1);
    vector<int> all = getCands(cands, curr);
    for(int out: all) {
      dp[out] = dp[curr] + 1;
      par[out] = curr;
      q.push(out);
    }
  }
}

int main() {
  g1.seed(seed1);
  scanf("%d", &n);
  if(n <= 2) {
    printf("Y 1\n1\n");
    return 0;
  }
  bfs();
  check();
  vector<int> evens;
  for(int i = 1; i <= n; i++) {
    if(dp[i]%2 == 0) {
      evens.push_back(i);
    }
  }
  printf("Y %d\n", evens.size());
  for(int out: evens) {
    printf("%d ", out);
  }
  printf("\n");
  return 0;
}