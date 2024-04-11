#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

ll N, M, K;
deque<ll> A;

int main(){
  cin >> N >> M >> K;
  A.resize(M);
  for(int i=0; i<M; i++){
    cin >> A[i];
    A[i]--;
  }
  sort(A.begin(), A.end());
  ll cnt = 0;
  ll sub = 0;
  while(!A.empty()){
    cnt++;
    ll div = (A[0]-sub)/K;
    ll to = div*K+K-1;
    ll i;
    for(i=0; !A.empty(); i++){
      if(A[0]-sub > to)
        break;
      A.pop_front();
    }
    sub += i;
  }
  cout << cnt << endl;

  return 0;
}