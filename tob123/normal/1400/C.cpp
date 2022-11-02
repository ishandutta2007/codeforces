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
  int T, x;
  string S;
  cin >> T;
  while(T--){
    cin >> S >> x;
    string R(sz(S), '2');
    int N = sz(S);
    for(int i=0; i<N; i++){
      if(i < x){
        R[i] = i+x<N ? S[i+x] : '1';
      }
      else if(i >= N-x){
        R[i] = i-x >= 0 ? S[i-x] : '1';
      }
      else{
        if(S[i-x] == '1' && S[i+x] == '1')
          R[i] = '1';
        else
          R[i] = '0';
      }
    }
    string S2(N, '2');
    for(int i=0; i<N; i++){
      if(i+x < N && R[i+x] == '1')
        S2[i] = '1';
      else if(i-x >= 0 && R[i-x] == '1')
        S2[i] = '1';
      else
        S2[i] = '0';
    }
    if(S == S2){
      cout << R << "\n";
    }
    else
      cout << -1 << "\n";
  }
}