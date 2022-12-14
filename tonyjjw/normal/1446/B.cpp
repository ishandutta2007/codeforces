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

int N, M;

const int MN = 5000 + 5;

int D[MN][MN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;

  string s1, s2;
  cin >> s1 >> s2;
  int ans = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      int v1 = -1e9;
      if (s1[i-1] == s2[j-1]) {
        v1 = D[i-1][j-1] + 2;
      }
      int v2 = D[i-1][j] - 1;
      int v3 = D[i][j-1] - 1;
      D[i][j] = max({0, v1, v2, v3});
      ans = max(ans, D[i][j]);
    }
  }
  writeln(ans);
  
  return 0;
}