#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
typedef tree<
pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;
const int MX = 3e5+5;

int main() {
  int t; cin >> t;
  while(t--) {
    string s; cin >> s;
    int n = s.length();
    int lst[26];
    for(int i=0;i<26;i++)
      lst[i] = -5;
    bool change[n];
    memset(change,0,sizeof(change));
    for(int i=0;i<s.length();i++) {
      int r = i;
      while(r<s.length() && s[r]==s[i])
        ++r;
      --r;
      int x = s[i]-'a';
      if(lst[x]==i-2 && !change[i-2]) {
        for(int j=i;j<=r;j++) {
          if((j-i)%3==1) continue;
          change[j] = true;
        }
      }
      else {
        for(int j=i;j<=r;j++) {
          if((j-i)%3==0) continue;
          change[j] = true;
        }
      }
      lst[x] = r;
      i = r;
    }
    int ans = 0;
    for(int i=0;i<n;i++) ans+=change[i];
    cout << ans << "\n";
  }
}