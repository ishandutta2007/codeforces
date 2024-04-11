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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  vector<int> primes;
  for(int i=2;i<=1000;i++) {
    int numDiv = 0;
    for(int j=1;j<=i;j++) {
      if(i%j==0) ++numDiv;
    }
    if(numDiv==2) primes.push_back(i*i);
  }
  while(t--) {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int numSq = 0;
    unordered_map<int, int> num;
    for(int i=0;i<n;i++) {
      for(auto &it : primes) {
        while(a[i]%(it) == 0) {
          a[i] /= it;
        }
      }
      ++num[a[i]];
      //divide a[i] out by its largest square divisor
    }
    int sum = 0;
    numSq = num[1];
    int mxOdd = 0;
    int mxTot = 0;
    for(auto &it : num) {
      mxTot = max(mxTot, it.s);
      if(it.f!=1 && it.s%2==1) mxOdd = max(mxOdd, it.s);
      if(it.f!=1 && it.s%2==0) sum+=it.s;
    }
    int q; cin >> q;
    while(q--) {
      ll w; cin >> w;
      if(w==0) {
        cout << mxTot << "\n";
      }
      else {
        cout << max(numSq+sum, mxOdd) << "\n";
      }
    }
  }
}