#include <bits/stdc++.h>

using namespace std;

const int maxn = 12;
const int maxl = 105;
const int sigma = 55;

inline char fuck(int x){ return x < 26 ? 'A' + x : 'a' + (x - 26); }

int n;
int cnt[maxn][sigma], a[maxn][sigma][2];
int f[1 << maxn][sigma];
pair<int, int> g[1 << maxn][sigma];
int go[maxn][maxl][sigma];
char s[maxn][maxl];

inline int ID(char c){ return c <= 'Z' ? c - 'A' : c - 'a' + 26; }

inline void solve(){
  scanf("%d", &n);
  memset(a, -1, sizeof(a));
  for(int i = 0; i < n; ++i){
    scanf("%s", s[i]);
    for(int j = 0; j < 52; ++j)
      cnt[i][j] = 0;
    int len = strlen(s[i]);
    for(int j = 0; j < len; ++j)
      a[i][ID(s[i][j])][cnt[i][ID(s[i][j])]++] = j;
    for(int j = len; j >= 0; --j){
      for(int k = 0; k < 53; ++k)
	go[i][j][k] = (j == len ? -1 : go[i][j + 1][k]);
      if(j < len)
	go[i][j][ID(s[i][j])] = j;
    }
  }

  memset(f, -1, sizeof(f));
  f[0][52] = 0;
  int len = strlen(s[0]);
  for(int it = -1; it < len; ++it){
    int p = (it == -1 ? 52 : ID(s[0][it]));
    //printf("it = %d p = %d\n", it, p);
    for(int S = 0; S < (1 << n); ++S)
      if(f[S][p] >= 0){
	//printf("  S = %d p = %d f = %d\n", S, p, f[S][p]);
	for(int c = 0; c < 52; ++c){
	  int T = 0; bool ok = true;
	  for(int i = 0; i < n; ++i){
	    int pos = a[i][p][S >> i & 1] + 1;
	    int nxt = go[i][pos][c];
	    if(nxt == -1){
	      ok = false;
	      break;
	    }
	    //printf("    c = %d i = %d pos = %d nxt = %d %d (%d %d)\n", c, i, pos, nxt, nxt == a[i][c][1], a[i][c][0], a[i][c][1]);
	    T ^= ((nxt == a[i][c][1]) << i);
	  }
	  if(ok && f[S][p] + 1 > f[T][c]){
	    f[T][c] = f[S][p] + 1;
	    g[T][c] = make_pair(S, p);
	  }
	}
      }
  }
  
  int S = -1, c = -1;
  for(int T = 0; T < (1 << n); ++T)
    for(int i = 0; i < 53; ++i)
      if(!~S || f[S][c] < f[T][i])
	S = T, c = i;
  printf("%d\n", f[S][c]);
  string ans = "";
  for(; f[S][c] > 0; ){
    ans += fuck(c);
    int T = g[S][c].first, i = g[S][c].second;
    S = T, c = i;
  }
  reverse(ans.begin(), ans.end());
  printf("%s\n", ans.c_str());
  return;
}

int main(){
  //freopen("D.in", "r", stdin);
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}