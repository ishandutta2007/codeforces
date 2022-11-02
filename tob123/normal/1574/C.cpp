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

const ll INF = 2e18;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N;
  vector<ll> S(N);
  ll sum = 0;
  for(int i= 0; i<N; i++){
    cin >> S[i];
    sum += S[i];
  }
  sort(S.begin(), S.end());
  cin >> M;
  for(int i=0; i<M; i++){
    ll a, d;
    cin >> d >> a;
    auto it = upper_bound(S.begin(), S.end(), d);
    ll best = INF;
    if(it != S.end()){
      best = max(0ll, a-(sum-*it));
    }
    if(it != S.begin()){
      it--;
      best = min(best, d-*it + max(0ll, a-(sum-*it)));
    }
    cout << best << "\n";
  }
}