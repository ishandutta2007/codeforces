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

void solve(int n, int f=1){
  if(n == 4){
    int x = f;
    cout << 2*f << " " << x << " " << x << "\n";
  }
  else if(n%2){
    int x = n/2 * f;
    cout << f << " " << x << " " << x << "\n";
  }
  else{
    solve(n/2, 2*f);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T, N, K;
  cin >> T;
  while(T--){
    cin >> N >> K;
    for(int i=0; i<K-3; i++)
      cout << "1 ";
    solve(N-K+3);
  }
}