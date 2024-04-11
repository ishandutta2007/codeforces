#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> P;
vector<int> L;
vector<int> C;

int main(){
  cin >> N;
  P.resize(N);
  L.resize(N);
  C.resize(N);
  for(int i=1; i<N; i++){
    cin >> P[i];
    P[i]--;
    C[P[i]]++;
  }
  for(int i=0; i<N; i++){
    if(C[i] == 0){
      L[P[i]]++;
    }
  }
  for(int i=0; i<N; i++){
    if(C[i] != 0 && L[i] < 3){
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;

  return 0;
}