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
typedef pair<ll, ll> pll;

struct node {
  int pos, sz, sum;
  node* lhs;
  node* rhs;
};

node* makenode(int pos, int sz) {
  node* ret = new node;
  ret->pos = pos;
  ret->sz = sz;
  ret->sum = 0;
  ret->lhs = NULL;
  ret->rhs = NULL;
  return ret;
}
const int RAGETREE_SZ = 1 << 17;
inline void pullup(node* ret) {
  ret->sum = ret->lhs->sum + ret->rhs->sum;
}
node* init(int pos, int sz, vector<int>& v) {
  if(sz == 1) {
    node* ret = makenode(pos, sz);
    assert(sz(v) <= 1);
    ret->sum = sz(v);
    return ret;
  }
  vector<int> lhs, rhs;
  for(int out: v) {
    if(out < pos + sz/2) lhs.push_back(out);
    else rhs.push_back(out);
  }
  v.clear();
  node* ret = makenode(pos, sz);
  ret->lhs = init(pos, sz/2, lhs);
  ret->rhs = init(pos + sz/2, sz/2, rhs);
  pullup(ret);
  return ret;
}
node* init(vector<int>& v) { // nodes to send to one
  return init(0, RAGETREE_SZ, v);
}
node* upd(node* root, vector<pii>& changes) {
  if(sz(changes) == 0) return root;
  if(root->sz == 1) {
    node* ret = makenode(root->pos, root->sz);
    ret->sum = root->sum + changes[0].second;
    return ret;
  }
  vector<pii> lhs, rhs;
  for(pii out: changes) {
    if(out.first < root->lhs->pos + root->lhs->sz) lhs.push_back(out);
    else rhs.push_back(out);
  }
  node* ret = makenode(root->pos, root->sz);
  if(sz(lhs)) ret->lhs = upd(root->lhs, lhs);
  else ret->lhs = root->lhs;
  if(sz(rhs)) ret->rhs = upd(root->rhs, rhs);
  else ret->rhs = root->rhs;
  pullup(ret);
  return ret;
}

int qry(node* root, int k) {
  // return the smallest index <= k
  assert(root->sum >= k);
  if(root->sz == 1) return root->pos;
  if(root->lhs->sum >= k) return qry(root->lhs, k);
  return qry(root->rhs, k-root->lhs->sum);
}

vector<int> appears[100005];
int l[100005];
node* roots[100005];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    appears[l[i]].push_back(i);
  }
  vector<int> seed;
  for(int i = 1; i <= n; i++) if(sz(appears[i])) seed.push_back(appears[i][0]);
  roots[0] = init(seed);
  for(int i = 0; i < n; i++) {
    int val = l[i];
    int idx = upper_bound(all(appears[val]), i) - appears[val].begin();
    vector<pii> changes;
    changes.push_back({i, -1});
    if(idx < sz(appears[val])) changes.push_back({appears[val][idx], 1});
    roots[i+1] = upd(roots[i], changes);
  }
  for(int k = 1; k <= n; k++) {
    int start = 0;
    int ret = 1;
    while(roots[start]->sum > k) {
      // cerr << k << " " << start << ": " << ret << endl;
      ret++;
      start = qry(roots[start], k+1);
    }
    if(k > 1) cout << " ";
    cout << ret;
  } cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}