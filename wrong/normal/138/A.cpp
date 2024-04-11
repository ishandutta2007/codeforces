#include<cstdio>
#include<cstring>

int V[256], k;

int match(char *a, char *b)
{
  int an = strlen(a), bn = strlen(b);
  int x = an-1, y = bn-1;
  for(int t=k; x>=0; --x) {
    if(V[a[x]]) {
      t--;
      if(t == 0) break;
    }
  }
  for(int t=k; y>=0; --y) {
    if(V[b[y]]) {
      t--;
      if(t == 0) break;
    }
  }
  if(x < 0 || y < 0) return 0;
  if(an-x != bn-y) return 0;
  for(int i=0; x+i<an; ++i)
    if(a[i+x]!=b[i+y]) return 0;
  return 1;
}

char T[4][10050];

int main()
{
  int n, s = 15;
  scanf("%d%d", &n, &k);

  V['a'] = V['e'] = V['i'] = V['o'] = V['u'] = 1;

  for(int i=0; i<n; ++i) {
    int t = 0;
    scanf("%s%s%s%s", T[0], T[1], T[2], T[3]);
    if(match(T[0], T[1]) && match(T[2], T[3])) t |= 1;
    if(match(T[0], T[2]) && match(T[1], T[3])) t |= 2;
    if(match(T[0], T[3]) && match(T[1], T[2])) t |= 4;
    if(match(T[0], T[1]) && match(T[1], T[2]) && match(T[2], T[3])) t |= 8;
    s &= t;
  }
  if(s & 8) puts("aaaa");
  else if(s & 1) puts("aabb");
  else if(s & 2) puts("abab");
  else if(s & 4) puts("abba");
  else puts("NO");
  return 0;
}