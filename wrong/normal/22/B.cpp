#include<cstdio>

using namespace std;

int main()
{
  int n, m, s[32][32]={{0}};
  char F[32][32];
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; ++i)
    scanf("%s", &F[i][1]);
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
      s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+F[i][j]-'0';
  int sol=0;
  for(int i=1; i<=n; ++i)
    for(int j=1; j<=m; ++j)
      for(int k=i; k<=n; ++k)
	for(int l=j; l<=m; ++l)
	  if(s[k][l]-s[i-1][l]-s[k][j-1]+s[i-1][j-1] == 0)
	    if(sol < 2*(k-i+1)+2*(l-j+1))
	      sol = 2*(k-i+1)+2*(l-j+1);
  printf("%d\n", sol);
  return 0;
}