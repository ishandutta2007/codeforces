#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
const int MX = 3e6+5;
vector<int> idx[MX];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) {
    cin >> a[i];
    idx[a[i]].push_back(i+1);
  }
  sort(a.begin(), a.end());
  vector<vector<pair<int, int>>> dif(MX, vector<pair<int, int>>());
  if(n >= 2000) {
    for(int i=0;i<n-1;i++) {
      dif[a[i+1]-a[i]].push_back({i, i+1});
    }
    for(int i=0;i<MX;i++) {
      if(dif[i].empty()) continue;
      pair<int, int> x = {dif[i][0].f, dif[i][0].s};
      pair<int, int> y = {-1, -1};
      for(auto &r : dif[i]) {
        if(r.f != x.f && r.f != x.s && r.s != x.f && r.s != x.s) {
          y = r;
        }
      }
      if(y.f == -1) continue;
      cout << "YES" << "\n";
      //w
      cout << idx[a[x.f]].back() << " ";
      idx[a[x.f]].pop_back();
      //z
      cout << idx[a[y.s]].back() << " ";
      idx[a[y.s]].pop_back();
      //w
      cout << idx[a[x.s]].back() << " ";
      idx[a[x.s]].pop_back();
      //y
      cout << idx[a[y.f]].back() << " ";
      idx[a[y.f]].pop_back();
      return 0;
    }
  }
  else {
    for(int i=0;i<n;i++) {
      for(int j=i+1;j<n;j++) {
        dif[a[j]-a[i]].push_back({i, j});
      }
    }
    for(int i=0;i<MX;i++) {
      if(dif[i].empty()) continue;
      pair<int, int> x = {dif[i][0].f, dif[i][0].s};
      pair<int, int> y = {-1, -1};
      for(auto &r : dif[i]) {
        if(r.f != x.f && r.f != x.s && r.s != x.f && r.s != x.s) {
          y = r;
        }
      }
      if(y.f == -1) continue;
      cout << "YES" << "\n";
      //w
      cout << idx[a[x.f]].back() << " ";
      idx[a[x.f]].pop_back();
      //z
      cout << idx[a[y.s]].back() << " ";
      idx[a[y.s]].pop_back();
      //w
      cout << idx[a[x.s]].back() << " ";
      idx[a[x.s]].pop_back();
      //y
      cout << idx[a[y.f]].back() << " ";
      idx[a[y.f]].pop_back();
      return 0;
    }
  }
  cout << "NO" << "\n";
}