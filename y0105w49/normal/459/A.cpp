#include <stdio.h>

using namespace std;

int abs(int a) { return a<0?-a:a; }

int main() {

  int x1,y1,x2,y2;
  scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

  if (x1==x2)
    printf("%d %d %d %d\n", x1+abs(y2-y1),y1,x1+abs(y2-y1),y2);
  else if (y1==y2)
    printf("%d %d %d %d\n", x1,y1+abs(x2-x1),x2,y1+abs(x2-x1));
  else if (abs(x2-x1)==abs(y2-y1))
    printf("%d %d %d %d\n",x1,y2,x2,y1);
  else
    printf("-1\n");

  return 0;

}