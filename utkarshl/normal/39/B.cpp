#include"stdio.h"
#include"set"
using namespace std;
int main()
{
  int N;
  scanf("%d",&N);
  int A[N];
  int k=1;
  for(int x=1;x<=N;x++)
  {
    int r;
    scanf("%d",&r);
    if(r==k){
      A[k-1]=x+2000;
      k++;
    }
  }
  printf("%d\n",--k);
  for(int t=0;t<k-1;t++)
    printf("%d ",A[t]);
  if(k>0)printf("%d\n",A[k-1]);
}