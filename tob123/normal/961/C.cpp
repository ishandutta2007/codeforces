#include <bits/stdc++.h>
using namespace std;

int N;
bool B[4][100][100];
int C[4];

int main(){
  cin >> N;
  for(int i=0; i<4; i++){
    for(int j=0; j<N; j++){
      for(int k=0; k<N; k++){
        char c;
        cin >> c;
        B[i][j][k] = c=='1';
      }
    }
  }

  for(int i=0; i<4; i++){
    for(int j=0; j<N; j++){
      for(int k=0; k<N; k++){
        if((((j+k)%2)==1) ^ B[i][j][k]){
          C[i]++;
        }
      }
    }
  }

  int best = 1000000;
  for(int i=0; i<4; i++){
    for(int j=i+1; j<4; j++){
      int cur = 0;
      for(int k=0; k<4; k++){
        if(k == j || k == i){
          cur += C[k];
        }
        else{
          cur -= C[k];
        }
      }
      cur += 2 * N * N;
      best = min(best, cur);
    }
  }

  cout << best << endl;


  return 0;
}