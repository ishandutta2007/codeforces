#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<ll,int> pii;
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

  int T;
  cin >> T;
  while(T--){
    ll N, W;
    cin >> N >> W;
    vector<pii> A(N);
    for(int i=0; i<N; i++){
      cin >> A[i].first;
      A[i].second = i;
    }
    sort(A.rbegin(), A.rend());
    vector<int> res;
    ll sum = 0;
    for(auto [w, ind] : A){
      if(sum+w <= W){
        sum += w;
        res.push_back(ind);
      }
    }
    if(sum*2 >= W && sum <= W){
      cout << sz(res) << "\n";
      for(int x : res)
        cout << x+1 << " ";
      cout << "\n";
    }
    else{
      cout << -1 << "\n";
    }
  }
}