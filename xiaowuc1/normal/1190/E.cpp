#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<pii, int> ppiii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> query;

const double PI = 2 * acos(0);

struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

inline double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
inline double dist2(PT p, PT q)   { return dot(p-q,p-q); }
inline double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  return os << "(" << p.x << "," << p.y << ")";
}

bool cmp(pdd a, pdd b) {
  if(a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}

const int MAX_D = 16;
int inc[100005][MAX_D];

double dist[100005];
double theta[100005];
PT origPts[100005];
int n;
pdd v[200005];

bool almostEqual(double a, double b) {
  return fabs(a-b) < 1e-10;
}

bool can(int allowed, double r) {
  int idx = 0;
  for(int i = 0; i < n; i++) {
    PT out = origPts[i];
    double lhs = acos(r / dist[i]);
    double a = theta[i]-lhs;
    double b = theta[i]+lhs;
    if(a < 0) {
      a += 2 * PI;
      b += 2 * PI;
    }
    if(a >= 2 * PI) {
      a -= 2 * PI;
      b -= 2 * PI;
    }
    v[idx++] = {a, b};
    v[idx++] = {a + 2*PI, b + 2*PI};
  }
  sort(v, v+idx, cmp);
  {
    stack<pdd> clean;
    for(int i = 0; i < idx; i++) {
      pdd out = v[i];
      while(!clean.empty() && out.first >= clean.top().first && out.second <= clean.top().second) clean.pop();
      clean.push(out);
    }
    idx = 0;
    while(!clean.empty()) {
      v[idx++] = clean.top();
      clean.pop();
    }
    reverse(v, v+idx);
  }
  {
    stack<pdd> superclean;
    int j = 0;
    for(int i = 0; i < idx; i++) {
      while(j < idx && v[j].first - v[i].first <= 2*PI - 1e-10) j++;
      if(j < idx && almostEqual(v[j].first - v[i].first, 2*PI) && almostEqual(v[j].second - v[i].second, 2*PI)) {
        superclean.push(v[i]);
      }
    }
    idx = 0;
    while(!superclean.empty()) {
      v[idx++] = superclean.top();
      superclean.pop();
    }
    reverse(v, v+idx);
  }
  for(int i = 0; i < idx; i++) {
    int lhs = 0;
    int rhs = idx;
    while(lhs != rhs) {
      int mid = (lhs+rhs+1)/2;
      int j = (i+mid)%idx;
      if(v[i].second >= v[j].first && v[i].second <= v[j].second) {
        lhs = mid;
      }
      else if(v[i].second >= v[j].first + 2*PI && v[i].second <= v[j].second + 2*PI) {
        lhs = mid;
      }
      else if(v[i].second >= v[j].first - 2*PI && v[i].second <= v[j].second - 2*PI) {
        lhs = mid;
      }
      else {
        rhs = mid-1;
      }
    }
    inc[i][0] = min(idx, lhs+1);
  }
  for(int d = 1; d < MAX_D; d++) {
    for(int i = 0; i < idx; i++) {
      inc[i][d] = inc[i][d-1] + inc[(i+inc[i][d-1])%idx][d-1];
    }
  }
  for(int i = 0; i < idx; i++) {
    int curr = i;
    int left = allowed;
    int added = 0;
    for(int d = MAX_D-1; d >= 0; d--) {
      while((1<<d) <= left) {
        left -= (1<<d);
        int now = inc[curr][d];
        added += now;
        curr += now;
        curr %= idx;
      }
    }
    if(added >= idx) return true;
  }
  return false;
}

void solve() {
  int m;
  cin >> n >> m;
  double lhs = 0;
  double rhs = 1e9;
  for(int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    rhs = min(rhs, sqrt(x*x+y*y));
    origPts[i] = PT(x, y);
    theta[i] = -atan2(y, x);
    dist[i] = sqrt(x*x+y*y);
  }
  for(int qq = 0; rhs != 0 && qq < 40; qq++) {
    double mid = (lhs+rhs)/2;
    if(can(m, mid)) lhs = mid;
    else rhs = mid;
  }
  cout << fixed << setprecision(12) << lhs << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << " ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}