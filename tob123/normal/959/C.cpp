#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
  ios_base::sync_with_stdio(false);
  cin >> N;
  
  if(N <= 5){
    cout << -1 << endl;
  }
  else{
    cout << 1 << " " << 2 << endl;
    cout << 1 << " " << 3 << endl;
    cout << 1 << " " << 4 << endl;
    for(int i=5; i<=N; i++){
      cout << 2 << " " << i << endl;
    }
  }

  for(int i=1; i<N; i++){
    cout << i << " " << i+1 << endl;
  }

  return 0;
}