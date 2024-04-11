#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
  char n[12], m[12];
  scanf("%s%s", n, m);
  if(n[0] == '0') {
    puts(strcmp(m, "0") == 0 ? "OK" : "WRONG_ANSWER");
    return 0;
  }
  if(m[0] == '0') {
    puts("WRONG_ANSWER");
    return 0;
  }
  sort(n, n+strlen(n));
  int zero = 0;
  for(int i=0; i<strlen(n); ++i)
    if(n[i] == '0') zero++;
  char sol[12];
  int k=0;
  for(int i=0; i<strlen(n); ++i) {
    if(k != 0) {
      sol[k++] = n[i];
    } else if(k==0 && n[i] != '0') {
      sol[k++] = n[i];
      for(int j=0; j<zero; ++j)
	sol[k++] = '0';
    }
  }
  sol[k] = '\0';
  puts(strcmp(m, sol) == 0 ? "OK" : "WRONG_ANSWER");
  return 0;
}