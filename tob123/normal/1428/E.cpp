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

ll cost(ll l, ll z){
  ll l1 = l/z;
  ll l2 = l1+1;
  ll cnt2 = l%z;
  ll cnt1 = z-cnt2;
  return l1*l1*cnt1 + l2*l2*cnt2;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  /*
  cout << cost(5, 1) << endl;
  cout << cost(5, 2) << endl;
  cout << cost(5, 3) << endl;
  cout << cost(5, 4) << endl;
  cout << cost(5, 5) << endl;
  cout << cost(5, 6) << endl;
  cout << cost(5, 10) << endl;
  cout << endl;
  */
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  vector<ll> cnt(N);
  ll res = 0;
  priority_queue<pair<ll,ll>> PQ;
  for(int i=0; i<N; i++){
    cin >> A[i];
    res += A[i] * A[i];
    cnt[i] = 1;
    PQ.push(make_pair(cost(A[i], 1)-cost(A[i],2), i));
  }
  K -= N;
  while(K--){
    auto [c, ind] = PQ.top(); PQ.pop();
    res -= c;
    cnt[ind]++;
    PQ.push(make_pair(cost(A[ind], cnt[ind])-cost(A[ind], cnt[ind]+1), ind));
  }
  cout << res << "\n";
}