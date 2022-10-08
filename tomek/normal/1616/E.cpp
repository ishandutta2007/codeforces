#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int _n=(n), i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << endl;

void init_io() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
}

constexpr int alphabet = 26;
constexpr int64_t infinity = numeric_limits<int64_t>::max();
constexpr int group_size = 300;

class Sum {
public:
  Sum(int nn):
    n(nn),
    available(n, 1),
    group_count(n / group_size + 1, group_size)
  {}

  int count_smaller(int x) {
    int res = 0;
    int i=0;
    int pos = 0;
    while (pos + group_size <= x) {
      res += group_count[i];
      ++i;
      pos += group_size;
    }
    while (pos < x) {
      res += available[pos];
      ++pos;
    }
    return res;
  }

  void erase(int x) {
    available[x] = 0;
    group_count[x / group_size] -= 1;
  }

private:
  int n;
  vector<char> available;
  vector<int> group_count;
};

int64_t solve_one() {
  int len; cin >> len;
  string text, goal;
  cin >> text >> goal;
  vector<int> positions[alphabet];
  REP(i,len) positions[text[i]-'a'].push_back(i);
  for (auto &v : positions) reverse(v.begin(), v.end());

  Sum available(len);

  int64_t best_result = infinity;
  int64_t result = 0;

  REP(i, len) {
    int goal_c = goal[i] - 'a';
    int best_smaller = len;
    REP(c, goal_c) {
      if(!positions[c].empty()) {
        best_smaller = min(best_smaller, positions[c].back());
      }
    }
    if (best_smaller < len) {
      int pos_smaller = available.count_smaller(best_smaller);
      best_result = min(best_result, result + pos_smaller);
    }

    if (positions[goal_c].empty()) break;
    int equal = positions[goal_c].back();
    positions[goal_c].pop_back();
    result += available.count_smaller(equal);
    available.erase(equal);
  }

  return best_result == infinity ? -1 : best_result;
}

int main() {
  init_io();

  int ntc; cin >> ntc;
  REP(tc, ntc) {
    auto x = solve_one();
    cout << x << "\n";
  }
}