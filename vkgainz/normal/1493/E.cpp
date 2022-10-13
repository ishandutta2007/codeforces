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
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 1e6 + 5;

int main() {
  int n; cin >> n;
  string l, r; cin >> l >> r;
  if(l[0] != r[0]) {
    string ret;
    for(int i=0;i<n;i++)
      ret+="1";
    cout << ret << "\n";
  }
  else {
    if(r[n-1] == '0') {
      int diff = -1;
      for(int i=0;i<n;i++) {
        if(l[i] != r[i]) {
          diff = i;
          break;
        }
      }
      if(diff == -1)
        cout << r << "\n";
      else {
        bool f = true;
        for(int i=diff+1;i<n;i++) {
          if(l[i] == '1' && r[i] == '0') continue;
          f = false;
        }
        if(f) cout << r << "\n";
        else {
          r[n-1] = '1';
          cout << r << "\n";
        }
      }
    }
    else {
      cout << r << "\n";
    }
  }

}