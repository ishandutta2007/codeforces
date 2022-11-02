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
    int N;
    string S;
    cin >> N;
    cin >> S;
    for(int i=1; i<N; i++){
      if(S[i] != '?')
        continue;
      if(S[i-1] == 'R')
        S[i] = 'B';
      if(S[i-1] == 'B')
        S[i] = 'R';
    }
    if(S[N-1] == '?')
      S[N-1] = 'R';
    for(int i=N-2; i>=0; i--){
      if(S[i] != '?')
        continue;
      if(S[i+1] == 'R')
        S[i] = 'B';
      if(S[i+1] == 'B')
        S[i] = 'R';
    }
    cout << S << endl;
  }
}