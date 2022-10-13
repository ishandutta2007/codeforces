#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5 + 5;

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    string s; cin >> s;
    int a = 0, b = 0;
    for(int i = 0; i < n/2; i++) {
      if(s[i] == '0' && s[n-i-1] == '1') ++a;
      if(s[i] == '1' && s[n-i-1] == '0') ++a;
      if(s[i] == '0' && s[n-i-1] == '0') ++b;
    }
    if(a >= 2) {
      cout << "ALICE" << "\n";
    }
    else if(a == 1) {
    }
    else {
      if(n%2 && s[n/2] == '0' && b) 
        cout << "ALICE" << "\n";
      else
        cout << "BOB" << "\n";
    }
  }
}