#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1000000000;

int A[3010], B[3010], ID[3010];

int DP1[3010][3010];
int DP2[3010][3010];

vector<int> ansA, ansB;

int main(){
  int N, AN, BN; scanf("%d%d%d", &N, &AN, &BN);
  for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
  for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
  for(int i = 1; i <= N; i++) ID[i] = i;

  for(int i = 1; i <= N; i++){
    for(int j = i + 1; j <= N; j++){
      if(A[i] < A[j]){ swap(A[i], A[j]); swap(B[i], B[j]); swap(ID[i], ID[j]); }
    }
  }

  for(int i = 0; i <= N; i++){
    for(int j = 0; j <= N; j++){
      // A j, B i-j
      if(j > AN || i - j < 0 || i - j > BN) DP1[i][j] = -INF; // impossible
      else if(i == 0) DP1[i][j] = 0; // i = j = 0
      else if(j == 0){ // A 0, B i
        DP1[i][j] = DP1[i - 1][j] + B[i];
      }
      else{
        int x = DP1[i - 1][j - 1] + A[i];
        int y = DP1[i - 1][j] + B[i];

        DP1[i][j] = max(x, y);
      }
    }
  }

  for(int i = 0; i <= N; i++){
    for(int j = 0; j <= N; j++){
      if(j > i || j > BN) DP2[i][j] = -INF;
      else if(i == 0) DP2[i][j] = 0; // i = j = 0
      else if(j == 0) DP2[i][j] = DP2[i - 1][j];
      else{
        int x = DP2[i - 1][j - 1] + B[N - i + 1];
        int y = DP2[i - 1][j];

        DP2[i][j] = max(x, y);
      }
    }
  }

  int ans = 0, ansn = -1;
  for(int i = 0; i <= AN + BN; i++){
    int v = DP1[i][AN] + DP2[N - i][BN - i + AN];
    if(v > ans){ ans = v; ansn = i; }
  }

  int nowi = ansn, nowj = AN;
  for(;;){
    if(nowi == 0 && nowj == 0) break;

    if(nowj == 0){
      ansB.push_back(ID[nowi]); nowi--;
    }
    else{
      int x = DP1[nowi - 1][nowj - 1] + A[nowi];
      int y = DP1[nowi - 1][nowj] + B[nowi];

      if(DP1[nowi][nowj] == x){
        ansA.push_back(ID[nowi]);
        nowi--; nowj--;
      }
      else{ ansB.push_back(ID[nowi]); nowi--; }
    }
  }

  nowi = N - ansn; nowj = BN - ansn + AN;
  for(;;){
    if(nowi == 0 && nowj == 0) break;

    if(nowj == 0) nowi--;
    else{
      int x = DP2[nowi - 1][nowj - 1] + B[N - nowi + 1];
      int y = DP2[nowi - 1][nowj];

      if(DP2[nowi][nowj] == x){
        ansB.push_back(ID[N - nowi + 1]);
        nowi--; nowj--;
      }
      else nowi--;
    }
  }

  printf("%d\n", ans);
  for(int x : ansA) printf("%d ", x); printf("\n");
  for(int x : ansB) printf("%d ", x); printf("\n");
  return 0;
}