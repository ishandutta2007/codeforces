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
#include <unordered_map>
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
typedef pair<pii, int> config;

const int MOD = 1000000009;

int f[300006];
int pref[300006];

inline int fib(int n) {
  return f[n];
}

const int MAX_N = 300005;
const int BUCKET_SZ = 3000;
const int NUM_BUCKETS = MAX_N / BUCKET_SZ + 1;
int bucketsum[NUM_BUCKETS];
int actual[MAX_N];
vector<int> lazy[NUM_BUCKETS];

void force(int bucketidx) {
  int lhs = bucketidx * BUCKET_SZ;
  int rhs = lhs + BUCKET_SZ - 1;
  for(int i = lhs; i <= rhs; i++) {
    for(int out: lazy[bucketidx]) {
      actual[i] += f[out + i - lhs];
      if(actual[i] >= MOD) actual[i] -= MOD;
    }
  }
  lazy[bucketidx].clear();
}

int qry(int lhs, int rhs) {
  int ret = 0;
  if(lhs % BUCKET_SZ) {
    force(lhs/BUCKET_SZ);
  }
  while(lhs <= rhs && lhs % BUCKET_SZ) {
    ret += actual[lhs++];
    if(ret >= MOD) ret -= MOD;
  }
  while(lhs + BUCKET_SZ - 1 <= rhs) {
    ret += bucketsum[lhs / BUCKET_SZ];
    if(ret >= MOD) ret -= MOD;
    lhs += BUCKET_SZ;
  }
  if(lhs <= rhs) force(lhs/BUCKET_SZ);
  while(lhs <= rhs) {
    ret += actual[lhs++];
    if(ret >= MOD) ret -= MOD;
  }
  return ret;
}

void upd(int lhs, int rhs) {
  int idx = 1;
  while(lhs <= rhs && lhs % BUCKET_SZ) {
    actual[lhs] += f[idx];
    if(actual[lhs] >= MOD) actual[lhs] -= MOD;
    bucketsum[lhs/BUCKET_SZ] += f[idx];
    if(bucketsum[lhs/BUCKET_SZ] >= MOD) bucketsum[lhs/BUCKET_SZ] -= MOD;
    lhs++;
    idx++;
  }
  while(lhs <= rhs && lhs + BUCKET_SZ - 1 <= rhs) {
    lazy[lhs/BUCKET_SZ].push_back(idx);
    bucketsum[lhs/BUCKET_SZ] += pref[idx + BUCKET_SZ] - pref[idx];
    if(bucketsum[lhs/BUCKET_SZ] >= MOD) bucketsum[lhs/BUCKET_SZ] -= MOD;
    if(bucketsum[lhs/BUCKET_SZ] < 0) bucketsum[lhs/BUCKET_SZ] += MOD;
    lhs += BUCKET_SZ;
    idx += BUCKET_SZ;
  }
  while(lhs <= rhs) {
    actual[lhs] += f[idx];
    if(actual[lhs] >= MOD) actual[lhs] -= MOD;
    bucketsum[lhs/BUCKET_SZ] += f[idx];
    if(bucketsum[lhs/BUCKET_SZ] >= MOD) bucketsum[lhs/BUCKET_SZ] -= MOD;
    lhs++;
    idx++;
  }
}

void solve() {
  f[0] = 0;
  f[1] = 1;
  for(int i = 2; i <= 300001; i++) {
    f[i] = f[i-1] + f[i-2];
    if(f[i] >= MOD) f[i] -= MOD;
  }
  for(int i = 0; i <= 300001; i++) {
    pref[i+1] = pref[i] + f[i];
    if(pref[i+1] >= MOD) pref[i+1] -= MOD;
  }
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> actual[i];
    bucketsum[i/BUCKET_SZ] += actual[i];
    if(bucketsum[i/BUCKET_SZ] >= MOD) bucketsum[i/BUCKET_SZ] -= MOD;
  }
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
      int lhs, rhs;
      cin >> lhs >> rhs;
      upd(lhs, rhs);
    }
    else {
      int lhs, rhs;
      cin >> lhs >> rhs;
      cout << qry(lhs, rhs) << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}