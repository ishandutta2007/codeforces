#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int n = 300005;

int N, Mcnt;
vector<vector<int>> M;
string toC = "ACGT";
int dp[n][4][4];
int dp2[n][4][4];
pii cur[6] = {{0, 1}, {0, 2}, {0,3}, {1, 2}, {1, 3}, {2, 3}};
int oth[6] = {5, 4, 3, 2, 1, 0};

int howMany(int y, int x, int val){
  int cnt = 0;
  for(int i=x; i<Mcnt; i+=2){
    if(M[y][i] != val)
      cnt++;
  }
  return cnt;
}

void change(int y, int x, int val){
  for(int i=x; i<Mcnt; i+=2){
    M[y][i] = val;
  }
}

int howMany2(int x, int y, int val){
  int cnt = 0;
  for(int i=y; i<N; i+=2){
    if(M[i][x] != val)
      cnt++;
  }
  return cnt;
}

void change2(int x, int y, int val){
  for(int i=y; i<N; i+=2){
    M[i][x] = val;
  }
}

int main(){
  cin >> N >> Mcnt;
  M = vector<vector<int>>(N, vector<int>(Mcnt));
  for(int i=0; i<N; i++){
    for(int j=0; j<Mcnt; j++){
      char x;
      cin >> x;
      switch(x){
      case 'A':
        M[i][j] = 0;
        break;
      case 'C':
        M[i][j] = 1;
        break;
      case 'G':
        M[i][j] = 2;
        break;
      case 'T':
        M[i][j] = 3;
        break;
      }
    }
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<4; j++){
      for(int k=0; k<4; k++){
        dp[i][j][k] = n;
      }
    }
  }
  for(int i=0; i<Mcnt; i++){
    for(int j=0; j<4; j++){
      for(int k=0; k<4; k++){
        dp2[i][j][k] = n;
      }
    }
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<6; j++){
      int a, b, toa, tob;
      tie(a, b) = cur[j];
      tie(toa, tob) = cur[oth[j]];
      int minCur = min(howMany(i, 0, a) + howMany(i, 1, b), howMany(i, 1, a) + howMany(i, 0, b));
      int minOth = 0;
      if(i > 0){
        minOth = dp[i-1][toa][tob];
      }
      if(minOth + minCur < dp[i][a][b]){
        dp[i][a][b] = minCur + minOth;
      }
    }
  }
  int best = n;
  int bestI = -1;
  for(int i=0; i<6; i++){
    int a, b;
    tie(a, b) = cur[i];
    if(dp[N-1][a][b] < best){
      best = dp[N-1][a][b];
      bestI = i;
    }
  }

  for(int i=0; i<Mcnt; i++){
    for(int j=0; j<6; j++){
      int a, b, toa, tob;
      tie(a, b) = cur[j];
      tie(toa, tob) = cur[oth[j]];
      int minCur = min(howMany2(i, 0, a) + howMany2(i, 1, b), howMany2(i, 1, a) + howMany2(i, 0, b));
      int minOth = 0;
      if(i > 0){
        minOth = dp2[i-1][toa][tob];
      }
      if(minOth + minCur < dp2[i][a][b]){
        dp2[i][a][b] = minCur + minOth;
      }
    }
  }
  int best2 = n;
  int bestI2 = -1;
  for(int i=0; i<6; i++){
    int a, b;
    tie(a, b) = cur[i];
    if(dp2[Mcnt-1][a][b] < best2){
      best2 = dp2[Mcnt-1][a][b];
      bestI2 = i;
    }
  }


  if(best < best2){
    int I = bestI;
    for(int x=N-1; x>=0; x--){
      int a, b;
      tie(a, b) = cur[I];
      if(howMany(x, 0, a) + howMany(x, 1, b) < howMany(x, 1, a) + howMany(x, 0, b)){
        change(x, 0, a);
        change(x, 1, b);
      }
      else{
        change(x, 1, a);
        change(x, 0, b);
      }
      I = oth[I];
    }
    //cout << best << endl;
  }
  else{
    int I = bestI2;
    for(int x=Mcnt-1; x>=0; x--){
      int a, b;
      tie(a, b) = cur[I];
      if(howMany2(x, 0, a) + howMany2(x, 1, b) < howMany2(x, 1, a) + howMany2(x, 0, b)){
        change2(x, 0, a);
        change2(x, 1, b);
      }
      else{
        change2(x, 1, a);
        change2(x, 0, b);
      }
      I = oth[I];
    }
    //cout << best2 << endl;
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<Mcnt; j++){
      cout << toC[M[i][j]];
    }
    cout << "\n";
  }

  return 0;
}