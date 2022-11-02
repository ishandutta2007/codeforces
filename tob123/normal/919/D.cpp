#include <bits/stdc++.h>
using namespace std;

int N, M;
string S;
vector<int> G[300001];
int occ[300001][26];
int in[300001];

int main(){
  cin >> N >> M;
  cin >> S;

  int a, b;
  for(int i=0; i<M; i++){
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    in[b]++;
  }

  queue<int> Q;
  for(int i=0; i<N; i++){
    if(in[i] == 0){
      Q.push(i);
    }
  }

  int res = 0;
  while(!Q.empty()){
    int cur = Q.front();
    Q.pop();
    occ[cur][S[cur]-'a']++;
    res = max(res, occ[cur][S[cur]-'a']);
    for(int x : G[cur]){
      in[x]--;
      if(in[x] == 0)
        Q.push(x);
      for(int i=0; i<26; i++){
        occ[x][i] = max(occ[x][i], occ[cur][i]);
      }
    }
  }

  for(int i=0; i<N; i++){
    if(in[i] != 0){
      cout << -1 << endl;
      return 0;
    }
  }

  cout << res << endl;

  return 0;
}