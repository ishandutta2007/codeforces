#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
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

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;

int x[100000];
int y[100000];
int n, a;

typedef pair<double, int> pdi;
const double PI = acos(-1);

double normalize(double theta) {
  if(theta < -PI) theta += 2 * PI;
  if(theta >= PI) theta -= 2 * PI;
  return theta;
}

bool seen[100005];
bool can(double r) {
  vector<pdi> events;
  for(int i = 0; i < n; i++) {
    // circle centered at (-a, 0) has radius R
    double R = hypot(x[i] + a, y[i]);
    // circle with radius r around (a, 0)
    double d = hypot(x[i] - a, y[i]);
    if(R+d<=r) continue;
    if(R+r<=d) continue;
    if(r+d<=R) continue;
    double base = atan2(y[i], a - x[i]);
    double theta = acos((r*r+d*d-R*R)/(2*r*d));
    events.push_back(pdi(normalize(base - theta), i));
    events.push_back(pdi(normalize(base + theta), i));
  }
  sort(all(events));
  stack<int> s;
  memset(seen, 0, sizeof(seen));
  for(auto out: events) {
    if(seen[out.second]) {
      if(sz(s) == 0 || s.top() - out.second) return true;
      s.pop();
    }
    else {
      s.push(out.second);
      seen[out.second] = true;
    }
  }
  return false;
}

void solve() {
  cin >> n >> a;
  for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
  double lhs = 0;
  double rhs = 2*a;
  for(int qq = 0; qq < 50; qq++) {
    double mid = (lhs+rhs)/2;
    if(can(mid)) rhs = mid;
    else lhs = mid;
  }
  cout << fixed << setprecision(12) << rhs << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}