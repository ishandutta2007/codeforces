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

const int MN = 100+5;

int A[MN][MN];

struct AA {
  int x1, y1, x2, y2, x3, y3;

  AA(){}
  AA(pii p1, pii p2, pii p3) {
    x1 = p1.fst;
    y1 = p1.snd;
    x2 = p2.fst;
    y2 = p2.snd;
    x3 = p3.fst;
    y3 = p3.snd;
  }
};

vector<AA> ans;

void f(int x1, int y1, int x2, int y2, int x3, int y3) {
  A[x1][y1] ^= 1;
  A[x2][y2] ^= 1;
  A[x3][y3] ^= 1;
  ans.emplace_back(pii(x1+1, y1+1), pii(x2+1, y2+1), pii(x3+1, y3+1));
}

void f(pii p1, pii p2, pii p3) {
  f(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
}

void solve() {
  ints(N, M);
  ans.clear();
  string inp;

  for(int i = 0; i < N; i++) {
    cin >> inp;
    for(int j = 0; j < M; j++) {
      A[i][j] = (inp[j] == '1');
    }
  }

  if(N&1) {
    for(int j = 0; j < M; j++) {
      if(A[0][j] == 1) {
        if (j == M-1) {
          f(0, j, 1, j-1, 1, j);
        }
        else {
          f(0, j, 0, j+1, 1, j);
        }
      }
    }
  }
  if(M&1) {
    for(int i = 0; i < N; i++) {
      if(A[i][0] == 1) {
        if (i == N-1) {
          f(i, 0, i, 1, i-1, 1);
        }
        else {
          f(i, 0, i+1, 0, i, 1);
        }
      }
    }
  }
  for(int i = N&1; i < N; i += 2) {
    for(int j = M&1; j < M; j += 2) {
      while(true) {
        int sum = A[i][j] + A[i+1][j] + A[i][j+1] + A[i+1][j+1];
        vector<pii> p = {{i, j}, {i+1, j}, {i, j+1}, {i+1, j+1}};
        sort(all(p), [&](pii a, pii b) {
          return A[a.x][a.y] < A[b.x][b.y];
        });
        if (sum == 0) break;
        else if (sum == 1) {
          f(p[0], p[1], p[3]);
        }
        else if (sum == 2) {
          f(p[0], p[1], p[2]);
        }
        else if (sum == 3) {
          f(p[1], p[2], p[3]);
        }
        else {
          f(p[0], p[1], p[2]);
        }
      }
    }
  }

  writeln(sz(ans));
  for(auto &aa: ans) {
    writeln(aa.x1, aa.y1, aa.x2, aa.y2, aa.x3, aa.y3);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ints(T);
  while(T--) {
    solve();
  }
  return 0;
}