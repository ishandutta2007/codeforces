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
  int T, N;
  cin >> T;
  while(T--){
    cin >> N;
    vector<int> A(N);
    vector<int> cnt(31);
    for(int i=0; i<N; i++){
      cin >> A[i];
      for(int j=0; j<31; j++){
        if(A[i] & (1<<j))
          cnt[j]++;
      }
    }
    for(int j=30; j>=0; j--){
      if(cnt[j] % 2){
        if(cnt[j] / 2 % 2){
          if(N % 2)
            cout << "LOSE\n";
          else
            cout << "WIN\n";
        }
        else{
          cout << "WIN\n";
        }
        goto END;
      }
    }
    cout << "DRAW\n";
END: ;
  }
}