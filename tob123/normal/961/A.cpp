#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[1001];

int main(){
  cin >> N >> M;
  for(int i=0; i<M; i++){
    int c;
    cin >> c;
    A[c]++;
  }
  int m = 100000;
  for(int i=1; i<=N; i++){
    m = min(m, A[i]);
  }
  cout << m << endl;

  return 0;
}