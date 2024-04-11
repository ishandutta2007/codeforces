#include<cstdio>

bool ciel(int& x, int& y)
{
  if(y<2) return false;
  if(x>=2) { x-=2; y-=2; return true; }
  if(x==1 && y<12) return false;
  if(x==1) { x-=1; y-=12; return true; }
  if(y<22) return false;
  y-=22;
  return true;
}

bool hanako(int& x, int& y)
{
  if(y>=22) { y-=22; return true; }
  if(y>=12 && x>=1) { x-=1; y-=12; return true; }
  if(y>=2 && x>=2) { x-=2; y-=2; return true; }
  return false;
}

int main()
{
  int x, y;
  scanf("%d%d", &x, &y);
  while(true) {
    if(!ciel(x, y)) { puts("Hanako"); break; }
    if(!hanako(x, y)) { puts("Ciel"); break; }
  }
  return 0;
}