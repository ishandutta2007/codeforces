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

const int RAGETREE_SZ = 1 << 19;
int bit[RAGETREE_SZ];
void upd(int idx, int val) {
  idx += 2;
  while(idx < RAGETREE_SZ) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}
int qry(int idx) {
  idx += 2;
  int ret = 0;
  while(idx) {
    ret += bit[idx];
    idx -= idx & -idx;
  }
  return ret;
}

const int K = 26;

struct node {
  node* next[K]; // descendant node
  node* go[K]; // failure if appending char, may point to next if included
  node* p = NULL;
  int pch = '$';
  node* link = NULL;
  int start;
  int sz;
};
node* go(node* n, int c);
node* get_link(node* n);

node* root;
map<node*, vector<node*>> suffixlinks;

inline void buildeulertour(node* curr, int& idx) {
  curr->start = idx++;
  curr->sz = 1;
  for(auto out: suffixlinks[curr]) {
    buildeulertour(out, idx);
    curr->sz += out->sz;
  }
}
void prop(node* n) {
  if(n == NULL) return;
  if(n != root) {
    suffixlinks[get_link(n)].push_back(n);
  }
  for(int i = 0; i < 26; i++) prop(n->next[i]);
}
void buildeulertour() {
  int idx = 0;
  prop(root);
  buildeulertour(root, idx);
}

node* makenode(node* p, int pch) {
  node* ret = new node;
  memset(ret->next, 0, sizeof(ret->next));
  memset(ret->go, 0, sizeof(ret->go));
  ret->p = p;
  ret->pch = pch;
  ret->link = NULL;
  return ret;
}

node* add_string(string const& s) {
  node* curr = root;
  for(char ch : s) {
    int c = ch - 'a';
    if(curr->next[c] == NULL) {
      curr->next[c] = makenode(curr, c);
    }
    curr = curr->next[c];
  }
  return curr;
}

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
    else n->go[c] = (n == root ? root : go(get_link(n), c));
  }
  return n->go[c];
}

int trie[400005][26];
int querytotriemap[400005];
vector<int> actualnodes[400005];
int numtrienodes = 1;

void buildtrie() {
  memset(trie, -1, sizeof(trie));
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    int from = 0;
    if(x == 2) {
      cin >> from;
      from = querytotriemap[from];
    }
    string s;
    cin >> s;
    int use = s[0] - 'a';
    if(trie[from][use] == -1) {
      trie[from][use] = numtrienodes++;
    }
    querytotriemap[i] = trie[from][use];
    actualnodes[querytotriemap[i]].push_back(i);
  }
}

vector<int> stringtoqueryindex[400005];
int queryid[400005];
string src[400005];
node* sourcenode[400005];
int ret[400005];
int qq;
void getqueries() {
  cin >> qq;
  root = makenode(NULL, -1);
  for(int i = 0; i < qq; i++) {
    cin >> queryid[i] >> src[i];
    stringtoqueryindex[queryid[i]].push_back(i);
    sourcenode[i] = add_string(src[i]);
  }
  buildeulertour();
}

void dfs(node* curr, int trienode) {
  upd(curr->start, 1);
  for(int actualnode: actualnodes[trienode]) {
    for(int queryidx: stringtoqueryindex[actualnode]) {
      ret[queryidx] = qry(sourcenode[queryidx]->start + sourcenode[queryidx]->sz - 1) - qry(sourcenode[queryidx]->start - 1);
    }
  }
  for(int i = 0; i < 26; i++) {
    if(trie[trienode][i] >= 0) {
      dfs(go(curr, i), trie[trienode][i]);
    }
  }
  upd(curr->start, -1);
}

void solvequeries() {
  dfs(root, 0);
  for(int i = 0; i < qq; i++) cout << ret[i] << "\n";
}

void solve() {
  buildtrie();
  getqueries();
  solvequeries();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}