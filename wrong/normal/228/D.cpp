#include<cstdio>
#include<cstring>

using namespace std;

typedef long long Int;

inline Int in()
{
  Int res;
  scanf("%I64d", &res);
  return res;
}

Int a[100050];

struct BIT {
  Int n;
  Int s[100050];
  void update(int x, Int v) {
    while(x <= n) {
      s[x] += v;
      x += x & -x;
    }
  }
  Int sum(int x) {
    Int r = 0;
    while(x > 0) {
      r += s[x];
      x -= x & -x;
    }
    return r;
  }
  Int sum(int l, int r) {
    if(l>r) return 0;
    return sum(r) - sum(l-1);
  }
} S[11][10];

int main()
{
  int n = in();

  {
    for(int j=1; j<=10; ++j) {
      for(int k=0; k<j; ++k) {
        S[j][k].n = n;
      }
    }
    for(int i=1; i<=n; ++i) {
      a[i] = in();
      for(int j=1; j<=10; ++j) {
        S[j][i%j].update(i, a[i]);
      }
    }

    int m = in();
    for(int i=0; i<m; ++i) {
      int t = in();
      if(t == 1) {
        Int p = in();
        Int v = in();

        Int dif = v - a[p];
        a[p] = v;
        for(int j=1; j<=10; ++j) {
          S[j][p%j].update(p, dif);
        }
      } else {
        Int l = in();
        Int r = in();
        Int z = in();
        z = 2*(z-1);

        Int res = 0, s = 1, ds = 1;
        for(int i=l; i<=r && i<l+z; ++i) {
          res += s * S[z][i%z].sum(i, r);
          s += ds;
          if(s == (z+2)/2) {
            ds = -1;
          }
        }

        printf("%I64d\n", res);
      }
    }
  }

  return 0;
}