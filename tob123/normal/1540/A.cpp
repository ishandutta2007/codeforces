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

int N, T;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    ll sum = 0;
    vector<ll> D(N);
    for(int i=0; i<N; i++){
      cin >> D[i];
    }
    sort(D.begin(), D.end());
    sum += D.back();
    ll curS = 0;
    for(int i=0; i<N; i++){
      sum += -i*D[i]+curS;
      curS += D[i];
    }
    cout << sum << "\n";
  }
}