#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;
const int M = 755;

int ch[N][2], sz, n, m, x, y, fail[N], word[N], Len, rt, Beg[N], P[M], du[M], to[M];
int pos[N];
bitset < M > f[M];
char s[N];

int add(char *s) {
  int Len = strlen(s + 1);
  int now = rt;
  for(int i = 1; i <= Len; ++ i) {
    if(!ch[now][s[i] - 'a']) {
      ch[now][s[i] - 'a'] = ++ sz;
    }
    now = ch[now][s[i] - 'a'];
  }
  return now;
}

void build() {
  queue <int> q;
  q.push(1);
  while(!q.empty()) {
    int ind = q.front(); q.pop();
    for(int c = 0; c < 2; ++ c) if(ch[ind][c]) {
	int now = ch[ind][c], p = fail[ind];
	while(!ch[p][c] && p) p = fail[p];
	if(!p) p = 1; else p = ch[p][c];
	fail[now] = p; word[now] = (pos[p]) ? p : word[p];
	q.push(now);
    }
  }
  for(int i = 1; i <= n; ++ i) {
    int now = rt;
    for(int j = Beg[i]; j < Beg[i + 1]; ++ j) {
      now = ch[now][s[j] - 'a'];
      int p = now;
      if(j == Beg[i + 1] - 1 || !pos[p]) p = word[p];
      while(p) {
	if(f[i][pos[p]]) break;
	f[i][pos[p]] = 1;
	p = word[p];
      }
    }
  }
}

bool vis[M];

bool dfs(int x) {
  if(vis[x]) return 0;
  vis[x] = 1;
  for(int i = 1; i <= n; ++ i) if(f[x][i]) {
      if(!P[i] || dfs(P[i])) {
	P[i] = x;
	return 1;
      }
  }
  return 0;
}

int Ans[N];

int main() {
  cin >> n; rt = ++ sz;
  int All = 1;
  for(int i = 1; i <= n; ++ i) {
    scanf("%s", s + All);
    Beg[i] = All;
    pos[add(s + All - 1)] = i;
    All += strlen(s + All);
    Beg[i + 1] = All;
  }
  build();
  
  for(int k = 1; k <= n; ++ k)
    for(int i = 1; i <= n; ++ i)
      if(f[i][k]) f[i] |= f[k];
  
  int ans = 0;
  for(int i = 1; i <= n; ++ i) {
    memset(vis, 0, sizeof(vis));
    if(dfs(i)) -- ans;
  }
  ans = 0;
  for(int i = 1; i <= n; ++ i) to[P[i]] = i;
  for(int i = 1; i <= n; ++ i) if(!P[i]) Ans[++ ans] = i;
  while(1) {
    bool flag = 1;
    for(int i = 1; i <= ans; ++ i)
      for(int j = 1; j <= ans; ++ j) {
	if(f[Ans[i]][Ans[j]]) {
	  flag = 0;
	  while(f[Ans[i]][Ans[j]]) Ans[i] = to[Ans[i]];
	}
      }
    if(flag) break;
  }
  cout << ans << endl;
  for(int i = 1; i <= ans; ++ i) cout << Ans[i] <<" ";
  puts("");
}