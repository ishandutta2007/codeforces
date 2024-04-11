#include<cstdio>

int main()
{
  int n;
  scanf("%d", &n);
  while(n--) {
    char s[32];
    scanf("%s", s);
    int typ = 0;
    for(int i=0; s[i]; ++i)
      if('0'<=s[i]&&s[i]<='9'&&typ==0) typ=1;
      else if(s[i]=='C'&&typ==1) typ=2;
    if(typ==2) {
      int r=0, c=0, k=1;
      while('0'<=s[k]&&s[k]<='9') r=r*10+s[k++]-'0'; k++;
      while('0'<=s[k]&&s[k]<='9') c=c*10+s[k++]-'0';
      for(c--, k=0; c>=0; c/=26, c--) s[k++]=c%26+'A'; s[k]='\0';
      while(k-1>=0) putchar(s[--k]);
      printf("%d\n", r);
    } else {
      int r=0, c=0, k=0;
      while('A'<=s[k]&&s[k]<='Z') c=c*26+s[k++]-'A'+1;
      while('0'<=s[k]&&s[k]<='9') r=r*10+s[k++]-'0';
      printf("R%dC%d\n", r, c);
    }
  }
  return 0;
}