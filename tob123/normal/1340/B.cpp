#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 2100;

int dig[] = {0b1110111, 0b010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
int N, K;
int A[n];
int dp[n][n];
int nxt[n][n];

int ch[(1<<7)][10];

void printDp(){
  for(int i=0; i<=N; i++){
    for(int k=0; k<=K; k++){
      cout << dp[i][k] << " ";
    }
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for(int i=0; i<(1<<7); i++){
    for(int j=0; j<=9; j++)
      ch[i][j] = -1;
    for(int j=0; j<10; j++){
      if(i & (~dig[j])) continue;
      ch[i][j] = __builtin_popcount(dig[j]^i);
    }
  }
  cin >> N >> K;
  for(int i=N-1; i>=0; i--){
    string s;
    cin >> s;
    for(int j=0; j<sz(s); j++){
      A[i] *= 2;
      A[i] += s[j]-'0';
    }
  }
  for(int i=1; i<n; i++)
    dp[0][i] = -1;
  for(int i=1; i<=N; i++){
    for(int j=0; j<n; j++){
      dp[i][j] = -1;
      for(int k=9; k>=0; k--){
        if(ch[A[i-1]][k] != -1 && ch[A[i-1]][k] <= j && dp[i-1][j-ch[A[i-1]][k]] != -1){
          dp[i][j] = k;
          nxt[i][j] = j-ch[A[i-1]][k];
          break;
        }
      }
    }
  }
  //printDp();
  if(dp[N][K] == -1){
    cout << -1 << endl;
    return 0;
  }
  vector<int> x;
  int ind = K;
  for(int i=N; i>0; i--){
    x.push_back(dp[i][ind]);
    ind = nxt[i][ind];
  }
  for(int i=0; i<sz(x); i++){
    cout << x[i];
  }
  cout << endl;
}