#include<cstdio>

using namespace std;

char S[512][512];
int pat[10][512][512];
int black[10][512][512];

int main()
{
  int n, m;

  while(~scanf("%d%d", &n, &m)) {
    for(int i=0; i<n; ++i) {
      scanf("%s", S[i]);
    }

    static int dx[] = {0, 1, 0, 1};
    static int dy[] = {0, 1, 1, 0};
    for(int i=0; i<n-1; ++i) {
      for(int j=0; j<m-1; ++j) {
        pat[0][i][j] = 0;
        for(int k=0; k<4; ++k) {
          if(S[i+dx[k]][j+dy[k]] == '*') {
            pat[0][i][j] |= 1<<k;
          }
        }
        if(pat[0][i][j] == 15) {
          black[0][i][j] = 1;
        }
      }
    }

    int sol = 0;
    for(int s=4, p=1; s<=n && s<=m; ++p, s<<=1) {
      int ms = s>>1;
      for(int i=0; i+s<=n; ++i) {
        for(int j=0; j+s<=m; ++j) {
          pat[p][i][j] = -1;
          black[p][i][j] = 1;

          for(int k=0; k<4; ++k) {
            if(!black[p-1][i+ms*dx[k]][j+ms*dy[k]]) {
              black[p][i][j] = 0;
            }
          }
          
          for(int k=0; k<16; ++k) {
            bool ok = true;
            
            for(int x=0; x<4; ++x) {
              int ii = i+ms*dx[x], jj = j+ms*dy[x];

              if(k & (1<<x)) {
                ok &= black[p-1][ii][jj] == 1;
              } else {
                ok &= pat[p-1][ii][jj] == k;
              }
            }

            if(ok) {
              pat[p][i][j] = k;
              sol++;
              break;
            }
          }
        }
      }
    }

    printf("%d\n", sol);
  }

  return 0;
}