#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int M, K, N, S;
map<int, int> X;
vector<int> A, B;

int main(){
  cin >> M >> K >> N >> S;
  A.resize(M);
  B.resize(S);
  for(int i=0; i<M; i++){
    cin >> A[i];
  }
  for(int i=0; i<S; i++){
    cin >> B[i];
    X[B[i]]++;
  }

  int l = -1;
  int r = -1;
  int cnt = S;
  while(r < M){
    if(l >= 0){
      if(X.count(A[l])){
        X[A[l]]++;
        if(X[A[l]] > 0)
          cnt++;
      }
    }
    l++;
    while(cnt > 0 || r-l+1 < K){
      r++;
      if(r == M)
        break;
      if(X.count(A[r])){
        X[A[r]]--;
        if(X[A[r]] >= 0){
          cnt--;
        }
      }
    }
    //cout << l << " " << r << endl;
    if(r == M)
      break;
    //cout << "ges: " << 1 + l/K + (M-r-1)/K << endl;
    if(l/K + (M-r-1)/K >= N-1){
      //cout << "found" << endl;
      int d = l-l/K*K;
      int d2 = r-l+1-K;
      X = map<int,int>();
      for(int i=0; i<S; i++){
        X[B[i]]++;
      }
      cout << d+d2 << endl;
      for(int i=0; i<d; i++){
        cout << i+1 << " ";
      }
      cnt = K-S;
      for(int i=l; i<=r; i++){
        if(X[A[i]] > 0){
          X[A[i]]--;
        }
        else{
          if(cnt > 0)
            cnt--;
          else{
            cout << i+1 << " ";
          }
        }
      }
      cout << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}