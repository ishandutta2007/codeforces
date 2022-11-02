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

int T, N;
string S;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> S;
    bool l = true, r = true;
    for(int i=0; i<N; i++){
      if(S[i] == '>'){
        l = false;
      }
      else if(S[i] == '<'){
        r = false;
      }
    }
    if(l || r){
      cout << N << "\n";
    }
    else{
      int cnt = 0;
      for(int i=0; i<N; i++){
        if(S[i] == '-' || S[(i+1)%N] == '-'){
          cnt++;
        }
      }
      cout << cnt << "\n";
    }
  }
}