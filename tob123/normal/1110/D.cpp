#include <bits/stdc++.h>
using namespace std;

const int n = 1e6+10;
const int INF = 1e8;

int pos[n][3][3]; //pos, von n+1, von n+2
int A[n];
int N, M;

void printPos(){
  for(int i=0; i<=M; i++){
    for(int j=0; j<3; j++){
      for(int k=0; k<3; k++){
        if(pos[i][j][k] < 0)
          cout << -1 << " ";
        else
          cout << pos[i][j][k] << " ";
      }
      cout << "  ";
    }
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for(int i=1; i<=N; i++){
    int x;
    cin >> x;
    A[x]++;
  }
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      pos[0][i][j] = -1e8;
    }
  }
  pos[0][0][0] = 0;
  for(int i=1; i<=M; i++){
    for(int h1=0; h1<3; h1++){
      for(int h2=0; h2<3; h2++){
        if(h1+h2 > A[i]){
          pos[i][h1][h2] = -INF;
        }
        else{
          int best = -INF;
          for(int r=0; r<3; r++){
            if(r+h1+h2 <= A[i]){
              best = max(best, pos[i-1][r][h1] + r + (A[i]-r-h1-h2)/3);
            }
          }
          pos[i][h1][h2] = best;
        }
      }
    }
  }
  
  //printPos();

  cout << pos[M][0][0] << endl;

  return 0;
}