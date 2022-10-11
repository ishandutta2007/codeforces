#include <algorithm>
#include <bitset>
#include <cassert>
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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int l[1000000];
void solve() {
  int n, k;
  cin >> n >> k;
  k *= 8;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  sort(l, l+n);
  vector<int> v;
  for(int i = 0; i < n;) {
    int j = i+1;
    while(j < n && l[i] == l[j]) {
      j++;
    }
    v.push_back({j-i});
    i = j;
  }
  ll ret = n;
  int lhs = 0;
  int numBits = 0;
  ll inside = 0;
  for(int i = 0; i < v.size(); i++) {
    while((1 << numBits) < i-lhs+1) {
      numBits++;
    }
    inside += v[i];
    ll need = numBits * n;
    while(need > k) {
      numBits = max(0, numBits-1);
      inside -= v[lhs++];
      while((1 << numBits) < i-lhs+1) {
        numBits++;
      }
      need = numBits * n;
    }
    ret = min(ret, n - inside);
  }
  cout << ret << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}