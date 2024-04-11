#include <bits/stdc++.h>

using namespace std;

int N, Q, C;
int dp[105][105][15];
int e[105][105][15];

void cl() {
  for (int i=0;i<105;i++) {
    for(int j=0;j<105;j++) {
      for(int k=0;k<15;k++) {
        dp[i][j][k]=0;
        e[i][j][k]=0;
      }
    }
  }
}
int main() {
  scanf("%i%i%i", &N, &Q, &C);
  cl();
  for (int i=0;i<N;i++) {
    int X, Y, S;
    scanf("%i%i%i", &X, &Y, &S);
    e[X][Y][S]++;
  }
  for (int i=1;i<102;i++) {
    for (int j=1;j<102;j++) {
      for (int k=0;k<12;k++) {
        dp[i][j][k]+=e[i][j][k];
      }
    }
  }
  for (int i=1;i<102;i++) {
    for (int j=1;j<102;j++) {
      for (int k=0;k<12;k++) {
        dp[i][j][k] += dp[i][j-1][k]+dp[i-1][j][k]-dp[i-1][j-1][k];
      }
    }
  }
  for (int QQ=0;QQ<Q;QQ++) {
    int T, X1, Y1, X2, Y2;
    scanf("%i%i%i%i%i", &T, &X1, &Y1, &X2, &Y2);
    int ANS=0;
    for(int k=0;k<=10;k++) {
      ANS+=((k+T)%(C+1))*(dp[X2][Y2][k]-dp[X2][Y1-1][k]-dp[X1-1][Y2][k]+dp[X1-1][Y1-1][k]);
    }
    printf("%i \n", ANS);
  }
}