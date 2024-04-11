#include<cstdio>

char S[1<<20];

int main()
{
  int i, cnt = 0, rm = 0;
  scanf("%s", S);
  for(i=0; S[i]; ++i) {
    if(S[i]=='(') cnt++;
    else if(cnt==0) rm++;
    else cnt--;
  }
  printf("%d\n", i-rm-cnt);
  return 0;
}