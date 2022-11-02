#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<ll> A(N);
  vector<int> cnt(20);
  for(int i=0; i<N; i++){
    cin >> A[i];
    for(int j=0; j<20; j++){
      if(A[i]&(1<<j))
        cnt[j]++;
    }
  }
  ll res = 0;
  for(int i=0; i<N; i++){
    ll cur = 0;
    for(int j=0; j<20; j++){
      if(cnt[j]){
        cnt[j]--;
        cur |= 1<<j;
      }
    }
    res += cur*cur;
  }
  cout << res << endl;

}