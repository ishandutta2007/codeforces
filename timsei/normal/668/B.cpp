#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, q, t, x, y, A[N];
int fil, cur, dir;

int f(int x) {
  if(x % 2 != 0) return 1;
  return 0;
}

vector <int> G;

void get(void) {
  vector <int> ano;
  ano.clear();
  for(int i = 0; i < (int) G.size(); ++ i) {
    if(ano.size() && ano.back() == G[i]) {
      ano.pop_back();
      continue;
    }
    else ano.push_back(G[i]);
  }
  if(!ano.size()) return;
  if(ano[0] == 0) fil = ano.size();
  else fil = -(int)ano.size();
}

int main() {
  int it = 1;
  scanf("%d%d", &n, &q);
  dir = -1;
  for(int i = 1; i <= q; ++ i) {
    scanf("%d", &t);
    if(t == 1) {
      scanf("%d", &x);
      cur += x;
      cur %= n;
      if(x & 1) it = it * (-1);
    }
    else {
      G.push_back(f(cur));
    }
  }
  get();
  cerr << fil << endl;
  for(int i = 0; i < n; ++ i) {
    if(i % 2 == 0)
      A[(i + fil % n + n) % n] = i;
    else A[(i - fil % n + n) % n] = i;
  }
  cur %= n;
  cur = - cur;
  cur = (cur + n) % n;
  for(int i = 0; i < n; ++ i)
    printf("%d ", A[(cur + i) % n] + 1);
}