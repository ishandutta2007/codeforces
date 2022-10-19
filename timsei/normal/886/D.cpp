#include <bits/stdc++.h>
using namespace std;

const int N = 111111;

int to[27], n, m, x, y, now, du[27], Ba[27];

char s[N];

bool way[27][27];
bool vis[27];

void print(char c) {
  putchar(c + now);
  vis[c] = 1;
  if(to[c])
  print(to[c]);
}

int main(void) {
  cin >> n;
  now = 'a' - 1;
  for(int i = 1; i <= n; ++ i) {
    scanf("%s", s + 1);
    int l = strlen(s + 1);
    vis[s[l] - now] = 1;
    for(int j = 1;j < l;++ j) {
      vis[s[j] - now] = 1;
      if(to[s[j] - now] != s[j + 1] - now) {
        if(!to[s[j] - now]) {
          to[s[j] - now] = s[j + 1] - now;
          if(Ba[s[j + 1] - now]) {
            puts("NO");
            return 0;
          }
          Ba[s[j + 1] - now] = s[j] - now;
        }
        else {
          puts("NO");
          return 0;
        }
      } 
    }
  }
  for(int i = 1; i <= 26; ++ i) way[i][to[i]] = 1, ++ du[to[i]];
  for(int k = 1; k <= 26; ++ k) {
    for(int i = 1; i <= 26; ++ i) {
      for(int j = 1; j <= 26; ++ j) {
        if(way[i][k] && way[k][j]) way[i][j] = 1;
      }
    }
  }
  for(int i = 1; i <= 26; ++ i) {
    if(way[i][i]) {
      puts("NO");
      return 0;
    }
  }
  for(int i = 1; i <= 26; ++ i) {
    if(vis[i] && !du[i]) print(i);
  }
  puts("");
}