#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<ll,ll> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

pii iv(ll a, ll b){
  return make_pair(min(a,b), max(a,b));
}
pii comb(pii a, pii b){
  if(b.second < a.second)
    swap(a, b);
  return make_pair(max(0ll, b.first-a.second), b.second-a.first);
}
ll div(pii x){
  return x.second-x.first;
}
ll gap(pii a, pii b){
  if(a.first > b.first)
    swap(a, b);
  if(a.second >= b.first)
    return 0;
  else
    return b.first-a.second;
}

ll test(vector<pii> P){
  //print(P);
  ll res = 0;
  pii x1 = iv(P[0].first, P[1].first);
  pii x2 = iv(P[2].first, P[3].first);
  pii resX = comb(x1, x2);
  res += div(x1) + div(x2);
  pii y1 = iv(P[0].second, P[3].second);
  pii y2 = iv(P[2].second, P[1].second);
  pii resY = comb(y1, y2);
  res += div(y1) + div(y2);
  //print(resX); cout << "\n";
  //print(resY); cout << "\n";
  res += gap(resX, resY)*2;
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    vector<pii> P(4);
    for(int i=0; i<4; i++){
      cin >> P[i].first >> P[i].second;
    }
    sort(P.begin(), P.end());
    ll curBest = test(P);
    while(next_permutation(P.begin(), P.end())){
      curBest = min(curBest, test(P));
    }
    cout << curBest << "\n";
  }
}