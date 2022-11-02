#include <bits/stdc++.h>
using namespace std;

const int n = 100009;

int N;
int A[n], I[n];
bool win[n];

int main(){
  cin >> N;
  for(int i=1; i<=N; i++){
    cin >> A[i];
    I[A[i]] = i;
  }
  
  for(int cur=N; cur>0; cur--){
    for(int i=1; I[cur]+i*cur <= N; i++){
      if(A[I[cur]+i*cur] > cur){
        win[I[cur]] |= !win[I[cur]+i*cur];
      }
    }
    for(int i=-1; I[cur]+i*cur > 0; i--){
      if(A[I[cur]+i*cur] > cur){
        win[I[cur]] |= !win[I[cur]+i*cur];
      }
    }
  }

  string res = "";
  for(int i=1; i<=N; i++){
    if(win[i]){
      res.push_back('A');
    }
    else{
      res.push_back('B');
    }
  }
  cout << res << endl;

  return 0;
}