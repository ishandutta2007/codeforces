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

ll INF = 1e6;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll T, N;
  cin >> T;
  while(T--){
    cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++)
      cin >> A[i];
    ll X;
    cin >> X;
    ll curS = 0;
    ll cnt = 0;
    ll res = 0;
    for(int i=0; i<N; i++){
      if(cnt > 0 && curS + A[i] < X*(cnt+1)){
        cnt = 0;
        curS = 0;
      }
      else{
        if(curS >= cnt*X){
          curS = 0;
          cnt = 0;
        }
        cnt++;
        curS += A[i];
        res++;
      }
    }
    cout << res << "\n";
  }
}