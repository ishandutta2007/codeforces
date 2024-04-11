#include <bits/stdc++.h>
using namespace std;

int N, Q;
string S;
vector<int> W[3];
int dp[300][300][300];
int nxt[100100][26];

void printDp(){
  for(int i=0; i<=W[0].size(); i++){
    for(int j=0; j<=W[1].size(); j++){
      for(int k=0; k<=W[2].size(); k++){
        cout << dp[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  cout << "\n---------------\n";

  for(int i=0; i<=N+1; i++){
    for(int j=0; j<26; j++){
      cout << nxt[i][j] << " ";
    }
    cout << endl;
  }

  cout << "\n---------------\n";
  for(int i=0; i<=N+1; i++){
    cout << (int) S[i] << " ";
  }
  cout << endl;
}

void update0(){
  for(int i=W[0].size(); i<=W[0].size(); i++){
    for(int j=0; j<=W[1].size(); j++){
      for(int k=0; k<=W[2].size(); k++){
        dp[i][j][k] = N+1;
        if(i > 0)
          dp[i][j][k] = nxt[dp[i-1][j][k]][W[0][i-1]];
        if(j > 0)
          dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j-1][k]][W[1][j-1]]);
        if(k > 0)
          dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k-1]][W[2][k-1]]);
      }
    }
  }
}
void update1(){
  for(int i=0; i<=W[0].size(); i++){
    for(int j=W[1].size(); j<=W[1].size(); j++){
      for(int k=0; k<=W[2].size(); k++){
        dp[i][j][k] = N+1;
        if(i > 0)
          dp[i][j][k] = nxt[dp[i-1][j][k]][W[0][i-1]];
        if(j > 0)
          dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j-1][k]][W[1][j-1]]);
        if(k > 0)
          dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k-1]][W[2][k-1]]);
      }
    }
  }
}
void update2(){
  for(int i=0; i<=W[0].size(); i++){
    for(int j=0; j<=W[1].size(); j++){
      for(int k=W[2].size(); k<=W[2].size(); k++){
        dp[i][j][k] = N+1;
        if(i > 0)
          dp[i][j][k] = nxt[dp[i-1][j][k]][W[0][i-1]];
        if(j > 0)
          dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j-1][k]][W[1][j-1]]);
        if(k > 0)
          dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k-1]][W[2][k-1]]);
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> Q;
  cin >> S;

  S = "A" + S;
  S.push_back('A');
  for(int i=1; i<=N; i++){
    S[i] -= 'a';
  }
  for(int i=0; i<300; i++){
    for(int j=0; j<300; j++){
      for(int k=0; k<300; k++){
        dp[i][j][k] = N+1;
      }
    }
  }
  dp[0][0][0] = 0;
  for(int i=0; i<26; i++){
    nxt[N+1][i] = N+1;
  }
  for(int i=N; i>=0; i--){
    for(int j=0; j<26; j++){
      if(S[i+1] == j)
        nxt[i][j] = i+1;
      else
        nxt[i][j] = nxt[i+1][j];
    }
  }
  //printDp();

  for(int q=0; q<Q; q++){
    char t, c;
    int ind;
    cin >> t;
    if(t == '-'){
      cin >> ind;
      ind--;
      W[ind].pop_back();
    }
    else{
      cin >> ind >> c;
      ind--;
      c -= 'a';
      W[ind].push_back(c);
      if(ind == 0)
        update0();
      else if(ind == 1)
        update1();
      else
        update2();
    }
    cout << ((dp[W[0].size()][W[1].size()][W[2].size()] == N+1) ? "NO" : "YES") << endl;
  }

  return 0;
}