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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OST;
//cout<< X.order_of_key(7)<<endl;
//cout<< *X.find_by_order(6)<<endl;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll Q, N;
  cin >> Q;
  while(Q--){
    OST I;
    string S, T;
    cin >> N >> S >> T;
    string x = S;
    sort(x.begin(), x.end());
    if(x >= T){
      cout << -1 << "\n";
      continue;
    }
    vector<set<int>> chr(26);
    for(int i=0; i<N; i++){
      I.insert(i);
      chr[S[i]-'a'].insert(i);
    }
    ll best = N*N;
    ll cur = 0;
    for(int i=0; i<N; i++){
      int curC = T[i]-'a';
      for(int j=0; j<curC; j++){
        if(sz(chr[j])){
          best = min(best, cur + (ll) I.order_of_key(*chr[j].begin()));
        }
      }
      if(sz(chr[curC])){
        auto ind = chr[curC].begin();
        cur += I.order_of_key(*ind);
        I.erase(*ind);
        chr[curC].erase(ind);
      }
      else
        break;
    }
    cout << best << "\n";
  }
}