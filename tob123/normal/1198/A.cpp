#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

vector<ll> A;
//int cnt[1000000];

ll pw(ll b, ll x){
  if(x == 0)
    return 1;
  ll res = pw(b, x/2);
  res *= res;
  res = min(((ll)1e9) + 5, res);
  if(x % 2){
    res *= b;
    res = min(((ll)1e9) + 5, res);
  }
  return res;
}

int main(){
  ll N, I;
  cin >> N >> I;
  ll k = pw(2,I*8/N);
  A.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  /*
  cnt[0] = 1;
  for(int i=1; i<N; i++){
    cnt[i] = cnt[i-1];
    if(A[i] != A[i-1])
      cnt[i]++;
  }
  */
  ll best = N;
  int li = 0;
  A.push_back(5e9);
  int cnt = 0;
  for(int i=0; i<N; i++){
    if(i == 0 || A[i] != A[i-1])
      cnt++;
    /*
    while(cnt[i]-(li==0 ? 0 : cnt[li-1]) > k){
      li++;
    }
    */
    while(cnt > k){
      if(A[li] != A[li+1])
        cnt--;
      li++;
    }
    best = min(best, N-(i-li+1));
  }
  cout << best << endl;

  return 0;
}