#include <bits/stdc++.h>
using namespace std;

const int n = 505;

struct node{
  vector<int> nxt;
  int cnt, depth;
};

int N, K;
vector<int> S, M;
vector<node> T;
int dp[n][n][11];
vector<int> dp2[n][n][11];
bool solved[n][n];

void addString(string& s, int cnt, int ind, int cur){
  T[cur].cnt += cnt;
  if(ind >= s.size()){
    return;
  }
  int nxtInd = s[ind]-'0';
  if(T[cur].nxt[nxtInd] == -1){
    T[cur].nxt[nxtInd] = T.size();
    T.push_back({vector<int>(10, -1), 0, T[cur].depth+1});
  }
  int nxt = T[cur].nxt[nxtInd];
  addString(s, cnt, ind+1, nxt);
}

/*
void printTrie(){
  for(int i=0; i<T.size(); i++){
    cout << i << ": " << T[i].cnt << ", " << T[i].depth << " -> [";
    for(int x : T[i].nxt){
      cout << x << " ";
    }
    cout << "]" << endl;
  }
}
*/

void solve(int n, int a){
  if(solved[n][a]){
    return;
  }
  vector<int> I;
  for(int x : T[n].nxt){
    if(x != -1){
      I.push_back(x);
    }
  }
  for(int i=0; i<=K; i++){
    dp2[n][a][i].resize(I.size()+1);
  }
  for(int x : I){
    solve(x, a);
  }

  for(int i=I.size()-1; i>=0; i--){
    int c = I[i];
    for(int f=0; f<=K; f++){
      for(int l=0; l<=f; l++){
        dp2[n][a][f][i] = max(dp2[n][a][f][i], dp2[n][a][f-l][i+1] + dp[c][a][l]);
      }
    }
  }
  for(int f=0; f<=K; f++){
    dp[n][a][f] = dp2[n][a][f][0];
  }

  if(n != a){
    solve(n, n);
    for(int f=1; f<=K; f++){
      dp[n][a][f] = max(dp[n][a][f], T[n].cnt*(T[n].depth-T[a].depth) + dp[n][n][f-1]);
    }
  }

  solved[n][a] = true;
}

int main(){
  cin >> N >> K;
  S.resize(N);
  M.resize(N);
  T.push_back({vector<int>(10, -1), 0, 0});
  int totalSum = 0;
  for(int i=0; i<N; i++ ){
    string s;
    int m;
    cin >> s >> m;
    addString(s, m, 0, 0);
    totalSum += s.length() * m;
  }
  //printTrie();
  solve(0, 0);
  cout << totalSum - dp[0][0][K] << endl;

  return 0;
}