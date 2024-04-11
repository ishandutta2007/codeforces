#include <cstdio>

int A[110], B[110];
int DP[10010][2];

int main(){
  int N; scanf("%d", &N);
  int AS = 0, BS = 0;
  for(int i = 1; i <= N; i++){ scanf("%d", &A[i]); AS += A[i]; }
  for(int i = 1; i <= N; i++){ scanf("%d", &B[i]); BS += B[i]; }

  for(int i = 1; i <= BS; i++){ DP[i][0] = N + 1; DP[i][1] = -1; }
  for(int i = 1; i <= N; i++){
    for(int j = BS - B[i]; j >= 0; j--){
      int nx = DP[j][0] + 1, ny = DP[j][1] + A[i];
      if(nx < DP[j + B[i]][0] || (nx == DP[j + B[i]][0] && ny > DP[j + B[i]][1])){
        DP[j + B[i]][0] = nx; DP[j + B[i]][1] = ny;
      }
    }
  }

  int ansx = N + 1, ansy = -1;
  for(int i = AS; i <= BS; i++){
    if(DP[i][0] < ansx){ ansx = DP[i][0]; ansy = DP[i][1]; }
    else if(DP[i][0] == ansx && DP[i][1] > ansy) ansy = DP[i][1];
  }

  printf("%d %d\n", ansx, AS - ansy);
  return 0;
}