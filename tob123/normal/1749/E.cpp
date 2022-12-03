#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef pair<int,int> pii;

void printI(vector<vector<int>> X){
  for(int i=0; i<sz(X); i++){
    for(int j=0; j<sz(X[0]); j++){
      cout << X[i][j] << " ";
    }
    cout << endl;
  }
}
void printC(vector<vector<char>> X){
  for(int i=0; i<sz(X); i++){
    for(int j=0; j<sz(X[0]); j++){
      cout << (int)X[i][j] << " ";
    }
    cout << endl;
  }
}

int N, M;

int Y[4] = {1, 1, -1, -1};
int X[4] = {-1, 1, -1, 1};

int pos(vector<vector<char>> A, vector<vector<int>> C, vector<vector<char>>& mp){
  deque<pii> Q;
  set<pii> vis;
  vector<vector<pii>> from(sz(A), vector<pii>(sz(A[0])));
  for(int j=1; j<=N; j++){
    if(A[j][1]){
      if(C[j][1])
        Q.emplace_back(j, 1);
      else
        Q.emplace_front(j, 1);
      vis.emplace(j, 1);
    }
  }
  while(!Q.empty()){
    auto [y, x] = Q.front();
    Q.pop_front();
    for(int i=0; i<4; i++){
      int yn = y+Y[i];
      int xn = x+X[i];
      if(A[yn][xn] && !vis.count(make_pair(yn, xn))){
        from[yn][xn] = make_pair(y, x);
        vis.emplace(yn, xn);
        if(C[yn][xn]){
          Q.emplace_back(yn, xn);
        }
        else
          Q.emplace_front(yn, xn);
        C[yn][xn] += C[y][x];
      }
    }
  }
  int bst = N*M+1;
  for(int j=1; j<=N; j++){
    if(vis.count(make_pair(j, M))){
      bst = min(bst, C[j][M]);
    }
  }
  for(int i=1; i<=N; i++){
    if(vis.count(make_pair(i, M)) && C[i][M] == bst){
      int y=i, x=M;
      while(y!=0){
        mp[y][x] = true;
        tie(y, x) = from[y][x];
      }
      break;
    }
  }
  return bst;
}

int main(){
  int T;
  cin >> T;
  while(T--){
    cin >> N >> M;
    vector<vector<char>> A(N+2, vector<char>(M+2));
    for(int i=1; i<=N; i++){
      for(int j=1; j<=M; j++){
        cin >> A[i][j];
        A[i][j] = A[i][j] == '#';
      }
    }
    vector<vector<char>> B;
    vector<vector<char>> mp;
    int res;
    mp = A;
    B = A;
    vector<vector<int>> C(N+2, vector<int>(M+2, 0));
    for(int i=1; i<=N; i++){
      for(int j=1; j<=M; j++){
        if(!A[i-1][j] && !A[i+1][j] && !A[i][j-1] && !A[i][j+1] && !A[i][j]){
          B[i][j] = true;
          C[i][j] = 1;
        }
      }
    }
    res = pos(B, C, mp);
    if(res == N*M+1){
      cout << "NO" << endl;
    }
    else{
      cout << "YES" << endl;
      for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
          cout << (mp[i][j] ? '#' : '.');
        }
        cout << endl;
      }
    }
  }

  return 0;
}