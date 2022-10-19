#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 1000000 + 5;
 
inline int add(int x, int y) {
  x += y;
  return x >= mod ? x -= mod : x;
}
 
namespace pam {
  int sz, tot, last;
  int ch[maxn][26], len[maxn], fail[maxn];
  int cnt[maxn], dep[maxn], dif[maxn], slink[maxn];
  char s[maxn];
  int node(int l) {
    sz++; 
    memset(ch[sz], 0, sizeof(ch[sz]));
    len[sz] = l; 
    fail[sz] = 0;
    cnt[sz] = 0;
    dep[sz] = 0;
    return sz;
  }
  void clear() {
    sz = -1; last = 0;
    s[tot = 0] = '$';
    node(0); node(-1);
    fail[0] = 1;
  }
  int getfail(int x) {
    while (s[tot - len[x] - 1] != s[tot]) x = fail[x];
    return x;
  }
  void insert(char c) {
    s[++tot] = c;
    int now = getfail(last);
    if (!ch[now][c - 'a']) {
      int x = node(len[now] + 2);
      fail[x] = ch[getfail(fail[now])][c - 'a'];
      dep[x] = dep[fail[x]] + 1;
      ch[now][c - 'a'] = x;
 
      dif[x] = len[x] - len[fail[x]];
      if (dif[x] == dif[fail[x]]) slink[x] = slink[fail[x]];
      else slink[x] = fail[x];
    }
    last = ch[now][c - 'a'];
    cnt[last]++;
  }
}
using pam::len;
using pam::fail;
using pam::slink;
using pam::dif;
 
int n, dp[maxn], g[maxn], pre[maxn], pre2[maxn]; 
char s[maxn], t[maxn], c[maxn];
 
void print(int x) {
	if(!x) return;
	if(pre[x] + 2 == x); 
	else printf("%d %d\n", pre[x] / 2 + 1, x / 2);
	print(pre[x]);
	return;
}
 
int main() {
  pam::clear();
  scanf("%s", s + 1);
  scanf("%s", c + 1);
  n = strlen(s + 1); 
  for(int i = 1, j = 0; i <= n; ++ i) {
  	t[++ j] = s[i];
  	t[++ j] = c[i];
  }
  dp[0] = 0;
  for(int i = 1; i <= n * 2; ++ i) dp[i] = 1e7;
  n *= 2;
  for (int i = 1; i <= n; i++) {
  	if(i % 2 == 0 && t[i] == t[i - 1])
  	dp[i] = dp[i - 2], pre[i] = i - 2;
    pam::insert(t[i]);
    for (int x = pam::last; x > 1; x = slink[x]) {
      g[x] = dp[i - len[slink[x]] - dif[x]] + 1, 
	  pre2[x] = i - len[slink[x]] - dif[x];
      if (dif[x] == dif[fail[x]]) {
      	if(g[fail[x]] < g[x])
      	g[x] = g[fail[x]], pre2[x] = pre2[fail[x]];
	  }
	  if(g[x] < dp[i] && i % 2 == 0) {
	  	dp[i] = g[x];
	  	pre[i] = pre2[x];
	  }
    }
  }
  if(dp[n] > 5e6) {
  	puts("-1");
  	return 0;
  }
  else {
  	printf("%d\n", dp[n]);
  	print(n);
  }
  return 0;
}