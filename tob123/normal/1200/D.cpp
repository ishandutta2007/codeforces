#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 2020;

int N, K;
int Bh[n][n], Bv[n][n], R[n][n], C[n][n];

int sumh(int i, int j){
  return Bh[i][N] - Bh[i][min(j+K-1, N)] + Bh[i][j-1];
}

int sumv(int i, int j){
  return Bv[N][j] - Bv[min(i+K-1, N)][j] + Bv[i-1][j];
}

int main(){
  cin >> N >> K;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      char x;
      cin >> x;
      Bh[i][j] = x == 'B';
      Bv[i][j] = Bh[i][j];
    }
  }
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      Bh[i][j] += Bh[i][j-1];
      Bv[i][j] += Bv[i-1][j];
    }
  }
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      if(Bh[i][N] != 0 && sumh(i, j) == 0){
        R[i+1][j] += -1;
        R[max(0, i-K+1)][j] += 1;
      }
      if(Bv[N][j] != 0 && sumv(i, j) == 0){
        C[i][j+1] += -1;
        C[i][max(1, j-K+1)] += 1;
      }
    }
  }

  int best = 0;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N; j++){
      R[i][j] += R[i-1][j];
      C[i][j] += C[i][j-1];
      best = max(best, R[i][j] + C[i][j]);
    }
  }
  for(int i=1; i<=N; i++){
    if(Bh[i][N] == 0)
      best++;
    if(Bv[N][i] == 0)
      best++;
  }
  cout << best << endl;

  return 0;
}