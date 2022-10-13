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
#define ordered_set tree<double, null_type,less<double>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5+ 5;

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    int i = 0, j = 0, k = 0;
    string ans = "";
    for(int x=0;x<3*n;x++) {
      if(i == 2 * n) {
        if(j < 2 * n && j > k) {
          ans += b[j++];
        }
        else if(k < 2 * n) {
           ans += c[k++];
        }
        else {
          ans += '0';
        }
      }
      else if(j == 2 * n) {
        if(i < 2 * n && i > k) {
          ans += a[i++];
        }
        else if(k < 2 * n) {
          ans += c[k++];
        }
        else {
          ans += '0';
        }
      }
      else if(k == 2 * n) {
        if(i < 2 * n && i > j) {
          ans += a[i++];
        }
        else if(j < 2 * n) {
          ans += b[j++];
        }
        else {
          ans += '0';
        }
      }
      else {
      int tot = 0, num = 0;
      if(i < 2 * n) {
        ++tot, num += a[i] - '0';
      }
      if(j < 2*n) {
        ++tot, num += b[j] - '0';
      }
      if(k < 2*n) {
        ++tot, num += c[k] - '0';
      }
      if(num > tot/2) {
        ans += '1';
        if(i < 2*n && a[i] == '1') ++i;
        if(j < 2*n && b[j] == '1') ++j;
        if(k < 2*n && c[k] == '1') ++k;
      }
      else {
        ans += '0';
        if(i < 2*n && a[i] == '0') ++i;
        if(j < 2*n && b[j] == '0') ++j;
        if(k < 2*n && c[k] == '0') ++k;
      }
      }
    }
    cout << ans << "\n";
  }
}