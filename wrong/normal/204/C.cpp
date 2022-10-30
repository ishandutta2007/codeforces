#include<cstdio>
#include<algorithm>

using namespace std;

char S[200050], T[200050];

typedef long long Int;

int main()
{
  int n;
  
  scanf("%d%s%s", &n, S, T);
  
  Int div = 0;
  for(int i=1; i<=n; ++i)
    div += (Int)(n-i+1)*(n-i+1);
  
  long double res = 0;
  for(int i=0; i<26; ++i) {
    Int left = 0, right = 0;
    for(int j=n-1; j>=0; --j)
      if(T[j] == i+'A')
        right += n-j;
    
    for(int j=0; j<n; ++j) {
      if(S[j] == i+'A') {
        res += right * (j+1);
        res += left * (n-j);
      }
      if(T[j] == i+'A') {
        right -= n-j;
        left += j+1;
      }
    }
  }
  
  printf("%.12f\n", (double)(res/div));
  
  return 0;
}