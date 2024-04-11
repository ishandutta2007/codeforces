#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
const int MX = 1e5+5;

int main() {
  int n, k; cin >> n >> k;
  int a[n];
  map<int, int> f;
  set<int> s;
  for(int i=0;i<n;i++) {
    cin >> a[i];
    ++f[a[i]];
    s.insert(a[i]);
  }
  auto it = s.begin();
  int prev = (*it);
  int ans = 0;
  while(it!=s.end()) {
    if((*it)<=prev+k) {
    }
    else {
      ans+=f[prev];
    }
    prev=  (*it);
    ++it;
  }
  ans+=f[prev];
  cout << ans << "\n";
}