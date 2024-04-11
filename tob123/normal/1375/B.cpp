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
  int T, N, M;
  cin >> T;
  while(T--){
    cin >> N >> M;
    int x;
    bool pos = true;
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        cin >> x;
        if(i == 0 || i == N-1)
          x++;
        if(j == 0 || j == M-1)
          x++;
        pos &= x >= 0 && x <= 4;
      }
    }
    if(pos){
      cout << "YES\n";
      for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
          x = 4;
          if(i == 0 || i == N-1)
            x--;
          if(j == 0 || j == M-1)
            x--;
          cout << x << " ";
        }
        cout << "\n";
      }
    }
    else{
      cout << "NO\n";
    }
  }
}