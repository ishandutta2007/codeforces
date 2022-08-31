#include"stdio.h"
#include"algorithm"
using namespace std;
int main()
{
  int a,b,c,d,n;
  scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
  bool flag=b<=d;
  if(b>d)
  {
    swap(a,c);
    swap(b,d);
  }
  char s[d][a+c];
  for(int x=0;x<d;x++)
  {
    for(int y=0;y<a+c;y++)
    {
      if(x>=b && y<a)
	s[x][y]='.';
      else s[x][y]='?';
    }
  }
  int xpos=0,ypos=0,drn=1;
  if(a&1==1)
  {
    xpos=b-1;
    drn=-1;}
  for(int x=0;x<n;x++)
  {
    int ct;
    scanf("%d",&ct);
    while(ct--)
    {
      while(s[xpos][ypos]=='.')
      {
	xpos+=drn;
	if(xpos==-1||xpos>=d){
	  ypos++;drn*=-1;
	  xpos+=drn;
	}
      }
      s[xpos][ypos]=(char)('a'+x);
      xpos+=drn;
      if(xpos==-1||xpos>=d){
	ypos++;drn*=-1;
	xpos+=drn;
      }
    }
  }
  printf("YES\n");
  for(int x=0;x<d;x++)
  {
    for(int y=flag?0:a+c-1;1;y+=flag?1:-1)
    {
      printf("%c",s[x][y]);
      if(flag)
      {
	if(y==a+c-1)break;
      }
      else if(y==0)break;
    }
    printf("\n");
  }
}