#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

int T, N, K;
vector<int> A;

int main(){
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> N >> K;
    A.resize(N);
    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    sort(A.begin(), A.end());
    int best = 1e9+10;
    int bestI = 0;
    for(int i=0; i<N-K; i++ ){
      if(A[i+K]-A[i] < best){
        best = A[i+K]-A[i];
        bestI = (A[i+K]+A[i])/2;
      }
    }
    cout << bestI << endl;
  }

  return 0;
}