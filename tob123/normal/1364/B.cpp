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
  cout << "}" << endl;
}

int sign(int x){
  return x / abs(x);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    vector<int> P;
    vector<int> res;
    for(int i=0; i<N; i++){
      int x;
      cin >> x;
      if(i == 0 || x != P.back())
        P.push_back(x);
    }
    if(sz(P) <= 1)
      cout << 0 << "\n";
    else{
      res.push_back(P[0]);
      res.push_back(P[1]);
      for(int i=2; i<sz(P); i++){
        if(sign(P[i]-res.back()) == sign(res.back()-res[sz(res)-2]))
          res[sz(res)-1] = P[i];
        else
          res.push_back(P[i]);
      }
      cout << sz(res) << "\n";
      for(int x : res)
        cout << x << " ";
      cout << "\n";
    }
  }
}