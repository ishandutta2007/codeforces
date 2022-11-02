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
  int T, N, X;
  cin >> T;
  while(T--){
    cin >> N >> X;
    vector<int> A(N);
    int cnt[2] = {0,0};
    for(int& x : A){
      cin >> x;
      cnt[x&1]++;
    }
    if(cnt[1] > 0){
      if(cnt[1] == N && (X&1)==0){
        cout << "No\n";
      }
      else if(N == X && (cnt[1]&1)==0){
        cout << "No\n";
      }
      else{
        cout << "Yes\n";
      }
    }
    else
      cout << "No\n";
  }
}