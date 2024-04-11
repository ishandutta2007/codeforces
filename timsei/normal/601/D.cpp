#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int M = N * 2;

int ch[N][26], n, m, x, y, sz, c[N], dep[N], fir[N], ne[M], to[M], cnt, Si[N], S[N];
char s[N];

void add(int x, int y) {
  ne[++ cnt] = fir[x];
  fir[x] = cnt;
  to[cnt] = y;
}

void link(int x, int y) {
  add(x, y); add(y, x);
}

#define Foreachson(i, x) for(int i = fir[x]; i; i = ne[i])

int merge(int x, int V) {
  if(!x || !V) return x + V;
  S[x] = 1;
  for(int i = 0; i < 26; ++ i) {
    ch[x][i] = merge(ch[x][i], ch[V][i]);
    S[x] += S[ch[x][i]];
  }
  return x;
}

int a = 0, b = 0;

void dfs(int x, int f) {
  Si[x] = 1; S[x] = 1;
  int no = 0;
  Foreachson(i, x) {
    int V = to[i];
    if(V == f) continue;
    dfs(V, x);
    if(Si[no] < Si[V]) no = V;
    Si[x] += Si[V];
  }
  ch[x][s[no]] = no;
  S[x] += S[no];
  Foreachson(i, x) {
    int V = to[i];
    if(V == f || V == no) continue;
    S[x] -= S[ch[x][s[V]]];
    ch[x][s[V]] = merge(ch[x][s[V]], V);
    S[x] += S[ch[x][s[V]]];
  }
  if(S[x] + c[x] > a) {
    a = S[x] + c[x];
    b = 1;
  }
  else if(S[x] + c[x] == a) {
    ++ b;
  }
  //cerr << x <<" " << c[x] + S[x] << endl;
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; ++ i) scanf("%d", &c[i]);
  scanf("%s", s + 1); for(int i = 1; i <= n; ++ i) s[i] -= 'a';
  for(int i = 1; i < n; ++ i) scanf("%d%d", &x, &y), link(x, y);
  dfs(1, 0);
  cout << a << endl;
  cout << b << endl;
}