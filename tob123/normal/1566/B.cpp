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
  string S;
  cin >> T;
  while(T--){
    cin >> S;
    int first0 = sz(S);
    int last0 = -1;
    for(int i=0; i<sz(S); i++){
      if(S[i] == '0'){
        first0 = min(first0, i);
        last0 = max(last0, i);
      }
    }
    if(first0 == sz(S)){
      cout << 0 << "\n";
    }
    else{
      bool w = true;
      for(int i=first0; i<=last0; i++){
        w &= S[i] == '0';
      }
      if(w){
        cout << 1 << "\n";
      }
      else{
        cout << 2 << "\n";
      }
    }
  }
}