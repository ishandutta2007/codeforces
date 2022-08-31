#include"stdio.h"
#include"set"
#include"vector"
#include"map"
using namespace std;
int main()
{
  int n;
  scanf("%d",&n);
  char A[20000],*B=A;
  A[0]=1;
  while(A[0]!='\n')scanf("%c",&A[0]);
  gets(A);
  int num=0;
  while(*B!=0)
  {
    if(*B==' '){B++;continue;}
    int len=0;
    int last=-1;
    while(len<n&&B[len])
    {
      if(B[len]=='.'||B[len]=='?'||B[len]=='!')
	last=len+1;
      len++;
    }
    if(last<0){printf("Impossible");return 0;}
//     printf("%d %d %s\n",last,B[last],B);
    num++;
    B=B+last;
  }
  printf("%d",num);
}