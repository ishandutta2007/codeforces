#include<bits/stdc++.h>
using namespace std;
#define h first
#define w second
const int MX = 5e5+5;
using ll = long long;
ll mod = 1e9+7;
int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<pair<pair<int, int>, int>> in(n);
    vector<int> ans(n);
    for(int i=0;i<n;i++) {
      cin >> in[i].h.h >> in[i].h.w;
      in[i].w = i;
      ans[i] = -1;
    }
    sort(in.begin(), in.end());
    //hj<hi && wj<wi case
    int j= 0;
    int cmp = 0;
    bool add = false;
    for(int i=0;i<n;i++) {
      while(j < n && in[j].h.h < in[i].h.h) {
        add = true;
        if(in[j].h.w < in[cmp].h.w)
          cmp = j;
        ++j;
      }
      if(add && in[cmp].h.w < in[i].h.w)
        ans[in[i].w] = in[cmp].w;
    }
    //wj<hi && hj<wi case
    vector<pair<pair<int, int>, int>> rev(n);
    for(int i=0;i<n;i++) {
      rev[i].h.h = in[i].h.w;
      rev[i].h.w = in[i].h.h;
      rev[i].w = in[i].w;
    }
    sort(rev.begin(), rev.end());
    j = 0;
    cmp = 0;
    add = false;
    for(int i=0;i<n;i++) {
      while(j < n && rev[j].h.h < in[i].h.h) {
        add = true;
        if(rev[j].h.w < rev[cmp].h.w)
          cmp = j;
        ++j;
      }
      if(add && rev[cmp].h.w < in[i].h.w)
        ans[in[i].w] = rev[cmp].w;
    }
    for(int i=0;i<n;i++) {
      if(ans[i]!=-1)
        cout << ans[i]+1 << " ";
      else cout << -1 << " ";
    }
    cout << "\n";
  }
}