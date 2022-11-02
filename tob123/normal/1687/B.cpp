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

int N, M;

ll ask(string s){
  ll res;
  cout << "? " << s << endl;
  cin >> res;
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  vector<pair<ll,int>> w(M);
  string S;
  for(int i=0; i<M; i++)
    S.push_back('0');
  for(int i=0; i<M; i++){
    S[i] = '1';
    w[i] = make_pair(ask(S), i);
    S[i] = '0';
  }
  sort(w.begin(), w.end());
  ll lst = 0;
  for(auto [ww, ind] : w){
    S[ind] = '1';
    ll cur = ask(S);
    if(cur == lst + ww){
      lst = cur;
    }
    else
      S[ind] = '0';
  }
  cout << "! " << lst << endl;
}