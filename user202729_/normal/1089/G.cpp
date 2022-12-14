/*input
1
2
1 0 0 1 1 0 0
100000000
1 0 0 0 1 0 1
1
1 0 0 0 0 0 0
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() { cout << endl; }
template <typename T, typename... Ts>
void print(const T &value, const Ts &...values) {
  cout << value << ' ', print(values...);
}
#endif
// const int N =;

class Solver {
  int n;
  vector<int> a;

  int findLen(int x) {
    int ret = 1e18;
    loop(i, 0, 6) {
      int sum = 0;
      loop(j, 0, 6) {
        sum += a[(i + j) % 7];
        if (sum >= x) {
          ret = min(ret, j + 1);
          break;
        }
      }
    }
    return ret;
  }

public:
  void operator()() {
    cin >> n;
    a = vector<int>(7, 0);
    for (auto &it : a)
      cin >> it;

    int sum = 0;
    for (auto &it : a)
      sum += it;

    int baseWeeks = n / sum;
    int rem = n % sum;
    if (rem == 0) {
      baseWeeks--;
      rem = sum;
    }

    int lenForRem = findLen(rem);
    cout << baseWeeks * 7 + lenForRem << endl;
  }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    Solver solve;
    solve();
  }
}