#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fst first
#define snd second
#define x first
#define y second
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << (x) << endl;
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ints(TC);
  while(TC--) {
    ints(N, K);
    vector<pii> points;
    for(int i = 0; i < N; i++) {
      ints(x, y);
      points.emplace_back(x, y);
    }

    int ans = -1;
    for(int i = 0; i < N; i++) {
      bool flag = true;
      for(int j = 0; j < N; j++) {
        int d = abs(points[i].x - points[j].x) + abs(points[i].y - points[j].y);
        if (d > K) {
          flag = false;
          break;
        }
      }
      if (flag) {
        ans = 1;
      }
    }
    writeln(ans);
  }
  return 0;
}