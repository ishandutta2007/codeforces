#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>

using namespace std;

int n, m;
int a[100][100];
int r[100], c[100], rf[100], cf[100];

int solve()
{
  memset(r, 0, sizeof(r));
  memset(c, 0, sizeof(c));
  memset(rf, 0, sizeof(rf));
  memset(cf, 0, sizeof(cf));

  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      r[i] += a[i][j];
      c[j] += a[i][j];
    }
  }

  int ord[200];
  for(int i=0; i<n+m; ++i) {
    ord[i] = i;
  }
  
  int loops = 0;
  while(true) {
    #if 0
    if(loops >= 500000) {
      for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
          printf("%5d", a[i][j]);
        }
        puts("");
      }
      return 0;
    }
    #endif
    
    bool ok = true;
    for(int i=0; i<n; ++i) {
      ok &= r[i] >= 0;
    }
    for(int i=0; i<m; ++i) {
      ok &= c[i] >= 0;
    }
    if(ok) break;

    random_shuffle(ord, ord+n+m);
    for(int i=0; i<n+m; ++i) {
      if(ord[i] < n) {
        int row = ord[i];
        if(r[row] < 0) {
          rf[row] = 1 - rf[row];
          for(int j=0; j<m; ++j) {
            int dif = -2 * a[row][j];
            a[row][j] *= -1;
            r[row] += dif;
            c[j] += dif;
          }
        }
      } else {
        int col = ord[i] - n;
        if(c[col] < 0) {
          cf[col] = 1 - cf[col];
          for(int j=0; j<n; ++j) {
            int dif = -2 * a[j][col];
            a[j][col] *= -1;
            r[j] += dif;
            c[col] += dif;
          }
        }
      }
    }

    loops++;
  }

  return 1;
}

int main()
{
#if 1
  cin >> n >> m;

  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      cin >> a[i][j];
    }
  }
#else
  srand(time(NULL));
  while(true) {
  
  n = rand() % 100 + 1;
  m = rand() % 100 + 1;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<m; ++j) {
      a[i][j] = rand() % 201 - 100;
    }
  }

  cerr << n << " " << m << endl;
  if(solve()==0)return 0;
  }
#endif
  solve();
  
  int rc = 0, cc = 0;
  for(int i=0; i<n; ++i) {
    rc += rf[i];
  }
  for(int i=0; i<m; ++i) {
    cc += cf[i];
  }

  cout << rc;
  for(int i=0; i<n; ++i) {
    if(rf[i]) {
      cout << " " << i+1;
    }
  }
  cout << endl;

  cout << cc;
  for(int i=0; i<m; ++i) {
    if(cf[i]) {
      cout << " " << i+1;
    }
  }
  cout << endl;

  return 0;
}