#include<cstdio>
#include<cstring>

char S[100050], P[100050];

int main()
{
  int occ[26] = {0};
  scanf("%s%s", S, P);
  int n = strlen(S), m = strlen(P);
  int sol = 0, err = 0;
  if(n < m) { puts("0"); return 0; }
  for(int i=0; i<m; ++i) occ[P[i]-'a']++;
  for(int i=0; i<m; ++i) {
    if(S[i]=='?') continue;
    occ[S[i]-'a']--;
    if(occ[S[i]-'a']==-1) err++;
  }
  for(int i=0; i+m<=n; ++i) {
    if(err == 0) sol++;
    if(i+m == n) break;
    if(S[i]!='?') {
      occ[S[i]-'a']++;
      if(occ[S[i]-'a']==0) err--;
    }
    if(S[i+m]!='?') {
      occ[S[i+m]-'a']--;
      if(occ[S[i+m]-'a']==-1) err++;
    }
  }
  printf("%d\n", sol);
  return 0;
}