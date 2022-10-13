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
  int n; cin >> n;
  vector<int> div;
  for(int i=1;i*i<=n;i++) {
    if(n%i==0) {
      div.push_back(i);
      div.push_back(n/i);
    }
  }
  set<ll> ans;
  for(auto &it : div) {
    int k = n/it;
    ll curr = n*1LL*(k-1)/2+k;
    ans.insert(curr);
  }
  for(auto &it : ans)
    cout << it << " ";
}