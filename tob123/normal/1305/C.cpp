#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 2000;

const int sz = n;
vector<ll> BIT;

void update(int y, ll val){ // adds val to entry x (0-based)
  y++;
  while(y <= sz){
    BIT[y] += val;
    y += y & (-y);
  }
}

ll query(int x){ // returns sum of all elements 0..x
  x++;
  ll res = 0;
  while(x > 0){
    res += BIT[x];
    x -= x & (-x);
  }
  return res;
}

int N, M;
ll A[n];

ll pw(ll b, ll e){
  if(e == 0)
    return 1;
  ll cur = pw(b, e/2);
  cur *= cur;
  cur %= M;
  if(e%2)
    cur *= b;
  cur %= M;
  return cur;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  BIT.resize(n);
  ll cnt = 0;
  vector<int> X;
  for(int i=0; i<N; i++){
    int x;
    cin >> x;
    A[x%M]++;
    X.push_back(x);
  }
  sort(X.begin(), X.end());
  for(int x : X){
    update(x%M, 1);
    cnt += query(M) - query(x%M);
    //cout << "cnt: " << cnt << endl;
    cnt %= 2;
  }
  ll res = 1;
  for(int i=0; i<M; i++){
    if(A[i] > 1)
      res = 0;
    for(int j=1; j<M-i; j++){
      res *= pw(j, A[i]*A[(i+j)%M]);
      res %= M;
    }
  }
  if(cnt % 2 && res != 0)
    res = M - res;
  cout << res << endl;

  return 0;
}