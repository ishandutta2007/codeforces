#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int cnt, L[N][2];

multiset < int > S[N][2];

int n, m, k;
long long ans, res;

struct NODE {
  int s, t, cost, day;
  void input(void) {
    scanf("%d%d%d%d", &day, &s, &t, &cost);
  }
  friend bool operator < (NODE a, NODE b) {
    return a.day < b.day;
  }
}T[N];

void add(NODE x) {
  if(x.s != 0) {
    if(!L[x.s][0]) -- cnt, ++ L[x.s][0];
    if(S[x.s][0].size()) res -= *S[x.s][0].begin();
    S[x.s][0].insert(x.cost);
    res += *S[x.s][0].begin();
  }
}

void del(NODE x) {
  if(x.s == 0) {
    swap(x.s, x.t);
    if(!(-- L[x.s][1])){
      if(ans > 1e17) cout << "-1" << endl;
      else cout << ans << endl;
      exit(0);
    }
    res -= *S[x.s][1].begin();
    S[x.s][1].erase(S[x.s][1].find(x.cost));
    res += *S[x.s][1].begin();
  }
}

int main() {
  cin >> n >> m >> k;
  cnt = n;
  for(int i = 1; i <= m; ++ i) {
     T[i].input();
     if(T[i].s == 0) ++ L[T[i].t][1], S[T[i].t][1].insert(T[i].cost);
  }
  
  ans = 1e18, res = 0;
  for(int i = 1; i <= n; ++ i) {
    if(!L[i][1]) {
      puts("-1");
      return 0;
    }
    res += *S[i][1].begin();
  }

  
  sort(T + 1, T + m + 1);
  int R = 1;
  for(int i = 1; i < m; ++ i) {
    while(R <= m && T[R].day - T[i].day - 1 < k) {
      del(T[R]); ++ R;
    }
    if(R == m + 1) break;
    add(T[i]);
    if(cnt == 0) ans = min(ans, res);
  }
  if(ans > 1e17) cout << "-1" << endl;
  else cout << ans << endl;
}