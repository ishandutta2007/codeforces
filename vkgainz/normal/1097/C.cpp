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
const int MX = 5e5 + 5;
vector<int> in[MX], out[MX];
int main() {
  int n; cin >> n;
  //handle 0 case separately
  int x = 0;
  for(int i=0;i<n;i++) {
    string s; cin >> s;
    int curr = 0;
    int mn = 500000;
    for(int i=0;i<s.length();i++) {
      if(s[i] == '(') ++curr;
      else --curr;
      mn = min(mn, curr);
    }
    if(curr == 0) {
      if(mn >= 0) ++x;
    }
    if(curr > 0) in[curr].push_back(mn);
    if(curr < 0) out[-curr].push_back(mn);
  }
  int ans = x/2;
  for(int i=1;i<MX;i++) {
    int a = 0;
    for(auto &it : in[i]) if(it >= 0) ++a;
    int b = 0;
    for(auto &it : out[i]) if(it >= -i) ++b;
    ans += min(a, b);
  }
  cout << ans << "\n";
}