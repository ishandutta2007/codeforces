#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int M = 2e6 + 5;

const int mod = 1e9 + 7;

typedef pair <int, int> pii;

vector <pii> Div[M];
int n, pr[M], cnt, A[N], S[M], K[M];
bitset <M> isp;

namespace {
  int add(int x) {return (x >= mod) ? x - mod : x;}
  int sub(int x) {return (x < 0) ? x + mod : x;}
  void Add(int &x, int y) {x = add(x + y);}
  void Sub(int &x, int y) {x = sub(x - y);}
  int Pow(int x, int y) {
    int res = 1;
    for(; y; y >>= 1, x = 1LL * x * x % mod) {
      if(y & 1) {
	res = 1LL * res * x % mod;
      }
    }
    return res;
  }
}

vector <int> Chos;

void prework(int n) {
  for(int i = 2; i <= n; ++ i) isp[i] = 1;
  for(int i = 1; i <= n; ++ i) {
    if(isp[i]) pr[++ cnt] = i;
    for(int j = 1; j <= cnt && pr[j] * i <= n; ++ j) {
      isp[pr[j] * i] = 0;
      if(i % pr[j] == 0) break;
    }
  }
  for(int i = 1; i <= cnt; ++ i) {
    for(int j = pr[i]; j <= n; j += pr[i]) {
      int now = j, tot = 0;;
      while(now % pr[i] == 0) {
	now /= pr[i];
	++ tot;
      }
      Div[j].push_back(make_pair(pr[i], tot));
    }
  }
}

bool cmp(int x, int y) {
  return (x > y);
}

bool pd(int x) {
  bool ok = 1;
  for(int i = 0; i < (int) Div[x].size(); ++ i) {
    if(K[Div[x][i].first] >= 2 ||  Div[x][i].second < S[Div[x][i].first]) {
      ok = 1;
    }
    else {ok = 0; break;};
  }
  return ok;
}

void Upd(int x, int y) {
  if(S[x] > y) return;
  if(S[x] == y) ++ K[x];
  else S[x] = y, K[x] = 1;
}

main() {
  int ans = 1;
  prework(2e6);
  cin >> n;
  for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
  sort(A + 1, A + n + 1, cmp);
  for(int i = 1; i <= n; ++ i) {
    if(!S[A[i]]) {
      ++ S[A[i]];
      ++ K[A[i]];
      Chos.push_back(A[i]);
    }
    else {
      for(int j = 0; j < (int)Div[A[i] - 1].size(); ++ j) {
	Upd(Div[A[i] - 1][j].first, Div[A[i] - 1][j].second);
      }
      Chos.push_back(A[i] - 1);
    }
  }
  for(int i = 1; i < M; ++ i) {
    for(int j = 1; j <= S[i]; ++ j) ans = 1LL * ans * i % mod;
  }
  bool ok = 0;
  for(int i = 0; i < (int) Chos.size(); ++ i) {
    //if(pd(Chos[i])) cerr << i + 1 <<" " << Chos[i] << endl;
    ok |= pd(Chos[i]);
  }
  cout << add(ans + ok) << endl;
}