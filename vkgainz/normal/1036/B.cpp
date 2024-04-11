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
  int q; cin >> q;
  while(q--) {
    ll n,m,k;
    cin >>n>>m>>k;
    if(k<max(n,m))
      cout << -1 << "\n";
    else {
      if((n+m)%2==1) {
        if((k+max(n,m)%2)==1) {
          cout << k-1 << "\n";
        }
        else {
          cout << k-1 << "\n";
        }
      }
      else {
        if((k+max(n,m))%2==0) {
          cout << k << "\n";
        }
        else {
          cout << k-2 << "\n";
        }
      }
    }
  }
}