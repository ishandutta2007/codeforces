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
const int MX = 2e5 + 5;
struct robot {
  int type;
  int start;
  int index;
};
bool cmp(robot &x, robot &y) {
  return x.start < y.start;
}
vector<int> ans;
void solve(vector<robot> &v, int &m) {
  vector<robot> stackR;
  for(int i = 0; i < v.size(); i++) {
    if(v[i].type == 0) { //L
      if(stackR.empty()) {
        //change into right
        stackR.push_back({1, -v[i].start, v[i].index});
      }
      else {
        auto hit = stackR.back();
        int time = (v[i].start - hit.start) / 2;
        ans[v[i].index] = time, ans[hit.index] = time;
        stackR.pop_back();
      }
    }
    else { //R ==> handle end case by reversing...?
      stackR.push_back(v[i]);
    }
  }
  if(stackR.size() <= 1) return;
  //reverse stuff left
  vector<robot> nxt;
  for(auto &it : stackR) {
    nxt.push_back({0, m - it.start, it.index});
  }
  sort(nxt.begin(), nxt.end(), cmp);
  for(int i = 0; i < nxt.size(); i++) {
    if(i % 2) {
      int time = (nxt[i].start + nxt[i-1].start) / 2;
      ans[nxt[i].index] = time, ans[nxt[i-1].index] = time;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    vector<robot> in_odd, in_even;
    vector<int> x(n), st(n);
    for(int i = 0; i < n; i++) {
      cin >> x[i];
    }
    for(int i = 0; i < n; i++) {
      char ch; cin >> ch;
      if(ch == 'R') st[i] = 1;
      else st[i] = 0;
    }
    for(int i = 0; i < n; i++) {
      if(x[i] % 2) in_odd.push_back({st[i], x[i], i});
      else in_even.push_back({st[i], x[i], i});
    }
    ans.clear();
    ans.resize(n, -1);
    sort(in_odd.begin(), in_odd.end(), cmp);
    sort(in_even.begin(), in_even.end(), cmp);
    solve(in_odd, m), solve(in_even, m);
    for(auto &it : ans) {
      cout << it << " ";
    }
    cout << "\n";
  }
}