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

  ints(T);
  for(int t = 0; t < T; t++) {
    lls(N, W);
    vector<ll> A(N);
    for(int i = 0; i < N; i++) {
      cin >> A[i];
    }
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) {
      return A[i] > A[j];
    });
    ll s = 0;
    vector<int> ans;
    bool flag = false;
    for(auto &o: ord) {
      if (s + A[o] > W) continue;
      s += A[o];
      ans.push_back(o+1);
      if (2*s >= W) {
        flag = true;
        break;
      }
    }

    if(!flag) {
      writeln(-1);
    }
    else {
      cout << sz(ans) << '\n';
      sort(all(ans));
      for(auto &a: ans) cout << a << ' ';
      cout << '\n';
    }
  }
  
  return 0;
}