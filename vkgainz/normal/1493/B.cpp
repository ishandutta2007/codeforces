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
string get(int x) {
  if(x<10) return "0"+to_string(x);
  return to_string(x);
}
int get(string x) {
  return (x[0]-'0')*10 + (x[1]-'0');
}
bool valid(char c) {
  return c=='0' || c=='1' || c=='2' || c=='5' || c=='8';
}
int reverse(char c) {
  if(c=='0' || c=='1' || c=='8') return c-'0';
  if(c=='2') return 5;
  if(c=='5') return 2;
  return -1;
}
bool valid(string a, string b, int h, int m) {
  //a::b ==> b'::a'
  if(!valid(a[0]) || !valid(a[1]) || !valid(b[0]) || !valid(b[1]))
    return false;
  int nxtH = reverse(b[1])*10+reverse(b[0]);
  int nxtB = reverse(a[0]) + reverse(a[1])*10;
  return nxtH < h && nxtB < m;
}
int main() {
  int T; cin >> T;
  while(T--) {
    int h, m; cin >> h >> m;
    string s; cin >> s;
    int stH = get(s.substr(0, 2)), stM = get(s.substr(3, 2));
    bool found = false;
    string ans = "";
    for(int i=stH;i<h;i++) {
      for(int j=0;j<m;j++) {
        string a = get(i), b = get(j);
        if(i==stH && j<stM) continue;
        else if(valid(a, b, h, m)) {
          if(!found) ans = a+":"+b;
          found = true;
        }
      }
    }
    for(int i=0;i<=stH;i++) {
      for(int j=0;j<m;j++) {
        string a = get(i), b = get(j);
        if(i==stH && j>=stM) continue;
        else if(valid(a, b, h, m)) {
          if(!found) ans = a+":"+b;
          found = true;
        }
      }
    }
    cout << ans << "\n";
  }
}