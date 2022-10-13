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
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
int main() {
  int n; cin >> n;
  string s; cin >> s;
  int a = (n-11)/2;
  int nume = 0;
  for(int i=0;i<s.length();i++) {
    if(s[i]-'0' == 8) ++nume;
  }
  if(nume<=a) cout << "NO" << "\n";
  else {
    int pos = 0;
    int x = 0;
    for(int i=0;i<s.length();i++) {
      if(s[i]-'0'==8) ++x;
      if(x>a) {
        pos = i;
        break;
      }
    }
    int numbet = pos-a;
    if(numbet <= a) {
      cout << "YES" << "\n";
    }
    else cout << "NO" << "\n";
  }
}