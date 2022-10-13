#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 2e6+5;
const int LOG = 21;
pair<int, int> lastOcc[1<<LOG];
void insert(pair<int, int> &x, int y) {
  if(y == x.f || y == x.s) return;
  if(y >= x.f) {
    x = {y, x.f};
  }
  else if(y >= x.s) {
    x = {x.f, y};
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<1<<LOG;i++) lastOcc[i] = {-1, -1};
  for(int i=0;i<n;i++) {
    cin >> a[i];
    insert(lastOcc[a[i]], i);
  }
  for(int i=0;i<LOG;i++) {
    for(int msk=(1<<LOG)-1;msk>=0;msk--) {
      if(msk&(1<<i)) continue;
      insert(lastOcc[msk], lastOcc[msk^(1<<i)].f);
      insert(lastOcc[msk], lastOcc[msk^(1<<i)].s);
    }
  }
  int curr = 0;
  for(int i=LOG;i>=0;i--) {
    curr+=(1<<i);
    bool work = false;
    for(int x=0;x<n;x++) {
      int left = curr - (curr&(a[x]));
      if(lastOcc[left].s > x) work = true;
    }
    if(!work) curr-=(1<<i);
  }
  cout << curr << "\n";
}