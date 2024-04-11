#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

const int n = 1e5+10;

int N, K;
bool B[n];
stack<int> A0, A1;

int main(){
  cin >> N >> K;
  int l1=0, l0=0, r0=0, r1=0;
  for(int i=0; i<N; i++){
    char c;
    cin >> c;
    B[i] = c=='1';
    if(B[i])
      r1 = i;
    else
      r0 = i;
  }
  for(int i=N-1; i>=0; i--){
    if(B[i])
      l1 = i;
    else
      l0 = i;
  }
  if(r1-l1+1 <= K || r0-l0+1 <= K){
    cout << "tokitsukaze" << endl;
  }
  else{
    for(int i=K; i<N; i++){
      if(B[i])
        r1 = i;
      else
        r0 = i;
      if(B[N-i+K-1])
        l1 = i;
      else
        l0 = i;
    }
    for(int i=K; i<=N; i++){
      if(r1-l1+1 > K || r0-l0+1 > K){
        cout << "once again" << endl;
        return 0;
      }
      if(i < N){
        if(B[i-K]){
          l1 = min(l1, i-K);
          r1 = max(r1, i-K);
          A1.push(i-K);
        }
        else{
          l0 = min(l0, i-K);
          r0 = max(r0, i-K);
          A0.push(i-K);
        }
        if(i == r0){
          r0 = A0.top();
        }
        else if(i == r1){
          r1 = A1.top();
        }
      }
    }
    cout << "quailty" << endl;
  }

  return 0;
}