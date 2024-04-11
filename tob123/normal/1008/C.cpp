#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A, B;

int main(){
  cin >> N;
  A.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  int cnt = 0;
  int j = 0;
  for(int i=0; i<N; i++){
    while(j < N && A[j] <= A[i])
      j++;
    if(j == N)
      break;
    cnt++;
    j++;
  }

  cout << cnt << endl;

  return 0;
}