//correct answer by bob?
#include"stdio.h"
#include"algorithm"
using namespace std;
int main()
{
  char A[11],B[11],ch;
  int i=0;
  for(; (ch=getchar()) != EOF && ch != '\n'; i++)
    A[i] = ch;
  A[i]=0;
//   printf("\n before sorting:%s,%d,%d",A,A[i],i);
    sort(A,A+i);
//     printf("\n after sorting:%s,%d,%d",A,A[i],i);
  for(i=0;A[i]=='0';i++);
  if(A[i]==0)i--;
  swap(A[0],A[i]);
//   rotate(A,A+i,A+i+1);
//   printf("\n after rotating:%s",A);
  for(i=0; (ch=getchar()) != EOF && ch != '\n'; i++)
    B[i]=ch;
  B[i]=0;
  int x;
//   printf("%s\n",B);
  for(x=0;A[x]!=0 && B[x]==A[x];x++);
  if(A[x]==B[x])printf("OK\n");
  else
    printf("WRONG_ANSWER\n");
  
}