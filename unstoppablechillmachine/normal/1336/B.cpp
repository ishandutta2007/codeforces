#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

inline int sq(int a) {
  return a * a;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    vector<vector<int>> kek(3);
    kek[0].resize(a);
    kek[1].resize(b);
    kek[2].resize(c);
    for (int i = 0; i < 3; i++) {
      for (auto &it : kek[i]) {
        cin >> it;
      }
      sort(all(kek[i]));
    }
    vector<int> order = {0, 1, 2};
    int rez = sq(kek[0][0] - kek[1][0]) + sq(kek[0][0] - kek[2][0]) + sq(kek[1][0] - kek[2][0]);
    do {
      int ptr1 = 0, ptr2 = 0;
      for (auto it : kek[order[0]]) {
        if (it < kek[order[1]][ptr1]) {
          continue;
        }
        while (ptr1 + 1 < SZ(kek[order[1]]) && kek[order[1]][ptr1 + 1] <= it) {
          ptr1++;
        }
        while (ptr2 < SZ(kek[order[2]]) && kek[order[2]][ptr2] < it) {
          ptr2++;
        } 
        if (ptr2 == SZ(kek[order[2]])) {
          continue;
        }
        assert(it >= kek[order[1]][ptr1]);
        assert(it <= kek[order[2]][ptr2]);
        rez = min(rez, sq(it - kek[order[1]][ptr1]) + sq(it - kek[order[2]][ptr2]) + sq(kek[order[1]][ptr1] - kek[order[2]][ptr2]));
      }
    } while (next_permutation(all(order)));
    cout << rez << '\n';
  }   
}