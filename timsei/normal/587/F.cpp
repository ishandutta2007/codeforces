#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = N * 2;

int ch[N][26], n, q, L[N], End[N], l, r, x, rt, sz, fail[N];
char s[N];
string All[N];
long long Ans[N];

struct Q {
  int x, type, id;
};

struct Q2 {
  int l, r, id;
};

vector < Q > Qu[N];
vector < Q2 > Al[N];

int add(char *s, int Len) {
  int now = rt;
  for(int i = 1; i <= Len; ++ i) {
    if(!ch[now][s[i] - 'a'])
      ch[now][s[i] - 'a'] = ++ sz;
    now = ch[now][s[i] - 'a'];
  }
  return now;
}

const int Block = 370;

int Lb[N], Rb[N], S[N], dlc;
vector <int> Son[N];

void dfs(int x) {
  if(!x) return;
  Lb[x] = ++ dlc;
  for(int i = 0; i < (int) Son[x].size(); ++ i) {
    int V = Son[x][i];
    dfs(V);
  }
  Rb[x] = dlc;
}

void build() {
  queue <int> q;
  while(!q.empty()) q.pop();
  q.push(rt);
  while(!q.empty()) {
    int ind = q.front();
    q.pop();
    for(int i = 0; i < 26; ++ i) if(ch[ind][i]) {
      int d = ch[ind][i];
      int &now = fail[d];
      now = fail[ind];
      while(!ch[now][i] && now) now = fail[now];
      if(!now) now = 1; else now = ch[now][i];
      Son[now].push_back(d);
      q.push(d);
    }
    for(int i = 0; i < 26; ++ i) if(!ch[ind][i]) {
	int now = fail[ind];
	while(!ch[now][i] && now) now = fail[now];
	if(!now) now = 1; else now = ch[now][i];
	ch[ind][i] = now;
      }
  }
  dfs(1);
  //for(int i = 1; i <= sz; ++ i)
  //cerr << i <<" " << Lb[i] <<" " << Rb[i] << endl;
  
}

int ntot, id[N], Bid[N];
long long ans[N];

void solve(int x) {
  int now = rt;
  memset(S, 0, sizeof(S));
  for(int i = 0; i < All[x].size(); ++ i) {
    now = ch[now][All[x][i] - 'a'];
    ++ S[Lb[now]];
  }
  for(int i = 1; i <= dlc; ++ i) S[i] += S[i - 1];
  id[++ ntot] = x; Bid[x] = ntot;
  for(int i = 1; i <= n; ++ i) {
    ans[i] = ans[i - 1] + (S[Rb[End[i]]] - S[Lb[End[i]] - 1]);
  }
  //cerr << x <<" " << ans[ntot][n] << endl;
  for(int i = 0; i < (int)Al[x].size(); ++ i)
    Ans[Al[x][i].id] = ans[Al[x][i].r] - ans[Al[x][i].l - 1];
}

#define lowbit(x) (x & (-x))

namespace BIT {
  int S[N];

  void init() {
    memset(S, 0, sizeof(S));
  }
  
  void add(int x, int v) {
    for(int i = x; i < N; i += lowbit(i))
      S[i] += v;
  }
  long long Sum(int x) {
    long long res = 0;
    for(int i = x; i; i -= lowbit(i))
      res += S[i];
    return res;
  }
}

int main() {
  rt = ++ sz;
  scanf("%d%d", &n, &q);
  for(int i = 1; i <= n; ++ i) {
    scanf("%s", s + 1);
    L[i] = strlen(s + 1);
    for(int j = 1; j <= L[i]; ++ j)
      All[i] += s[j];
    End[i] = add(s, L[i]);
    //cerr << i <<" " << All[i] << endl;
  }
  build();
  for(int i = 1; i <= q; ++ i) {
    scanf("%d%d%d", &l, &r, &x);
    if(All[x].size() >= Block) {
      Al[x].push_back((Q2){l, r, i});
      continue;
    }
    else {
      Qu[l - 1].push_back((Q){x, -1, i});
      Qu[r].push_back((Q){x, 1, i});
    }
  }
  for(int i = 1; i <= n; ++ i)
    if(All[i].size() >= Block) solve(i);
  BIT :: init();
  for(int i = 1; i <= n; ++ i) {
    BIT :: add(Lb[End[i]], 1);
    BIT :: add(Rb[End[i]] + 1, -1);
    for(int j = 0; j < (int) Qu[i].size(); ++ j) {
      Q now = Qu[i][j];
      long long res = 0;
      int it = rt;
      for(int k = 0; k < All[now.x].size(); ++ k) {
	it = ch[it][All[now.x][k] - 'a'];
	res += BIT :: Sum(Lb[it]);
      }
      //cerr << res << " " << now.id <<' ' << now.x << " " << i <<   endl;
      Ans[now.id] += res * now.type;
    }
  }
  for(int i = 1; i <= q; ++ i) printf("%lld\n", Ans[i]);
}