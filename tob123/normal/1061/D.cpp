#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int n = 1e5+7;
const ll MOD = 1e9+7;

int N;
ll X, Y;
vector<ll> R, L;
vector<pair<ll, bool>> E;

int main(){
  cin >> N >> X >> Y;
  R.resize(N);
  L.resize(N);
  ll cost = 0;
  for(int i=0; i<N; i++){
    cin >> L[i] >> R[i];
    E.push_back({L[i], false});
    E.push_back({R[i], true});
    cost += (R[i]-L[i])*Y;
    cost %= MOD;
  }
  //cout << cost << endl;
  sort(E.begin(), E.end());
  ll tresh = X/Y; //for values > tresh -> rent new one
  stack<ll> lastRet;
  lastRet.push(-1e9);
  for(auto p : E){
    bool start = p.second;
    ll val = p.first;
    if(!start){
      if(lastRet.top() < val-tresh){
        cost += X;
        cost %= MOD;
      }
      else{
        cost += Y*(val-lastRet.top());
        cost %= MOD;
        lastRet.pop();
      }
    }
    else{
      lastRet.push(val);
    }
  }

  cout << cost << endl;

  return 0;
}