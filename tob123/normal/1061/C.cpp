#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int n = 100005;
const int maxa = 1000009;
const ll MOD = 1e9+7;

int N;
int A[n];
vector<int> divisors[maxa];
ll pos[maxa];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  for(int i=n; i>0; i--){
    for(int x=1; x*i<maxa; x++){
      divisors[i*x].push_back(i);
    }
  }
  
  pos[0] = 1;
  for(int i=0; i<N; i++){
    for(int x : divisors[A[i]]){
      pos[x] = (pos[x] + pos[x-1]) % MOD;
    }
  }

  ll sum = 0;
  for(ll x : pos){
    sum = (sum + x) % MOD;
  }
  cout << sum-1 << endl;

  return 0;
}