#include<cstdio>
#include<algorithm>

using namespace std;

int reach[101][52][2][256];

int main()
{
  int i, n;
  char p[128];
  scanf("%s%d", p+1, &n);

  reach[0][0][0][128] = 1;
  for(i=1; p[i]; ++i) {
    for(int j=0; j<=n; ++j) {
      for(int k=1; k<255; ++k) {
	if(reach[i-1][j][0][k]) {
	  if(p[i]=='F') reach[i][j][0][k+1]=1;
	  else reach[i][j][1][k]=1;
	  if(p[i]=='F') reach[i][j+1][1][k]=1;
	  else reach[i][j+1][0][k+1]=1;
	}
	if(reach[i-1][j][1][k]) {
	  if(p[i]=='F') reach[i][j][1][k-1]=1;
	  else reach[i][j][0][k]=1;
	  if(p[i]=='F') reach[i][j+1][0][k]=1;
	  else reach[i][j+1][1][k-1]=1;
	}
      }
    }
    for(int j=0; j<=n; ++j) {
      for(int k=1; k<255; ++k) {
	if(reach[i][j][0][k])
	  for(int x=j+2; x<=n; x+=2) reach[i][x][0][k]=1;
	if(reach[i][j][1][k])
	  for(int x=j+2; x<=n; x+=2) reach[i][x][1][k]=1;
      }
    }
  }
  int sol = 0;
  for(int k=1; k<255; ++k)
    if(reach[i-1][n][0][k] || reach[i-1][n][1][k])
      sol = max(sol, abs(k-128));
  printf("%d\n", sol);
  return 0;
}