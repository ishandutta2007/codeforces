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
  ll N;
  cin >> N;
  string S = "codeforces";
  vector<int> cnt(sz(S),1);
  ll res = 1;
  for(int i=0; true; i++){
    if(res<N){
      res = res/cnt[i%sz(S)];
      cnt[i%sz(S)]++;
      res = res*cnt[i%sz(S)];
    }
    else
      break;
  }
  for(int i=0; i<sz(S); i++){
    for(int j=0; j<cnt[i]; j++)
      cout << S[i];
  }
  cout << endl;
}