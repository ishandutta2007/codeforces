#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
vector<vector<int>> A;
vector<int> R;

int main(){
  cin >> N >> M;
  A.resize(N);
  R.resize(N);
  for(int i=0; i<M; i++){
    int a, b;
    cin >> a >> b;
    A[a-1].push_back(b-1);
  }

  for(int i=0; i<N; i++){
    if(A[i].size()){
      R[i] = N+1;
      for(int x : A[i]){
        R[i] = min(R[i], (N+x-i)%N);
      }
      R[i] += N*(A[i].size()-1);
    }
    //cout << R[i] << endl;
  }

  for(int i=0; i<N; i++){
    int time = 0;
    for(int j=0; j<N; j++){
      if(R[(i+j)%N])
        time = max(time, R[(i+j)%N] + j);
    }
    cout << time << " ";
  }
  cout << endl;

  return 0;
}