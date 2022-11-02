#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

int N;
string S;

int main(){
  cin >> N;
  cin >> S;
  int d=0, t;
  for(int i=0; i<N; i++){
    if(S[i] == ')'){
      d--;
      t = d%2;
    }
    else{
      t = d%2;
      d++;
    }
    cout << t;
  }
  cout << endl;

  return 0;
}