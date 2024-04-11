#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

int freq[101];
char ret[101];
void solve() {
  int n;
  vector<int> v;
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  for(int i = 0; i < n; i++) freq[v[i]]++;
  int one = 0;
  int more = 0;
  for(int i = 1; i <= 100; i++) {
    if(freq[i] == 1) one++;
    if(freq[i] >= 3) more++;
  }
  if(one%2 && more==0) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  int as = 0;
  int bs = 0;
  for(int i = 1; i <= 100; i++) {
    if(freq[i] != 1) continue;
    for(int j = 0; j < n; j++) {
      if(v[j] == i) {
        if(as == bs) {
          ret[j] = 'A';
          as++;
        }
        else {
          ret[j] = 'B';
          bs++;
        }
      }
    }
  }
  for(int i = 1; i <= 100; i++) {
    if(freq[i] <= 1) continue;
    if(as == bs || freq[i] == 2) {
      for(int j = 0; j < n; j++) {
        if(v[j] == i) {
          ret[j] = 'A';
        }
      }
    }
    else {
      assert(as == ++bs);
      bool first = true;
      for(int j = 0; j < n; j++) {
        if(v[j] == i) {
          if(first) {
            ret[j] = 'B';
            first = false;
          }
          else {
            ret[j] = 'A';
          }
        }
      }
    }
  }

  for(int i = 0; i < n; i++) cout << ret[i];
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}