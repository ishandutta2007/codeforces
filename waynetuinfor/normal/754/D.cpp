#include <iostream>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

struct Segment {
  int id, L, R;
  bool operator<(const Segment& seg) const {
    return L < seg.L;
  }
};

vector<Segment> vec;
set<pair<int, int>> s;
int n, k, L, R, Max, best;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> k;
  vec.push_back((Segment){ 0, INT_MIN, INT_MAX });
  for (int i = 1; i <= n; ++i) {
    cin >> L >> R;
    vec.push_back((Segment){ i, L, R });
  }
  sort(vec.begin(), vec.end());
  for (int i = 1; i <= n; ++i) {
    s.insert(make_pair(vec[i].R, vec[i].id));
    if (s.size() > k) s.erase(s.begin());
    if (s.size() == k) {
      int len = s.begin()->first - vec[i].L + 1;
      if (len > Max) Max = len, best = i;
    }
  }
  cout << Max << '\n';
  if (!Max) {
    for (int i = 1; i <= k; ++i) cout << i << ' ';
    return 0;
  }
  s.clear();
  for (int i = 1; i <= n; ++i) {
    s.insert(make_pair(vec[i].R, vec[i].id));
    if (s.size() > k) s.erase(s.begin());
    if (i == best) {
      for (auto a : s) cout << a.second << ' ';
      return 0;
    }
  }
}