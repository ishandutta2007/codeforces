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
    int N, K;
    cin >> N >> K;
    set<int> left;
    for(int i=0; i<2*N; i++)
      left.insert(i);
    vector<pii> P;
    for(int i=0; i<K; i++){
      int x, y;
      cin >> x >> y;
      x--; y--;
      left.erase(x);
      left.erase(y);
      P.emplace_back(min(x,y), max(x,y));
    }
    vector<int> X;
    for(int x : left)
      X.push_back(x);
    sort(X.begin(), X.end());
    for(int i=0; i<sz(X)/2; i++){
      P.emplace_back(X[i], X[i+sz(X)/2]);
    }

    sort(P.begin(), P.end());
    int cnt = 0;
    for(int i=0; i<N; i++){
      for(int j=i+1; j<N; j++){
        if(P[i].second < P[j].second && P[i].second > P[j].first)
          cnt++;
      }
    }
    cout << cnt << "\n";
  }
}