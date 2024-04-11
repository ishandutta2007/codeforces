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

set<int> P;
multiset<int> D;

void insP(int x){
  if(sz(P) == 0){
    P.insert(x);
    return;
  }
  auto it = P.lower_bound(x);
  if(it == P.begin()){
    D.insert(*it - x);
  }
  else if(it == P.end()){
    it--;
    D.insert(x - *it);
  }
  else{
    auto it2 = it;
    it2--;
    auto it3 = D.find(*it - *it2);
    D.erase(it3);
    D.insert(x - *it2);
    D.insert(*it - x);
  }
  P.insert(x);
}

void delP(int x){
  P.erase(x);
  if(sz(D) == 0){
    return;
  }
  auto it = P.lower_bound(x);
  if(it == P.begin()){
    auto it2 = D.find(*it - x);
    D.erase(it2);
  }
  else if(it == P.end()){
    it--;
    auto it2 = D.find(x - *it);
    D.erase(it2);
  }
  else{
    auto it2 = it;
    it2--;
    auto it3 = D.find(*it - x);
    D.erase(it3);
    it3 = D.find(x - *it2);
    D.erase(it3);
    D.insert(*it - *it2);
  }
}

int curAns(){
  if(sz(P) < 3)
    return 0;
  int d1 = *(--P.end()) - *P.begin();
  int d2 = *(--D.end());
  return d1 - d2;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, Q;
  cin >> N >> Q;
  for(int i=0; i<N; i++){
    int p;
    cin >> p;
    insP(p);
  }
  cout << curAns() << "\n";
  for(int i=0; i<Q; i++){
    int x, t;
    cin >> t >> x;
    if(t){
      insP(x);
    }
    else{
      delP(x);
    }
    cout << curAns() << "\n";
  }
}