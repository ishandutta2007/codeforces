#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll N, K;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> PQ;
vector<ll> A, B;
vector<ll> A2;

void printPQ(){
  vector<pair<ll, int>> R;
  while(!PQ.empty()){
    auto p = PQ.top();
    R.push_back(p);
    cout << p.first << " " << p.second << endl;
    PQ.pop();
  }
  for(auto x : R)
    PQ.push(x);
}

bool pos(ll x){
  //cout << endl << "x: " << x << endl;
  PQ = priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>();
  for(int i=0; i<N; i++){
    A2[i] = A[i];
    PQ.push(make_pair(A[i]/B[i], i));
  }
  //printPQ();
  for(ll i=0; i<K; i++){
    auto p = PQ.top();
    if(p.first < i)
      return false;
    PQ.pop();
    A2[p.second] += x;
    PQ.push(make_pair(A2[p.second]/B[p.second], p.second));
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  A.resize(N);
  B.resize(N);
  A2.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  for(int i=0; i<N; i++){
    cin >> B[i];
  }

  ll l = 0, r=4e12;
  while(l < r){
    ll m = (l+r)/2;
    if(pos(m))
      r = m;
    else
      l = m+1;
  }

  if(l == ((ll)4e12))
    cout << -1 << endl;
  else
    cout << l << endl;

  return 0;
}