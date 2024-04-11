#include <bits/stdc++.h>
using namespace std;

int N, K;

int main(){
  cin >> N >> K;
  int m = 1;
  int cur;
  for(int i=0; i<N; i++){
    cin >> cur;
    if(K%cur == 0){
      m = max(m, cur);
    }
  }
  cout << K/m << endl;

  return 0;
}