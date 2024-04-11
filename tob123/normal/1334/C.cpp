#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T, N;
vector<ll> A, B;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    A.resize(N);
    B.resize(N);
    for(int i=0; i<N; i++){
      cin >> A[i] >> B[i];
    }
    vector<ll> C = A;
    for(int i=0; i<N; i++){
      A[(i+1)%N] = max(0ll, A[(i+1)%N]-B[i]);
    }
    ll sum = 0;
    ll best = 1e13;
    for(int i=0; i<N;i++){
      sum += A[i];
      best = min(best, C[i]-A[i]);
    }
    sum += best;
    cout << sum << "\n";
  }
}