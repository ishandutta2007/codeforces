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
vector<int> pos[MX], neg[MX];
vector<int> zer;
int main() {
  int n; cin >> n;
  for(int i=0;i<n;i++) {
    string s; cin >> s;
    int mn = 1000000;
    int curr = 0;
    for(int i=0;i<s.length();i++) {
      if(s[i]==')') --curr;
      else ++curr;
      mn = min(mn, curr);
    }
    if(curr>0) pos[curr].push_back(mn);
    else if(curr<0) neg[-curr].push_back(mn);
    else zer.push_back(mn);
  }
  ll ans = 0;
  for(int i=1;i<MX;i++) {
    ordered_set o;
    for(int j=0;j<neg[i].size();j++) {
      o.insert({neg[i][j], j});
    }
    for(int k : pos[i]) {
      if(k>=0) {
        int x = o.order_of_key({-i, -10000000});
        ans+=o.size()-x;
      }
    }
  }
  int x =0;
  for(int i=0;i<zer.size();i++)
    if(zer[i]>=0) ++x;
  ans+=x*1LL*x;
  cout << ans << "\n";
}