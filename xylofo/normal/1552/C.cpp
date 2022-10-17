#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=int(b); a<int(c); ++a)
using namespace std;

bool cross(int x, int y, int a, int b) {
  if(x>a) {
    swap(x,a);
    swap(y,b);
  }
  if(y>b) return false;
  else if(y<a) return false;
  else return true;
}

int calc_intersections(vector<pair<int,int>> & p) {
  int ret=0;
  rep(i,0,p.size()) {
    rep(j,i+1,p.size()) {
      int x=p[i].first;
      int y=p[i].second;
      int a=p[j].first;
      int b=p[j].second;
      if(cross(x,y,a,b)) ++ret;
    }
  }
  return ret;
}

void solve() {
  int n,k; cin >> n >> k;
  vector<bool> points(2*n);
  vector<pair<int,int>> pairs;
  rep(i,0,k) {
    int x,y; cin >> x >> y;
    points[x-1]=true;
    points[y-1]=true;
    if(x>y) swap(x,y);
    pairs.emplace_back(x-1,y-1);
  }
  vector<int> points_left;
  rep(i,0,2*n) {
    if(!points[i]) points_left.push_back(i);
  }
  int m=points_left.size()/2;
  rep(i,0,m) {
    pairs.emplace_back(points_left[i], points_left[i+m]);
  }
  cout << calc_intersections(pairs) << endl;
}

int main() {
  int t; cin >> t;
  rep(i,0,t) solve();
}