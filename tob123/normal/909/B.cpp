#include <bits/stdc++.h>
using namespace std;

int N;
int used[102];

int main(){
  cin >> N;
  for(int i=0; i<N; i++){
    for(int j=i+1; j<=N; j++){
      for(int k=i; k<j; k++){
        used[k]++;
      }
    }
  }
  int m = 0;
  for(int i=0; i<N; i++){
    m = max(m, used[i]);
  }
  cout << m << endl;

  return 0;
}