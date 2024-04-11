#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N;
vector<ll> A;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  vector<ll> F;
  for(int i=0; i<2; i++){
    ll x = A[i];
    for(int j=2; j<=x; j++){
      if(x%j == 0){
        F.push_back(j);
        while(x%j == 0)
          x /= j;
      }
    }
  }
  sort(F.begin(), F.end());
  F.erase(unique(F.begin(), F.end()), F.end());
  ll res = 1;
  for(ll f : F){
    int a=1000, b=1000;
    for(int i=0; i<N; i++){
      ll x = A[i];
      int cnt = 0;
      while(x % f == 0){
        x /= f;
        cnt++;
      }
      if(cnt < a){
        b = a;
        a = cnt;
      }
      else if(cnt < b){
        b = cnt;
      }
    }
    for(int x=0; x<b; x++){
      res *= f;
    }
  }
  cout << res << endl;
}