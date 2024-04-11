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

#include <unordered_map>

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

const int MAX_N = 500000;
const int BUCKET_SZ = 700;
const int NUM_BUCKETS = MAX_N / BUCKET_SZ + 1;
ll l[MAX_N + BUCKET_SZ];
ll bucketinc[NUM_BUCKETS];
unordered_map<ll, int> indices[NUM_BUCKETS];

void solve() {
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
    indices[i/BUCKET_SZ][l[i]]++;
  }
  while(q--) {
    int t;
    cin >> t;
    if(t == 2) {
      ll want;
      cin >> want;
      int lhs = 1e9;
      int rhs = -1;
      for(int i = 0; i < NUM_BUCKETS; i++) {
        ll goal = want - bucketinc[i];
        if(indices[i].count(goal)) {
          for(int a = i * BUCKET_SZ; lhs > 1e8; a++) {
            if(l[a] == goal) lhs = a;
          }
          break;
        }
      }
      for(int i = NUM_BUCKETS-1; i >= 0; i--) {
        ll goal = want - bucketinc[i];
        if(indices[i].count(goal)) {
          for(int a = i * BUCKET_SZ; a < (i+1) * BUCKET_SZ; a++) {
            if(l[a] == goal) rhs = max(rhs, a);
          }
          break;
        }
      }
      if(lhs > rhs) cout << "-1\n";
      else cout << rhs-lhs << "\n";
    }
    else {
      assert(t == 1);
      int lhs, rhs, x;
      cin >> lhs >> rhs >> x;
      lhs--; rhs--;
      while(lhs <= rhs && lhs % BUCKET_SZ) {
        if(--indices[lhs/BUCKET_SZ][l[lhs]] == 0) indices[lhs/BUCKET_SZ].erase(l[lhs]);
        l[lhs] += x;
        indices[lhs/BUCKET_SZ][l[lhs]]++;
        lhs++;
      }
      while(lhs + BUCKET_SZ - 1 <= rhs) {
        bucketinc[lhs/BUCKET_SZ] += x;
        lhs += BUCKET_SZ;
      }
      while(lhs <= rhs) {
        if(--indices[lhs/BUCKET_SZ][l[lhs]] == 0) indices[lhs/BUCKET_SZ].erase(l[lhs]);
        l[lhs] += x;
        indices[lhs/BUCKET_SZ][l[lhs]]++;
        lhs++;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}