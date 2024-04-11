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
  int T;
  cin >> T;
  while(T--){
    int N, X;
    cin >> N >> X;
    vector<int> W(N);
    ll sum = 0;
    for(int i=0; i<N; i++){
      cin >> W[i];
      sum += W[i];
    }
    if(sum == X){
      cout << "NO\n";
    }
    else{
      ll s2 = 0;
      for(int i=0; i<N; i++){
        s2 += W[i];
        if(s2 == X){
          swap(W[i], W[i+1]);
          break;
        }
      }
      cout << "YES\n";
      for(int x : W)
        cout << x << " ";
      cout << "\n";
    }
  }
}