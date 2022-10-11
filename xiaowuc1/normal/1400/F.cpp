#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
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
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

const int K = 9;

struct node {
  node* next[K]; // descendant node
  node* go[K]; // failure if appending char, may point to next if included
  bool leaf = false;
  node* p = NULL;
  int pch = '$';
  node* link = NULL;
};

node* root;
node* makenode(node* p, int pch) {
  node* ret = new node;
  memset(ret->next, 0, sizeof(ret->next));
  memset(ret->go, 0, sizeof(ret->go));
  ret->leaf = false;
  ret->p = p;
  ret->pch = pch;
  ret->link = NULL;
  return ret;
}

void add_string(string const& s) {
  node* curr = root;
  for(char ch : s) {
    int c = ch - '1';
    if(curr->next[c] == NULL) {
      curr->next[c] = makenode(curr, c);
    }
    curr = curr->next[c];
  }
  curr->leaf = true;
}

node* go(node* n, int c);

node* get_link(node* n) {
  if(n->link == NULL) {
    if(n == root || n->p == root) n->link = root;
    else n->link = go(get_link(n->p), n->pch);
  }
  return n->link;
}

node* go(node* n, int c) {
  if(n->go[c] == NULL) {
    if(n->next[c] != NULL) n->go[c] = n->next[c];
    else n->go[c] = n == root ? root : go(get_link(n), c);
  }
  return n->go[c];
}

void validate(vector<string>& v, string s, int x) {
  for(int i = 0; i < sz(s); i++) {
    int curr = 0;
    for(int j = i; j < sz(s); j++) {
      curr += s[j] - '0';
      if(curr < x && x % curr == 0) return;
    }
  }
  v.push_back(s);
}

void dfs(vector<string>& v, string cand, int want) {
  int have = 0;
  for(int i = sz(cand)-1; i >= 0; i--) {
    have += cand[i] - '0';
    if(have != want && want % have == 0) return;
  }
  if(have == want) {
    validate(v, cand, want);
    return;
  }
  for(int x = 1; x <= 9 && x <= want - have; x++) dfs(v, cand + to_string(x), want);
}

vector<string> gen(int x) {
  vector<string> ret;
  dfs(ret, "", x);
  return ret;
}

void solve() {
  string s;
  int x;
  cin >> s >> x;
  vector<string> v = gen(x);
  cerr << sz(v) << endl;
  root = makenode(NULL, '$');
  for(string out: v) {
    add_string(out);
  }
  map<node*, int> dp;
  dp[root] = 0;
  for(int i = 0; i < sz(s); i++) {
    map<node*, int> ndp;
    for(auto out: dp) {
      if(!ndp.count(out.f)) ndp[out.f] = out.s+1;
      else ndp[out.f] = min(ndp[out.f], out.s+1);
      // include
      node* next = go(out.f, s[i]-'1');
      if(next->leaf) continue;
      if(!ndp.count(next)) ndp[next] = out.s;
      else ndp[next] = min(ndp[next], out.s);
    }
    dp.swap(ndp);
  }
  int ret = 1e9;
  for(auto out: dp) ret = min(ret, out.s);
  cout << ret << "\n";
}

// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}