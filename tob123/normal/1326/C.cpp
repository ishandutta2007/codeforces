#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 2e5+10;
const ll MOD = 998244353;

ll N, K;
vector<ll> A;
ll pos[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  A.resize(N);
  vector<ll> I;
  ll sum = 0;
  for(int i=0; i<N; i++){
    cin >> A[i];
    if(A[i] > N-K){
      I.push_back(i);
      sum += A[i];
    }
  }
  ll p = 1;
  for(int j=1; j<sz(I); j++){
    p *= I[j]-I[j-1];
    p %= MOD;
  }
  cout << sum << " " << p << endl;

  return 0;
}