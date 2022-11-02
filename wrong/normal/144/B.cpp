#include<cstdio>
#include<algorithm>

using namespace std;

int n;
int x[1024], y[1024], r[1024];

int check(int X, int Y)
{
  for(int i=0; i<n; ++i)
    if((X-x[i])*(X-x[i])+(Y-y[i])*(Y-y[i])<=r[i]*r[i])
      return 0;
  return 1;
}

int main()
{
  int xa, ya, xb, yb;
  scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
  if(xa > xb) swap(xa, xb);
  if(ya > yb) swap(ya, yb);
  int S = 0;
  scanf("%d", &n);
  for(int i=0; i<n; ++i) scanf("%d%d%d", &x[i], &y[i], &r[i]);
  for(int x=xa; x<=xb; ++x) S+=check(x, ya)+check(x, yb);
  for(int y=ya+1; y<yb; ++y) S+=check(xa, y)+check(xb, y);
  printf("%d\n", S);
  return 0;
}