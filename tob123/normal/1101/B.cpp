#include <bits/stdc++.h>
using namespace std;

string S, S2;

int findC(string& s, int ind, char c){
  for(int i=ind; i<s.size(); i++){
    if(s[i] == c){
      return i;
    }
  }
  cout << -1 << endl;
  exit(0);
  return -1;
}

int main(){
  cin >> S;
  S2 = S;
  for(int i=0; i<S2.size(); i++){
    S2[i] = S[S2.size()-1-i];
  }
  int op = findC(S, 0, '[');
  int col = findC(S, op, ':');
  int clo = findC(S2, 0, ']');
  int col2 = findC(S2, clo, ':');
  clo = S.size()-1-clo;
  col2 = S.size()-1-col2;
  if(col >= col2){
    cout << -1 << endl;
    return 0;
  }
  int stay = 4;
  for(int i=col+1; i<=col2; i++){
    if(S[i] == '|')
      stay++;
  }
  cout << stay << endl;

  return 0;
}