#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, K;
vector<pair<ll,ll>> A;

int main(){
  cin >> N >> K;
  A.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i].second >> A[i].first;
  }

  priority_queue<ll, vector<ll>, greater<ll>> Q;
  ll best = 0;
  ll sum = 0;
  sort(A.begin(), A.end());
  for(int i=N-1; i>=N-K; i--){
    sum += A[i].second;
    best = max(best, sum * A[i].first);
    Q.push(A[i].second);
  }
  for(int i=N-K-1; i>=0; i--){
    sum += A[i].second;
    Q.push(A[i].second);
    sum -= Q.top();
    Q.pop();
    best = max(best, sum * A[i].first);
  }

  cout << best << endl;

  return 0;
}