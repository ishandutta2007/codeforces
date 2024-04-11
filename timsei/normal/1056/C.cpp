#include <bits/stdc++.h>
using namespace std;

const int N = 4e3 + 5;

#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)

int n, m, P[N], A[N], B[N], t, tot, x;
bool vis[N], in[N];

struct NODE {
  int x, id;
  friend bool operator < (NODE a, NODE b) {
    return a.x > b.x;
  }
}T[N];

void print(int x) {
  vis[x] = 1;
  printf("%d\n", x);
  fflush(stdout);
}

int must;

void draw() {
  if(must) {
    print(must);
    must = 0;
    return;
  }
  REP(i, 1, m)
    if(!vis[A[i]]) {
      print((P[A[i]] > P[B[i]]) ? A[i] : B[i]);
      return;
    }
  REP(i, 1, tot) if(!vis[T[i].id]) return (void)print(T[i].id);
}

void let() {
  scanf("%d", &x); vis[x] = 1;
  REP(i, 1, m) {
    if(A[i] == x && !vis[B[i]]) must = B[i];
    else if(B[i] == x && !vis[A[i]]) must = A[i];
  }
}

int main() {
  cin >> n >> m;
  REP(i, 1, n * 2) scanf("%d", &P[i]);
  REP(i, 1, m) scanf("%d%d", &A[i], &B[i]), in[A[i]] = in[B[i]] = 1;
  REP(i, 1, n * 2) if(!in[i]) T[++ tot] = (NODE){P[i], i};
  sort(T + 1, T + tot + 1);
  cin >> t;
  REP(i, 1, n * 2) {
    if((i & 1) == (t & 1)) draw();
    else let();
  }
}