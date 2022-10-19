#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

vector <int> Vec;

char s[N];
int n;

int fir, nxt[N], pre[N];

void make(int x) {
  pre[nxt[x]] = x;
  nxt[pre[x]] = x;
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  if(n == 1) {
    puts("1");
    return 0;
  }
  fir = 1;
  if(s[1] == 'l')
    pre[1] = 2, nxt[2] = 1, nxt[0] = 2;
  else pre[2] = 1, nxt[1] = 2, nxt[0] = 1;
  bool last = (s[1] == 'l');
  for(int i = 2; i < n; ++ i) {
    if(last) {
      //[i -> i - 1]
      last = (s[i] == 'l');
      if(last)
	pre[i + 1] = pre[i], nxt[i + 1] = i, make(i + 1);
      else
	nxt[i + 1] = i - 1, pre[i + 1] = i, make(i + 1);
    }
    else {
      last = (s[i] == 'l');
      if(last) nxt[i + 1] = i, pre[i + 1] = i - 1, make(i + 1);
      else nxt[i + 1] = nxt[i], pre[i + 1] = i, make(i + 1);
    }
  }
  for(int i = nxt[0]; i; i = nxt[i]) {
    if(i) printf("%d\n", i);
  }
}