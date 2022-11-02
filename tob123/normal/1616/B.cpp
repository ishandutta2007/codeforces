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
  int T, N;
  string S;
  cin >> T;
  while(T--){
    cin >> N >> S;
    if(N > 1 && S[0] == S[1]){
      cout << S[0] << S[0] << "\n";
      continue;
    }
    string res;
    int i;
    for(i=1; i<N; i++){
      if(S[i] > S[i-1])
        break;
    }
    for(int j=0; j<i; j++){
      res.push_back(S[j]);
    }
    for(int j=i-1; j>=0; j--){
      res.push_back(S[j]);
    }
    cout << res << "\n";
  }
}