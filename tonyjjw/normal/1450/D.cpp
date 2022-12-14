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

struct UF {
  int N;
  vector<int> p;
  vector<pii> seg;

  UF(int _N) {
    N = _N;
    p.resize(_N);
    seg.resize(_N);
    iota(all(p), 0);
    for(int i = 0; i < _N; i++) {
      seg[i] = {i, i};
    }
  }

  int par(int n) {
    if (p[n] == n) return n;
    return p[n] = par(p[n]);
  }

  void merge(int n1, int n2) {
    n1 = par(n1);
    n2 = par(n2);
    seg[n2].fst = min(seg[n2].fst, seg[n1].fst);
    seg[n2].snd = max(seg[n2].snd, seg[n1].snd);
    p[n1] = n2;
  }

  pii lr(int n) {
    return seg[par(n)];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ints(TC);
  while(TC--) {
    ints(N);
    vector<int> A(N);
    vector<bool> joined(N);
    vector<vector<int>> pos(N+1);
    vector<int> chk(N+2);
    vector<int> tmp(N+2);
    auto mark = [&](int st, int ed) {
      chk[st]++;
      chk[ed+1]--;
    };

    for(int i = 0; i < N; i++) {
      cin >> A[i];
      pos[A[i]].push_back(i);
    }

    UF uf(N);
    for(int v = N; v >= 1; v--) {
      if (pos[v].empty()) {
        mark(1, N-v+1);
        continue;
      }

      for(int &p: pos[v]) {
        joined[p] = true;
        if (p > 0 && joined[p-1]) uf.merge(p-1, p);
        if (p < N-1 && joined[p+1]) uf.merge(p, p+1);
      }

      int ng = -1;
      bool multigroup = false;
      bool multielem = false;
      vector<int> group_lens;
      int max_single = 0;
      for(int &p: pos[v]) {
        auto seg = uf.lr(p);

        if (ng != uf.par(p)) {
          if (ng != -1) {
            multigroup = true;
          }
          ng = uf.par(p);

          group_lens.push_back(seg.snd - seg.fst + 1);
        }

        tmp[uf.par(p)]++;
        if (seg.fst != p && seg.snd != p) {
          max_single = max(max_single, seg.snd - seg.fst);
        }

        if(tmp[uf.par(p)] > 1) {
          multielem = true;
          max_single = max(max_single, seg.snd - seg.fst);
        }
      }

      int st = multielem ? 1 : 2;
      if (max_single >= 1) {
        mark(st, max_single);
      }

      if(multigroup) {
        sort(all(group_lens), greater<int>());
        mark(1, group_lens[1]);
      }

      for(int &p: pos[v]) {
        tmp[uf.par(p)]--;
      }
    }

    for(int i = 1; i <= N; i++) {
      chk[i] += chk[i-1];
      if (chk[i] > 0) cout << "0";
      else cout << "1";
    }
    cout << '\n';
  }
  return 0;
}