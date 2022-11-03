#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, M;
vector<ll> A;

int main(){
  cin >> N >> M;
  A.resize(N);
  ll hsum = 0;
  for(ll i=0; i<N; i++){
    cin >> A[i];
    hsum += A[i];
  }
  sort(A.begin(), A.end());
  ll hCov = 0;
  for(ll i=0; i<A.size(); i++){
    if(A[i] > hCov)
      hCov++;
  }
  ll sum = N;
  if(hCov < A[A.size()-1]){
    sum += A[A.size()-1]-hCov;
  }
  cout << hsum-sum << endl;

  return 0;
}