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

  ints(N);
  vector<int> A(N);
  vector<int> cnt(100+1);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    cnt[A[i]]++;
  }
  int a = max_element(all(cnt)) - cnt.begin();
  int ans = 0;

  for(int b = 1; b <= 100; b++) {
    if (cnt[b] == 0) continue;
    if (a == b) continue;
    vector<int> pos(N+1);
    for(int i = 0; i <= N; i++) {
      pos[i] = -10;
    }
    pos[0] = -1;

    int ca = 0, cb = 0;
    for(int i = 0; i < N; i++) {
      if (A[i] == a) ca++;
      if (A[i] == b) cb++;

      if (ca - cb >= 0) {
        if(pos[ca-cb] == -10) pos[ca-cb] = i;
        else {
          ans = max(ans, i - pos[ca-cb]);
          // writeln("@", a, b, ca, cb, ans);
        }
      }
    }
  }

  writeln(ans);
  return 0;
}