#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, K, L, M;
vector<ll> A;

bool vis[100001];

int main(){
  cin >> N >> K >> L;
  M = N*K;
  A.resize(M);
  for(int i=0; i<M; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());

  int m = A[0] + L;
  auto it = upper_bound(A.begin(), A.end(), m);
  it--;
  if(it == A.begin() && N>1){
    cout << 0 << endl;
    return 0;
  }

  int x = distance(A.begin(), it);
  ll cur;
  ll sum = 0;
  int r = M-1;
  for(int i=0; i<N; i++){
    x = min(x, r);
    if(x == -1){
      cout << 0 << endl;
      return 0;
    }
    cur = A[x];
    //cout << A[x];
    vis[x] = true;
    x--;

    for(int j=0; j<K-1; j++){
      while(vis[r]){
        r--;
      }
      vis[r] = true;
      //cout << " " << A[r];
      cur = min(cur, A[r]);
      r--;
    }
    //cout << endl;
    
    sum += cur;
  }

  cout << sum << endl;

  return 0;
}