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
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 3e5 + 5;
#define MAXN 200005
#define MAXE 400010
#define  INF (1<<29)
void print(vector<vector<int>> &v) {
  for(int i=0;i<v.size();i++) {
    for(int j=0;j<v.size();j++)
      cout << v[i][j] << " ";
    cout << "\n";
  }
}
int main() {
  int t; cin >> t;
  while(t--) {
    int m, k; cin >> m >> k;
    vector<int> a(k);
    for(auto &a : a) cin >> a;
    int lo = 1, hi = 500;
    for(int j=0;j<10;j++) {
      int mid = (lo+hi)/2;
      //test mid
      set<pair<int, int>, greater<pair<int, int>>> in;
      for(int i=0;i<k;i++) {
        if(a[i]) in.insert({a[i], i+1});
      }
      for(int i=0;i<(mid+1)/2*((mid+1)/2) && !in.empty();i++) {
        auto it = *in.begin();
        --it.f;
        if(it.f)
          in.insert(it);
        in.erase(in.begin());
      }
      int mx = 0, tot = 0;
      for(auto &it : in) {
        mx = max(mx, it.f);
        tot += it.f;
      }
      if(tot <= (mid*mid)/2 && mx <= (mid*mid)/4) {
        hi = mid;
      }
      else {
        lo = mid + 1;
      }
    }
    cout << lo << "\n";
    set<pair<int, int>, greater<pair<int, int>>> in;
    for(int i=0;i<k;i++) {
      if(a[i]) in.insert({a[i], i+1});
    }
    vector<vector<int>> ans(lo, vector<int>(lo));
    vector<pair<int, int>> o, e1, e2;
    for(int i=0;i<lo;i+=2) {
      for(int j=0;j<lo;j+=2) {
        o.push_back({i, j});
      }
    }
    for(int i=0;i<lo;i++) {
      for(int j=0;j<lo;j++) {
        if(i%2==0 && (i+j)%2) e1.push_back({i, j});
        else if(i%2==1 && (i+j)%2) e2.push_back({i, j});
      }
    }
    for(int i=0;i<(lo+1)/2*((lo+1)/2) && !in.empty();i++) {
      auto it = *in.begin();
      --it.f;
      if(it.f)
        in.insert(it);
      ans[o.back().f][o.back().s] = it.s;
      o.pop_back();
      in.erase(in.begin());
    }
    if(in.empty()) {
      print(ans);
      continue;
    }
    auto x = *in.begin();
    int num = x.f, col = x.s;
    in.erase(in.begin());
    reverse(e1.begin(), e1.end());
    while(num) {
      ans[e1.back().f][e1.back().s] = col;
      e1.pop_back();
      --num;
    }
    if(in.empty()) {
      print(ans);
      continue;
    }
    x = *in.begin();
    num = x.f, col = x.s;
    int dx[] = {-1, 1, 1, -1};
    int dy[] = {1, -1, 1, -1};
    if(num > e1.size()) {
      while(e1.size()) {
        ans[e1.back().f][e1.back().s] = col;
        e1.pop_back();
        --num;
      }
      for(int i=0;i<lo;i++) {
        for(int j=0;j<lo;j++) {
          if(num && (i+j)%2 && ans[i][j] == 0) {
            bool work = true;
            for(int r=0;r<4;r++) {
              int nx = dx[r] + i, ny = dy[r] + j;
              if(nx<lo&&ny<lo&&nx>=0&&ny>=0 && ans[nx][ny] == col) {
                work = false;
              }
            }
            if(work) {
              ans[i][j] = col;
              --num;
            }
          }
        }
      }
      in.erase(in.begin());
      e2.clear();
      for(int i=0;i<lo;i++) {
        for(int j=0;j<lo;j++) {
          if(i%2==1 && (i+j)%2 && ans[i][j] == 0) e2.push_back({i, j});
        }
      }
    }
      vector<pair<int, int>> ord;
      while(!e1.empty()) {
        ord.push_back(e1.back());
        e1.pop_back();
      }
      ord.insert(ord.end(), e2.begin(), e2.end());
      vector<int> put;
      for(auto &it : in) {
        for(int j=0;j<it.f;j++) {
          put.push_back(it.s);
        }
      }
      int idx = 0;
      for(int i=0;i<ord.size();i++) {
        if(idx == put.size()) continue;
        ans[ord[i].f][ord[i].s] = put[idx++];
      }
      print(ans);
  }
}