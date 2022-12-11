#include <bits/stdc++.h>
using namespace std;

struct point
{
  int x,y,idx;
  bool operator<(const point &rhs) const
  {
    if (x!=rhs.x) return x<rhs.x;
    return y<rhs.y;
  }
};
point dat[100005];

bool oneline(point p1, point p2, point p3)
{
  p2.x -= p1.x; p2.y -= p1.y;
  p3.x -= p1.x; p3.y -= p1.y;
  return (long long)p2.x*p3.y - (long long)p3.x*p2.y;
}

int main()
{
  int n;
  scanf("%d",&n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d",&dat[i].x,&dat[i].y);
    dat[i].idx = i+1;
  }
  sort(dat,dat+n);

  printf("%d %d ", dat[0].idx, dat[1].idx);
  if (dat[0].x != dat[1].x)
  {
    int i;
    for (i = 2; !oneline(dat[0], dat[1], dat[i]); i++);
    printf("%d", dat[i].idx);
  }
  else
  {
    int i;
    for (i = 2; dat[1].x == dat[i].x; i++);
    printf("%d", dat[i].idx);
  }
}