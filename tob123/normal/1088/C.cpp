#include <bits/stdc++.h>
using namespace std;

int N;
int A[100000];

int main(){
  cin >> N;
  cout << N+1 << "\n";
  for(int i=1; i<=N; i++){
    cin >> A[i];
  }
  for(int i=1; i<N; i++){
    int add = 2e5-1 - (A[i]-A[i+1]);
    cout << 1 << " " << i << " " << add << "\n";
  }
  cout << 1 << " " << N << " " << 2e5-1-A[N] << "\n";
  cout << 2 << " " << N << " " << 200000 << "\n";

  return 0;
}