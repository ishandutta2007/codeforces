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

int N;
vector<int> A;

ll query(vector<int>& x){
  if(sz(x) == 0)
    return 0;
  cout << "? " << sz(x);
  for(int y : x){
    cout << " " << y;
  }
  cout << endl;
  ll res;
  cin >> res;
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for(int i=0; i<(1<<13); i++){
    if(__builtin_popcount(i) == 6)
      A.push_back(i);
  }
  cin >> N;
  vector<ll> res(13);
  for(int i=0; i<13; i++){
    vector<int> cur;
    for(int j=0; j<N; j++){
      if(A[j]&(1<<i))
        cur.push_back(j+1);
    }
    res[i] = query(cur);
  }
  cout << "!";
  for(int i=0; i<N; i++){
    ll cur = 0;
    for(int j=0; j<13; j++){
      if(((1<<j)&A[i]) == 0)
        cur |= res[j];
    }
    cout << " " << cur;
  }
  cout << endl;
}