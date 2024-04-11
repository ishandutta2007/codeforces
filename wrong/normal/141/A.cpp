#include<cstdio>

int main()
{
  int A[256] = {0};
  char S[256];
  scanf("%s", S);
  for(int i=0; S[i]; ++i) A[(int)S[i]]++;
  scanf("%s", S);
  for(int i=0; S[i]; ++i) A[(int)S[i]]++;
  scanf("%s", S);
  for(int i=0; S[i]; ++i) A[(int)S[i]]--;
  int ok = 1;
  for(int i=0; i<256; ++i)
    if(A[i]!=0) ok=0;
  puts(ok ? "YES" : "NO");
  return 0;
}