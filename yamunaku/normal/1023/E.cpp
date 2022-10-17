#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  cin >> n;
  int nx=1,ny=1;
  vector<int> keiro(2*(n-1),-1);
  string re;
  while(nx+ny<n+1){
    printf("? %d %d %d %d\n",ny,nx+1,n,n);
    cin >> re;
    if(re=="YES") keiro[nx+ny-2]=1,nx++;
    else keiro[nx+ny-2]=0,ny++;
  }
  nx=n,ny=n;
  while(nx+ny>n+1){
    printf("? %d %d %d %d\n",1,1,ny-1,nx);
    cin >> re;
    if(re=="YES") keiro[nx+ny-3]=0,ny--;
    else keiro[nx+ny-3]=1,nx--;
  }
  char c[2]={'D','R'};
  printf("! ");
  for(int i=0;i<2*(n-1);i++){
    printf("%c",c[keiro[i]]);
  }
  printf("\n");
  return 0;
}