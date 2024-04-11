#include<cstdio>

typedef long long ll;

int start[2048], end[2048];
char S[2048];

int main()
{
  scanf("%s", S);

  for(int i=0; S[i]; ++i) {
    int j=i, k=i;
    while(true) {
      start[j]++; end[k]++;
      --j; ++k;
      if(j<0 || S[k]=='\0' || S[j]!=S[k]) break;
    }
  }

  for(int i=1; S[i]; ++i) {
    int j=i-1, k=i;
    while(true) {
      if(S[j]!=S[k]) break;
      start[j]++; end[k]++;
      --j; ++k;
      if(j<0 || S[k]=='\0') break;
    }
  }

  for(int i=1; S[i]; ++i)
    end[i] += end[i-1];

  ll sol = 0;
  for(int i=1; S[i]; ++i)
    sol += (ll)end[i-1] * start[i];
  printf("%I64d\n", sol);

  return 0;
}