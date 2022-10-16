#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n;
char s[maxn];

inline void solve(){
  scanf("%s", s);
  n = strlen(s);
  int cnt0 = 0, l = -1, r = -1;
  for(int i = 0; i < n; ++i){
    cnt0 += (s[i] == '0');
    if(!~l && s[i] == '0')
      l = i;
    if(s[i] == '0')
      r = i;
  }
  if(!cnt0)
    puts("0");
  else if(cnt0 == n)
    puts("1");
  else if(cnt0 == r - l + 1)
    puts("1");
  else
    puts("2");
  return;
}

int main(){
  //freopen("B.in", "r", stdin);
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}