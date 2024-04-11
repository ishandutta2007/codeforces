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
    ints(N);
    vector<int> A(N);
    vector<int> cnt(N+1);
    vector<int> cnt2(N+1);
    int seg = 0;
    for(int i = 0; i < N; i++) {
      cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
      cnt2[A[i]]++;
      if (i == 0 || A[i-1] == A[i]) {
        cnt[A[i]]++;
        seg++;
      }
      if (i == N-1 || A[i+1] == A[i]) {
        cnt[A[i]]++;
      }
    }

    int mc = *max_element(all(cnt2));
    if (2*mc-1 > N) {
      writeln(-1);
      continue;
    }

    int k = max_element(all(cnt)) - cnt.begin();
    int add = 0;

    if (cnt[k] - seg > 1) {
      add = cnt[k] - seg - 1;
    }

    writeln(seg + add - 1);
  }
  return 0;
}