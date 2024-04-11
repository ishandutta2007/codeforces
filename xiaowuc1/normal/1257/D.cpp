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

bool piisort(pii a, pii b) {
  if(a.first == b.first) return a.second > b.second;
  return a.first > b.first;
}
int l[200005];
void rsolve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  int m;
  cin >> m;
  vector<pii> v;
  for(int i = 0; i < m; i++) {
    int p, s;
    cin >> p >> s;
    v.push_back({p, s});
  }
  sort(v.begin(), v.end(), piisort);
  {
    vector<pii> nv;
    for(pii out: v) {
      if(nv.empty() || nv.back().second < out.second) {
        nv.push_back(out);
      }
    }
    v = nv;
  }
  int ret = 0;
  int curr = 0;
  while(curr < n) {
    int curri = sz(v)-1;
    int dead = 0;
    while(curr < n && dead < v[curri].second) {
      if(l[curr] <= v[curri].first) {
        curr++;
        dead++;
        continue;
      }
      int lhs = 0;
      int rhs = curri-1;
      while(lhs < rhs) {
        int mid = (lhs+rhs+1)/2;
        if(l[curr] <= v[mid].first) {
          lhs = mid;
        }
        else {
          rhs = mid-1;
        }
      }
      curri = lhs;
      if(l[curr] <= v[curri].first && dead < v[curri].second) {
        curr++;
        dead++;
      }
      else {
        break;
      }
    }
    if(dead == 0) {
      cout << "-1\n";
      return;
    }
    ret++;
  }
  cout << ret << "\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) rsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}