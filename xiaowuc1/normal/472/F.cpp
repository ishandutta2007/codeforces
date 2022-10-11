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
typedef vector<string> matrix;

vector<int> rref(vector<int>& v, vector<pii>& moves) {
  int row = 0;
  vector<int> x;
  for(int j = 29; row < sz(v) && j >= 0; j--) {
    for(int i = row; i < sz(v); i++) {
      if(v[i]&(1<<j)) {
        if(i > row) {
          swap(v[i], v[row]);
          moves.push_back({i, row});
          moves.push_back({row, i});
          moves.push_back({i, row});
        }
        break;
      }
    }
    if((v[row] & (1<<j)) == 0) continue;
    x.push_back(1 << j);
    for(int i = 0; i < sz(v); i++) {
      if(i == row) continue;
      if(v[i] & (1<<j)) {
        v[i] ^= v[row];
        moves.push_back({i, row});
      }
    }
    row++;
  }
  return x;
}

bool convertbases(vector<int>& ax, vector<int>& bx, vector<int>& a, vector<int>& b, vector<pii>& cm) {
  if(sz(ax) < sz(bx)) return false;
  int j = 0;
  for(int i = 0; i < sz(ax); i++) {
    if(j == sz(bx)) {
      a[i] = 0;
      cm.push_back({i, i});
      continue;
    }
    if(ax[i] > bx[j]) {
      a[i] = 0;
      cm.push_back({i, i});
      continue;
    }
    if(ax[i] < bx[j]) return false;
    int want = a[i] ^ b[j];
    for(int k = i+1; k < sz(ax); k++) {
      if(want & (ax[k])) {
        want ^= a[k];
        cm.push_back({i, k});
        a[i] ^= a[k];
      }
    }
    if(want) return false;
    j++;
  }
  if(j != sz(bx)) return false;
  for(int i = sz(ax)-1; i >= 0; i--) {
    if(a[i] == 0) {
      for(int k = i; k+1 < sz(ax); k++) {
        a[k] = a[k+1];
        cm.push_back({k, k+1});
        cm.push_back({k+1, k+1});
      }
      ax.pop_back();
    }
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  vector<pii> am, bm;
  vector<int> ax = rref(a, am);
  vector<int> bx = rref(b, bm);
  vector<pii> cm;
  if(!convertbases(ax, bx, a, b, cm)) cout << "-1\n";
  else {
    reverse(all(bm));
    cout << sz(am) + sz(cm) + sz(bm) << "\n";
    for(pii out: am) cout << out.first+1 << " " << out.second+1 << "\n";
    for(pii out: cm) cout << out.first+1 << " " << out.second+1 << "\n";
    for(pii out: bm) cout << out.first+1 << " " << out.second+1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}