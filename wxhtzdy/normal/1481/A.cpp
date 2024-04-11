/**
 *    author:  milos
 *    created: 05.02.2021 15:36:14       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;          
    map<char, int> cnt;
    for (int i = 0; i < (int) s.size(); i++) {
      cnt[s[i]]++;  
    }
    int xx = cnt['R'] - cnt['L'];
    int yy = cnt['U'] - cnt['D'];
    bool ok = true;
    if (xx > x && cnt['R'] < xx - x) {
      ok = false;
    } 
    if (xx < x && cnt['L'] < x - xx) {
      ok = false;
    }
    if (yy > y && cnt['U'] < yy - y) {
      ok = false;
    } 
    if (yy < y && cnt['D'] < y - yy) {
      ok = false;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}