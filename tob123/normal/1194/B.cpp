#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

const int n = 5e4 + 10;

int Q, N, M;
vector<vector<char>> A;
int R[n];
int C[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> Q;
  while(Q--){
    cin >> N >> M;
    A = vector<vector<char>>(N, vector<char>(M));
    for(int i=0; i<N; i++)
      R[i] = 0;
    for(int i=0; i<M; i++)
      C[i] = 0;
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        cin >> A[i][j];
        R[i] += A[i][j] == '*';
        C[j] += A[i][j] == '*';
      }
    }
    int best = N+M;
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        if(A[i][j] == '*'){
          best = min(best, N+M - R[i] - C[j]);
        }
        else{
          best = min(best, N+M - R[i] - C[j] - 1);
        }
      }
    }
    cout << best << "\n";
  }

  return 0;
}