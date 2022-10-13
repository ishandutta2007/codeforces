#include <bits/stdc++.h>
using namespace std;


const int MX = 5e5 + 5;
int seg[2 * MX];
int lstLess[MX];
int n;
void upd(int i, int v) {
  seg[i+=n+1] = v;
  while(i>1) {
    i/=2;
    seg[i] = max(seg[2*i], seg[2*i+1]);
  }
}
int query(int l, int r) {
  l+=n+1, r+=n+1;
  int ret = -1; //check this
  while(l<r) {
    if(l%2) ret = max(ret, seg[l++]);
    if(r%2) ret = max(ret, seg[--r]);
    l/=2, r/=2;
  }
  return ret;
}
int main() {
  int t; cin >> t;
  while(t--) {
    cin >> n;
    int a[n];
    vector<pair<int, int>> priority;
    priority.push_back({0, 0});
    for(int i=0;i<n;i++)
      cin >> a[i], --a[i], priority.push_back({a[i], i + 1});
    sort(priority.begin(), priority.end());
    for(int i=0;i<=2*n+2;i++)
      seg[i] = -1; //check this
    for(int i=0;i<n;i++) lstLess[i] = -1;
    vector<int> stack;
    for(int i=0;i<n;i++) {
      while(stack.size()>0 && a[stack.back()]<a[i])
        stack.pop_back();
      if(stack.size()>0)
        lstLess[i] = stack.back() + 1;
      stack.push_back(i);
    }
    int ans = 1;
    upd(0, 1);
    for(int i=1;i<n+1;i++) {
      int idx = priority[i].second;
      int put = 1;
      put = max(put, query(0, idx) + 1);
      if(lstLess[idx-1] != -1) {
        put = max(put, query(0, lstLess[idx-1]) + 2);
      }
      ans = max(ans, put);
      upd(idx, put);
    }
    cout << ans-1 << "\n";
  }
}