//CF 6D
/*
archerdp
      10 * 15 * 15 * 15
 
      
     
1  n  f[2][h1][h2][h3] = 0 visfalse 
*/

#include<stdio.h>

inline int max(const int a, const int b){return a > b ? a : b;} 

int n, a, b, h[16], fa[11][17][17][17], f[11][17][17][17], t1, t2, t3, t4, t5, cnt;

int main() {
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &h[i]);
    h[i]++;
  }
  fa[2][h[1]][h[2]][h[3]] = -1;
  f[2][h[1]][h[2]][h[3]] = 0;
  for (int i = 2; i < n; i++) {
    for (int j = h[i - 1]; j >= 0; j--) {
      for (int k = h[i]; k >= 0; k--) {
        for (int l = h[i + 1]; l >= 0; l--) {
          if (!fa[i][j][k][l]) continue;
          
//          printf("%d %d %d %d : %d\n", i, j, k, l, f[i][j][k][l]);
          
          //cast a fire ball at i -> j - b k - a l - b
          if (!fa[i][max(0, j - b)][max(0, k - a)][max(0, l - b)] ||
              f[i][max(0, j - b)][max(0, k - a)][max(0, l - b)] > f[i][j][k][l] + 1) {
            fa[i][max(0, j - b)][max(0, k - a)][max(0, l - b)] = j * 289 + k * 17 + l;
            f[i][max(0, j - b)][max(0, k - a)][max(0, l - b)] = f[i][j][k][l] + 1;
          }
          //if the i - 1 th archer is dead
          if (j == 0 && i < n - 1) {
            if (!fa[i + 1][k][l][h[i + 2]] ||
                f[i + 1][k][l][h[i + 2]] > f[i][j][k][l]) {
              fa[i + 1][k][l][h[i + 2]] = -32767;
              f[i + 1][k][l][h[i + 2]] = f[i][j][k][l]; 
            }
          }
        }
      }
    } 
  }
  
  printf("%d\n", f[n - 1][0][0][0]); 
  
  cnt = 0;
  t1 = n - 1; t2 = t3 = t4 = 0;
  while (cnt < f[n - 1][0][0][0]) {
    if (fa[t1][t2][t3][t4] == -32767) {
      t1--; t4 = t3; t3 = t2; t2 = 0;
    } else {
      cnt++;
      if (cnt != 1) printf(" ");
      printf("%d", t1);
      t5 = fa[t1][t2][t3][t4];
      t2 = t5 / 289;
      t3 = t5 / 17 % 17;
      t4 = t5 % 17;
    } 
  }
  printf("\n");
  return 0;
}