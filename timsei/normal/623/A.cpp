#include <bits/stdc++.h>
using namespace std;

const int N = 505;

bool way[N][N];

int n, x, y, m;

char s[N];

main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= m; ++ i) {
	scanf("%d%d", &x, &y);
	way[x][y] = 1;
	way[y][x] = 1;
  }
  
  int ok = 0;
  
  for(int i = 1; i <= n; ++ i) { 
	way[i][i] = 1;
	for(int j = 1; j <= n; ++ j) {
	  if(!way[i][j]) {
		ok = i; break;
	  }
	}
	if(ok) break;
  }
  for(int i = 1; i <= n; ++ i) way[i][i] = 1;
  if(!ok) {
	puts("Yes");
	for(int i = 1; i <= n; ++ i) putchar('b');
	return 0;
  }
  
  s[ok] = 'a';
  
  int now = 0;
  for(int i = 1; i <= n; ++ i) {
	if(!way[ok][i]) {
	  s[i] = 'c';
	  now = i;
	}
  }
  for(int i = 1; i <= n; ++ i) {
	if(!way[now][i]) s[i] = 'a';
  }
  for(int i = 1; i <= n; ++ i) if(s[i] != 'a' && s[i] != 'c') s[i] = 'b';
  ok = 1;
  for(int i = 1; i <= n; ++ i) {
	for(int j = 1; j <= n; ++ j) {
	  if(way[i][j] != (abs(s[i] - s[j]) <= 1)) ok = 0;
	}
  }
  //for(int i = 1; i <= n; ++ i) putchar(s[i]);
  if(!ok) puts("No");
  else puts("Yes");
  if(ok) for(int i = 1; i <= n; ++ i) putchar(s[i]);
}