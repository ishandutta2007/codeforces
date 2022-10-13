#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6 + 5;
using ll = long long;
#define f first
#define s second
struct pt {
  int x, y;
};
pair<double, double> intersection(pt a, pt b, pt c, pt d) {
  ll a1 = b.y - a.y;
  ll b1 = a.x - b.x;
  ll c1 = a1*(a.x) + b1*(a.y);

  ll a2 = d.y - c.y;
  ll b2 = c.x - d.x;
  ll c2 = a2*(c.x) + b2*(c.y);
  
  ll determinant = a1*b2 - a2*b1;

  if(determinant == 0) {
    return {b.x, b.y};
  }
  else {
    double x = (b2*c1 - b1*c2)*1.0/determinant;
    double y = (a1*c2 - a2*c1)*1.0/determinant;
    return {x, y};
  }
}
int orientation (pt p1, pt p2, pt p3) {
  ll val = (p2.y - p1.y) * 1LL *(p3.x - p2.x) - (p2.x - p1.x) * 1LL * (p3.y - p2.y);
  if(val >= 0) {
    return 1; //clockwise
  }
  else {
    return 0; //counterclockwise
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, H; cin >> n >> H;
  vector<pt> in(n);
  for(int i=0;i<n;i++) {
    cin >> in[i].x >> in[i].y;
  }
  pt sauron = {in[n-1].x, in[n-1].y + H};
  pt best = in[n-1];
  double ans = 0.0;
  for(int i=n-1;i>=0;i--) {
    if(i < n-1) {
      if(orientation(sauron, in[i+1], in[i]) && orientation(sauron, best, in[i])) { //works
        pair<double, double> intersect = intersection(in[i], in[i+1], sauron, best);
        ans += sqrt((intersect.f - in[i].x)*(intersect.f-in[i].x) + (intersect.s-in[i].y)*(intersect.s-in[i].y));
      }
    }
    if(orientation(sauron, best, in[i])) {
      best = in[i];
    }
  }
  cout << setprecision(12) << ans << "\n";
}