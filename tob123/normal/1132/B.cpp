#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;
vector<ll> A;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  ll sum = 0;
  for(int i=0; i<N; i++){
    cin >> A[i];
    sum += A[i];
  }
  sort(A.rbegin(), A.rend());
  cin >> M;
  for(int i=0; i<M; i++){
    ll q;
    cin >> q;
    cout << sum-A[q-1] << "\n";
  }

  return 0;
}