#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1100;

int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};

int N, M, T;
int A[n][n];
int x[n][n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> T;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=M; j++){
      char c;
      cin >> c;
      A[i][j] = c-'0';
    }
  }
  for(int i=0; i<=N; i++){
    A[i][0] = x[i][0] = 100;
    A[i][M+1] = x[i][M+1] = 100;
  }
  for(int i=0; i<=M; i++){
    A[0][i] = x[0][i] = 100;
    A[N+1][i] = x[N+1][i] = 100;
  }
  queue<pii> Q;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=M; j++){
      bool pos = false;
      for(int k=0; k<4; k++){
        pos |= A[i+X[k]][j+Y[k]] == A[i][j];
      }
      if(pos){
        x[i][j] = 1;
        Q.push({i,j});
      }
    }
  }
  while(!Q.empty()){
    int i, j;
    tie(i, j) = Q.front();
    Q.pop();
    for(int k=0; k<4; k++){
      if(!x[i+X[k]][j+Y[k]]){
        x[i+X[k]][j+Y[k]] = x[i][j]+1;
        Q.push({i+X[k], j+Y[k]});
      }
    }
  }
  while(T--){
    int i, j;
    ll p;
    cin >> i >> j >> p;
    if(p < x[i][j] || x[i][j] == 0){
      cout << A[i][j] << "\n";
    }
    else{
      cout << ((p-x[i][j]+1+A[i][j])&1) << "\n";
    }
  }
}