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
  ll l, r; cin >> l >> r;
  cout << "YES" << "\n";
  for(ll x=l; x+1 <= r; x+=2) {
    cout << x << " " << x+1 << "\n";
  }
}