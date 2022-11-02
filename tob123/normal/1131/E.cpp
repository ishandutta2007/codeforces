#include <bits/stdc++.h>
using namespace std;

const int n = 1e5+10;

int N;
vector<string> S;

int L[n], R[n];
bool oneChar[n];
int mx[n][26];

int main(){
  cin >> N;
  S.resize(N);
  for(int i=0; i<N; i++){
    cin >> S[i];
    int x;
    for(x=1; x<S[i].size(); x++){
      if(S[i][x] != S[i][0])
        break;
    }
    L[i] = x;
    int sz = S[i].size();
    for(x=sz-2; x>=0; x--){
      if(S[i][x] != S[i][sz-1])
        break;
    }
    R[i] = sz-x-1;

    char curC = 0;
    int cnt = 0;
    for(char c : S[i]){
      if(c == curC){
        cnt++;
      }
      else{
        curC = c;
        cnt = 1;
      }
      mx[i][curC-'a'] = max(mx[i][curC-'a'], cnt);
    }
    oneChar[i] = (L[i] == S[i].size());
  }

  for(int i=1; i<N; i++){
    char fc = S[i][0]-'a', lc = S[i][S[i].size()-1]-'a';
    for(int c=0; c<26; c++){
      if(mx[i-1][c]){
        mx[i][c] = max(mx[i][c], 1);
      }
    }
    if(oneChar[i]){
      mx[i][fc] = max(mx[i][fc], (mx[i-1][fc]+1) * (L[i]+1)-1);
    }
    else{
      if(fc == lc){
        if(mx[i-1][fc]){
          mx[i][fc] = L[i] + R[i] + 1;
        }
      }
      else{
        if(mx[i-1][fc]){
          mx[i][fc] = max(mx[i][lc], L[i]+1);
        }
        if(mx[i-1][lc]){
          mx[i][lc] = max(mx[i][lc], R[i]+1);
        }
      }
    }
  }

  int best = 0;
  for(int i=0; i<26; i++){
    best = max(best, mx[N-1][i]);
  }

  cout << best << endl;

  return 0;
}