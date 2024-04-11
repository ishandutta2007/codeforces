#include<cstdio>

int S[100], R[100], H[100], C[100];

int main()
{
  int n;
  scanf("%d", &n);

  for(int i=0; i<n; ++i)
    scanf("%d%d%d%d", &S[i], &R[i], &H[i], &C[i]);

  int f = -1, c = 1024;
  for(int i=0; i<n; ++i) {
    if(c > C[i]) {
      bool ok = true;
      for(int j=0; j<n; ++j)
	if(S[i]<S[j] && R[i]<R[j] && H[i]<H[j])
	  ok = false;
      if(ok) {
	f = i;
	c = C[i];
      }
    }
  }

  printf("%d\n", f+1);
  return 0;
}