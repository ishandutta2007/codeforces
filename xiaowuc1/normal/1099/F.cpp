#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct node {
  node* lhs;
  node* rhs;
  int lv;
  int rv;
  ll amt;
  ll cost;
  node() {}
  node(int a, int b, ll c, ll d) {
    lhs = NULL;
    rhs = NULL;
    lv=a;
    rv=b;
    amt=c;
    cost=d;
  }
  void pullup() {
    lv = lhs->lv;
    rv = rhs->rv;
    amt = lhs->amt + rhs->amt;
    cost = lhs->cost + rhs->cost;
  }
};

ll query(node* n, ll amt) {
  if(n->cost <= amt) return n->amt;
  if(n->lv == n->rv) {
    return amt / n->lv;
  }
  if(n->lhs->cost >= amt) {
    return query(n->lhs, amt);
  }
  return n->lhs->amt + query(n->rhs, amt - n->lhs->cost);
}

node* increment(node* n, int i, int v) {
  assert(n->lv <= i && i <= n->rv);
  if(n->lv == n->rv) {
    node* ret = new node(n->lv, n->rv, n->amt, n->cost);
    ret->amt += v;
    ret->cost = ret->amt * ret->lv;
    return ret;
  }
  else {
    node* ret = new node;
    int m = (n->lv + n->rv) / 2;
    if(i <= m) {
      ret->lhs = increment(n->lhs, i, v);
      ret->rhs = n->rhs;
    }
    else {
      ret->lhs = n->lhs;
      ret->rhs = increment(n->rhs, i, v);
    }
    ret->pullup();
    return ret;
  }
}

void fill_children(node* n) {
  if(n->lv != n->rv) {
    int m = (n->lv) + (n->rv);
    m /= 2;
    n->lhs = new node(n->lv, m, 0, 0);
    fill_children(n->lhs);
    n->rhs = new node(m+1, n->rv, 0, 0);
    fill_children(n->rhs);
  }
}

node* make_empty() {
  node* root = new node(1, 1000000, 0, 0);
  fill_children(root);
  return root;
}

int cookieCount[100005];
int cost[100005];
node* roots[100005];
vector<pii> children[100005];

ll solve(int curr, ll amtLeft, bool block) {
  if(amtLeft <= 0) return 0;
  roots[curr] = increment(roots[curr], cost[curr], cookieCount[curr]);
  ll ret = query(roots[curr], amtLeft);
  ll best = -1;
  ll best2 = -1;
  for(pii out: children[curr]) {
    roots[out.first] = roots[curr];
    ll cand = solve(out.first, amtLeft - 2 * out.second, true);
    if(cand > best) {
      best2 = best;
      best = cand;
    }
    else if(cand > best2) {
      best2 = cand;
    }
  }
  if(block) ret = max(ret, best2);
  else ret = max(ret, best);
  return ret;
}

void solve() {
  roots[1] = make_empty();
  int n;
  ll maxT;
  cin >> n >> maxT;
  for(int i = 1; i <= n; i++) {
    cin >> cookieCount[i];
  }
  for(int i = 1; i <= n; i++) {
    cin >> cost[i];
  }
  for(int i = 2; i <= n; i++) {
    int par, cc;
    cin >> par >> cc;
    children[par].push_back({i, cc});
  }
  cout << solve(1, maxT, false) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}