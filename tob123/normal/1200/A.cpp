#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

bool b[10];

int main(){
  int N;
  string S;
  cin >> N;
  cin >> S;

  for(int i=0; i<N; i++){
    if(S[i] == 'R'){
      for(int j=9; j>=0; j--){
        if(!b[j]){
          b[j] = true;
          break;
        }
      }
    }
    else if(S[i] == 'L'){
      for(int j=0; j<10; j++){
        if(!b[j]){
          b[j] = true;
          break;
        }
      }
    }
    else{
      b[S[i]-'0'] = false;
    }
  }
  for(int i=0; i<10; i++){
    cout << b[i];
  }
  cout << endl;

  return 0;
}