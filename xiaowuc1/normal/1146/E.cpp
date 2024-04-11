#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int RAGETREE_SZ = 200001;
int ragetreemin[1000000];
int ragetreemax[1000000];
bool ragetreelazy[1000000];

pii eval(int idx) {
  if(ragetreelazy[idx]) {
    return {-ragetreemax[idx], -ragetreemin[idx]};
  }
  return {ragetreemin[idx], ragetreemax[idx]};
}
void pullup(int idx, bool debug = false) {
  pii lhs = eval(2*idx);
  pii rhs = eval(2*idx+1);
  assert(lhs.first <= lhs.second);
  assert(rhs.first <= rhs.second);
    ragetreemin[idx] = min(lhs.first, rhs.first);
  ragetreemax[idx] = max(lhs.second, rhs.second);
}
void pushdown(int idx) {
  ragetreelazy[2*idx] ^= ragetreelazy[idx];
  ragetreelazy[2*idx+1] ^= ragetreelazy[idx];
  ragetreelazy[idx] = false;
}

void greaterthan(int idx, int lhs, int rhs, int x) {
  pii key = eval(idx);
  if(key.first > x) {
    ragetreelazy[idx] ^= true;
    return;
  }
  if(key.second <= x) return;
  pushdown(idx);
  int mid = (lhs+rhs)/2;
  greaterthan(2*idx, lhs, mid, x);
  greaterthan(2*idx+1, mid+1, rhs, x);
  pullup(idx);
}
void greaterthan(int x) {
  greaterthan(1, 0, RAGETREE_SZ-1, x);
}

void lessthan(int idx, int lhs, int rhs, int x) {
  pii key = eval(idx);
  if(key.second < x) {
    ragetreelazy[idx] ^= true;
    return;
  }
  if(key.first >= x) return;
  pushdown(idx);
  int mid = (lhs+rhs)/2;
  lessthan(2*idx, lhs, mid, x);
  lessthan(2*idx+1, mid+1, rhs, x);
  pullup(idx);
}
void lessthan(int x) {
  lessthan(1, 0, RAGETREE_SZ-1, x);
}

int get(int idx, int lhs, int rhs, int i) {
  if(lhs == rhs) {
    if(ragetreelazy[idx]) return -ragetreemin[idx];
    return ragetreemin[idx];
  }
  pushdown(idx);
  int mid = (lhs+rhs)/2;
  int ret;
  if(i <= mid) ret = get(2*idx, lhs, mid, i);
  else ret = get(2*idx+1, mid+1, rhs, i);
  pullup(idx);
  return ret;
}
int get(int idx) {
  return get(1, 0, RAGETREE_SZ-1, idx);
}

void init(int idx, int lhs, int rhs, vector<int>& v) {
  if(lhs == rhs) {
    ragetreemin[idx] = v[lhs];
    ragetreemax[idx] = v[lhs];
    return;
  }
  int mid = (lhs+rhs)/2;
  init(2*idx, lhs, mid, v);
  init(2*idx+1, mid+1, rhs, v);
  pullup(idx);
}
void init(vector<int>& v) {
  init(1, 0, v.size()-1, v);
}

void init(vector<char>& op, vector<int>& thresh) {
  vector<int> v;
  v.resize(RAGETREE_SZ);
  for(int i = 0; i < RAGETREE_SZ; i++) v[i] = i - 100000;
  init(v);
  for(int i = 0; i < op.size(); i++) {
    if(op[i] == '<') lessthan(thresh[i]);
    else greaterthan(thresh[i]);
  }
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> v;
  v.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  vector<char> op;
  vector<int> thresh;
  op.resize(q);
  thresh.resize(q);
  for(int i = 0; i < q; i++) {
    string s;
    cin >> s >> thresh[i];
    op[i] = s[0];
  }
  init(op, thresh);
  for(int i = 0; i < n; i++) {
    cout << get(v[i] + 100000);
    if(i == n-1) cout << "\n";
    else cout << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}