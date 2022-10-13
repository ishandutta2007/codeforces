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
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a[n];
    ll s = 0LL;
    for(int i=0;i<n;i++)
      cin >> a[i], s+=a[i];
    int b[n];
    ll t = 0LL;
    for(int i=0;i<n;i++) {
      if(i%2==0) t+=a[i]-1;
    }
    if(2*t<=s) {
      for(int i=0;i<n;i++) {
        if(i%2==0) b[i] = 1LL;
        else b[i] = a[i];
      }
    }
    else {
      for(int i=0;i<n;i++) {
        if(i%2==1) b[i] = 1LL;
        else b[i] = a[i];
      }

    }
    for(int i=0;i<n;i++)
      cout << b[i] << " ";
    cout << "\n";
  }
}