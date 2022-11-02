#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m, x1, y1, x2, y2;
    scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2);
    int x1l, x1r, y1l, y1r, x2l, x2r, y2l, y2r;
    if(x1 <= x2) {
      x1l = 1; x2r = n;
      x1r = n-(x2-x1);
      x2l = 1+(x2-x1);
    } else {
      x2l = 1; x1r = n;
      x2r = n-(x1-x2);
      x1l = 1+(x1-x2);
    }
    if(y1 <= y2) {
      y1l = 1; y2r = m;
      y1r = m-(y2-y1);
      y2l = 1+(y2-y1);
    } else {
      y2l = 1; y1r = m;
      y2r = m-(y1-y2);
      y1l = 1+(y1-y2);
    }

    long long sol = (long long)n * m;
    sol -= (long long)(y2r-y2l+1)*(x2r-x2l+1) + (long long)(x1r-x1l+1)*(y1r-y1l+1);
    if(x1l <= x2r && x2l <= x1r && y1l <= y2r && y2l <= y1r) {
      int l = max(x1l, x2l);
      int r = min(x1r, x2r);
      int u = max(y1l, y2l);
      int d = min(y1r, y2r);
      sol += (long long)(d-u+1)*(r-l+1);
    }
    cout << sol << endl;
  }
  return 0;
}