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
typedef pair<int, pii> query;

const int RAGETREE_SZ = 1 << 18;
int ragetree[2 * RAGETREE_SZ];
void insert(int idx) {
  assert(idx >= 0 && idx < RAGETREE_SZ);
  idx += RAGETREE_SZ;
  while(idx > 0) {
    ragetree[idx]++;
    idx /= 2;
  }
}
int qry(int k) {
  int curr = 1;
  while(curr < RAGETREE_SZ) {
    if(ragetree[2*curr] >= k) {
      curr *= 2;
    }
    else {
      k -= ragetree[2*curr];
      curr = 2*curr+1;
    }
  }
  assert(k == 1);
  assert(ragetree[curr] == 1);
  return curr-RAGETREE_SZ;
}

int l[200005];
int ret[200005];
query queries[200005]; // <length, <idx in, idx to ret>>

bool piisort(pii a, pii b) {
  if(a.first != b.first) return a.first > b.first;
  return a.second < b.second;
}

void solve() {
  int n;
  cin >> n;
  vector<pii> v;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    v.push_back({l[i], i});
  }
  sort(v.begin(), v.end(), piisort);
  int q;
  cin >> q;
  for(int i = 0; i < q; i++) {
    cin >> queries[i].first >> queries[i].second.first;
    queries[i].second.second = i;
  }
  sort(queries, queries+q);
  int qIdx = 0;
  for(int amt = 1; amt <= n; amt++) {
    insert(v[amt-1].second);
    while(qIdx < q && queries[qIdx].first == amt) {
      ret[queries[qIdx].second.second] = l[qry(queries[qIdx].second.first)];
      qIdx++;
    }
  }
  for(int i = 0; i < q; i++) cout << ret[i] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}