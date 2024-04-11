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

struct node {
  int sz;
  bool isdirty;
  node* child[26];
};

struct compareNodePointers {
  bool operator()(node* a, node* b) {
    return a->sz < b->sz;
  }
};

node* makenode() {
  node* ret = new node;
  ret->sz = 0;
  ret->isdirty = false;
  memset(ret->child, 0, sizeof(ret->child));
  return ret;
}

node* root;

vector<pii> edges[300005]; // <node, letter>
int depth[300005];

vector<node*> nodesbydepth[300005];
int maxDepth;

void cleanse(node* n) {
  // note - only clean nodes which are dirty!
  if(n == NULL) return;
  if(!n->isdirty) return;
  for(int i = 0; i < 26; i++) cleanse(n->child[i]);
  delete n;
}

node* merge(node* a, node* b) {
  assert(a);
  assert(b);
  node* ret = makenode();
  ret->sz = 1;
  ret->isdirty = true;
  for(int i = 0; i < 26; i++) {
    if(a->child[i] == NULL && b->child[i] == NULL) continue;
    if(a->child[i] && b->child[i]) {
      ret->child[i] = merge(a->child[i], b->child[i]);
    }
    else if(a->child[i]) {
      ret->child[i] = a->child[i];
    }
    else {
      ret->child[i] = b->child[i];
    }
    ret->sz += ret->child[i]->sz;
  }
  return ret;
}

node* finalsize(vector<node*>& v) {
  assert(sz(v));
  if(sz(v) == 1) return v[0];
  priority_queue<node*, vector<node*>, compareNodePointers> q;
  for(auto out: v) q.push(out);
  while(sz(q) > 1) {
    node* a = q.top(); q.pop();
    node* b = q.top(); q.pop();
    q.push(merge(a, b));
  }
  assert(sz(q) == 1);
  return q.top();
}

int improve(int d) {
  int ans = 0;
  for(node* cand: nodesbydepth[d-1]) {
    vector<node*> temp;
    for(int i = 0; i < 26; i++) {
      if(cand->child[i]) temp.push_back(cand->child[i]);
    }
    if(sz(temp)) {
      node* ret = finalsize(temp);
      for(int i = 0; i < 26; i++) if(ret->child[i]) {
        ans += ret->child[i]->sz;
      }
      cleanse(ret);
    }
  }
  return ans;
}

void dfs(node* curr, int v) {
  curr->sz = 1;
  maxDepth = max(maxDepth, depth[v]);
  for(pii out: edges[v]) {
    if(depth[out.first] < 1 + depth[v]) continue;
    depth[out.first] = 1 + depth[v];
    if(curr->child[out.second] == NULL) curr->child[out.second] = makenode();
    dfs(curr->child[out.second], out.first);
    curr->sz += curr->child[out.second]->sz;
  }
  nodesbydepth[depth[v]].push_back(curr);
}

void solve() {
  root = makenode();
  int n;
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    string s;
    cin >> a >> b >> s;
    edges[a].push_back(pii(b, s[0] - 'a'));
    edges[b].push_back(pii(a, s[0] - 'a'));
  }
  memset(depth, 1, sizeof(depth));
  depth[1] = 0;
  dfs(root, 1);
  int ans = 1e9;
  int from = -1;
  for(int i = 1; i <= maxDepth; i++) {
    int orig = 0;
    for(node* out: nodesbydepth[i]) orig += out->sz;
    int improvement = orig - improve(i);
    if(n - improvement < ans) {
      ans = n - improvement;
      from = i;
    }
  }
  cout << ans << "\n";
  cout << from << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}