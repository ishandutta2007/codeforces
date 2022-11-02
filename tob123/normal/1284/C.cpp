#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 3e5+10;

ll N, M;
ll f[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  f[0] = 1;
  for(ll i=1; i<=N; i++){
    f[i] = f[i-1] * i % M;
  }
  ll sum = 0;
  for(ll i=1; i<=N; i++){
    ll res = (N-i+1)*(N-i+1) % M;
    res *= f[N-i];
    res %= M;
    res *= f[i];
    res %= M;
    sum += res;
    sum %= M;
  }
  cout << sum << endl;

  return 0;
}