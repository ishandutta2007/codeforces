#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef pair<int,int> pii;

int main(){
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    ll sum = 0;
    for(int i=0; i<N; i++){
      cin >> A[i];
      sum += A[i];
    }
    ll mx = 0;
    for(int i=0; i<N; i++){
      cin >> B[i];
      sum += B[i];
      mx = max(mx, B[i]);
    }
    sum -= mx;
    cout << sum << endl;
  }

  return 0;
}