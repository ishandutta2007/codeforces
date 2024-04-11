#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, K;
priority_queue<ll,vector<ll>,greater<ll>> PQ;

int main(){
  cin >> N >> K;
  for(int i=0; i<N; i++){
    ll a;
    cin >> a;
    PQ.push(a);
  }

  ll sum = 0;
  //cout << PQ.top() << endl;

  for(int i=0; i<K; i++){
    while(!PQ.empty() && PQ.top()-sum <= 0)
      PQ.pop();
    if(PQ.empty()){
      cout << 0 << "\n";
    }
    else{
      ll cur = PQ.top();
      //cout << cur << ", " << sum << endl;
      PQ.pop();
      cout << cur-sum << endl;
      sum += cur-sum;
      cur = cur + cur - sum;
      PQ.push(cur);
    }
  }

  return 0;
}