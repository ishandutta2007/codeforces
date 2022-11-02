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
  int T, N, M, X, Y;
  cin >> T;
  while(T--){
    cin >> N >> M >> X >> Y;
    Y = min(Y, 2*X);
    ll c = 0;
    for(int i=0; i<N;i++){
      string S;
      cin >> S;
      int s = 0;
      for(char ch : S){
        if(ch == '.'){
          s++;
        }
        else{
          c += s/2*Y + s%2*X;
          s = 0;
        }
      }
      c += s/2*Y + s%2*X;
    }
    cout << c << endl;
  }
}