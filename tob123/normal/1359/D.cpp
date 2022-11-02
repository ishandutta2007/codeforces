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

const int n = 1e5+10;

int N;
int A[n];
ll pl[n], pr[n];
ll cur[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=1; i<=N; i++){
    cin >> A[i];
    pl[i] = pr[i] = A[i];
  }
  for(int i=1; i<=N+1; i++){
    pl[i] += pl[i-1];
  }
  for(int i=N; i>=0; i--){
    pr[i] += pr[i+1];
  }
  ll best = 0;
  ll INF = 1e10;
  for(int x=30; x>0; x--){
    ll mx = -INF;
    for(int i=1; i<=N; i++){
      if(A[i] == x){
        cur[i] = max(0ll, mx-pr[i]);
      }
      if(A[i] > x)
        mx = -INF;
      else{
        mx = max(mx, pr[i]);
      }
    }
    mx = -INF;
    for(int i=N; i>=1; i--){
      if(A[i] == x){
        cur[i] += max(0ll, mx-pl[i]);
        best = max(best, cur[i]);
        //cout << i << ": " << cur[i] << endl;
      }
      if(A[i] > x)
        mx = -INF;
      else{
        mx = max(mx, pl[i]);
      }
    }
  }
  cout << best << endl;
}