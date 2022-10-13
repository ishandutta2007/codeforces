#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 3e5 + 5;
vector<vector<int>> adj1, adj2;
vector<int> st, en;
int x;
int ans = 0;
int n;
set<pair<int, int>> inAns;
void dfs(int curr, int par) {
  //put in
  bool rem = false;
  pair<int, int> gone;
  auto it = inAns.lower_bound({st[curr], 0});
  if(it != inAns.begin()) {
    --it;
    if((*it).f < st[curr] && (*it).s > en[curr]) {
      rem = true;
      gone = (*it);
      inAns.erase(it);
    }
  }
  inAns.insert({st[curr], en[curr]});
  ans = max(ans, (int) inAns.size());
  for(int next : adj1[curr]) { //souroush tree
    if(next == par) continue;
    dfs(next, curr);
  }
  //put out
  inAns.erase({st[curr], en[curr]});
  if(rem) {
    inAns.insert(gone);
  }
}

void init(int curr, int par) {
  st[curr] = x++;
  for(int next : adj2[curr]) { //keishi tree
    if(next == par) continue;
    init(next, curr);
  }
  en[curr] = x++;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--) {
    cin >> n;
    adj1.clear(), adj1.resize(n);
    adj2.clear(), adj2.resize(n);
    for(int i = 1; i < n; i++) {
      int a; cin >> a;
      --a;
      adj1[a].push_back(i);
      adj1[i].push_back(a);
    }
    for(int i = 1; i < n; i++) {
      int b; cin >> b;
      --b;
      adj2[b].push_back(i);
      adj2[i].push_back(b);
    }
    st.clear(), st.resize(n);
    en.clear(), en.resize(n);
    x = 0;
    ans = 0;
    inAns.clear();
    init(0, -1);
    dfs(0, -1);
    cout << ans << "\n";
  }
}