#include <bits/stdc++.h>
using namespace std;

const int n = 1e5+10;

int N, M, K;
int B[n];
vector<int> R;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> K;
  for(int i=0; i<N; i++){
    cin >> B[i];
  }
  for(int i=1; i<N; i++){
    R.push_back(B[i]-B[i-1]-1);
  }
  sort(R.begin(), R.end());
  int res = N;
  for(int i=0; i<N-K; i++){
    res += R[i];
  }
  cout << res << endl;

  return 0;
}