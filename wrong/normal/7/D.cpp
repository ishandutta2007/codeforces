#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int rad[10000050];
int deg[10000050];
char S[5000050];

void longest_palindrome(char *s, int n)
{
  int i, j, k;
  for(i = j = 0; i < 2*n; i += k, j = max(j-k, 0)) {
    while(i-j >= 0 && i+j+1 < 2*n && s[(i-j)/2] == s[(i+j+1)/2]) ++j;
    rad[i] = j;
    for(k = 1; i-k >= 0 && rad[i]-k >= 0 && rad[i-k] != rad[i]-k; ++k)
      rad[i+k] = min(rad[i-k], rad[i]-k);
  }
}

int main()
{
  scanf("%s", S);
  longest_palindrome(S, strlen(S));
  int sol = 0, len = strlen(S)*2;
  for(int i=0; i<len; ++i) {
    if(rad[i] == i+1) {
      deg[i] = deg[i-(rad[i]+1)/2];
      deg[i] += 1;
      sol += deg[i];
    }
  }
  printf("%d\n", sol);
  return 0;
}