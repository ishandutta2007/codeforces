#include <stdio.h>
#include <math.h>
#include <algorithm>

#define BASE 1000000

using namespace std;

int next[BASE][10],cost[BASE][10];
long long n,res=0;

int maxc(int x){
  int res=0;
  while (x>0){
    res=max(res,x%10);
    x/=10;
  }
  return res;
}


int main(){
  scanf("%I64d",&n);
  for (int i=0;i<BASE;i++)
    for (int j=1;j<=9;j++){
      int m=max(maxc(i),j);
      if (i-m<0){
	next[i][j]=1;
	cost[i][j]=m;
      }else{
	next[i][j]=next[i-m][j]+1;
	cost[i][j]=cost[i-m][j]+m;
      }
    }
  while (n>=BASE){
    int m=maxc(n/BASE);
    res+=next[n%BASE][m];
    n-=cost[n%BASE][m];
  }
  while (n>0){
    int m=maxc(n);
    res++;
    n-=m;
  }
  printf("%I64d\n",res);
}