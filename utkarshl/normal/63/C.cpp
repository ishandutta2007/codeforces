#include"stdio.h"
using namespace std;
bool isValid(int i)
{
  int ct[10];
  for(int x=0;x<10;x++)ct[x]=0;
  ct[i%10]=1;
  i/=10;
  ct[i%10]=1;
  i/=10;
  ct[i%10]=1;
  i/=10;
  ct[i%10]=1;
  i/=10;
  int sum=0;
  for(int x=0;x<10;x++)sum+=ct[x];
  return sum==4;
}
bool check(char s[10],int x,int y,int n)
{
  y+=x;
  if(s[0]-'0'==n/1000)x--;
  if(s[1]-'0'==(n/100)%10)x--;
  if(s[2]-'0'==(n/10)%10)x--;
  if(s[3]-'0'==n%10)x--;
  if(x!=0)return 0;
  int ct[10];
  for(int z=0;z<10;z++)
  {
    ct[z]=0;
  }
  int i=n;
  ct[i%10]=1;
  i/=10;
  ct[i%10]=1;
  i/=10;
  ct[i%10]=1;
  i/=10;
  ct[i%10]=1;
  for(int z=0;z<4;z++)
    if(ct[s[z]-'0'])y--;
  return y==0;
}
int main()
{
  int N;
  scanf("%d",&N);
  bool valid[10000];
  for(int x=0;x<10000;x++)
    valid[x]=isValid(x);
  for(int x=0;x<N;x++)
  {
    char inp[10];
    int x,y;
    scanf("%s%d%d",inp,&x,&y);
    for(int n=0;n<10000;n++)
      if(valid[n] && check(inp,x,y,n))valid[n]=1;
      else valid[n]=0;
  }
  int n=0;
  for(int x=0;x<10000;x++)
    n+=valid[x]?1:0;
  if(n==0)printf("Incorrect data");
  else if(n>1)printf("Need more data");
  else
  {
    for(int x=0;x<10000;x++)
      if(valid[x])
      {
	printf("%d%d%d%d",(x/1000),(x/100)%10,(x/10)%10,x%10);
      }
  }
}