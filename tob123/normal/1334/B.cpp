#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T;
ll N, X;
vector<ll> A;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> X;
    A.resize(N);
    ll sum = 0;
    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    sort(A.rbegin(), A.rend());
    ll i;
    for(i=0; i<N; i++){
      sum += A[i];
      if(X*(i+1) > sum)
        break;
    }
    cout << i << "\n";
  }
}