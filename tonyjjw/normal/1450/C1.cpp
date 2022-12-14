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

const int MN = 300 + 5;

char s[MN][MN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ints(TC);
  while(TC--) {
    ints(N);
    int cnt[3] = {0, };
    for(int i = 0; i < N; i++) {
      cin >> s[i];
      for(int j = 0 ; j < N; j++) {
        if (s[i][j] == 'X') {
          cnt[(i+j)%3]++;
        }
      }
    }

    int p = 0;
    if (cnt[p] > cnt[1]) p = 1;
    if (cnt[p] > cnt[2]) p = 2;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        if (s[i][j] == 'X') {
          if (p == (i+j)%3) s[i][j] = 'O';
        }
      }
    }

    for(int i = 0; i < N; i++) {
      writeln(s[i]);
    }
  }
  return 0;
}