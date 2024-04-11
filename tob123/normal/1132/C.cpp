#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int n = 5050;

int N, Q;
vector<pair<int,int>> A;
int dp1[n], dp2[n], dp3[n];

int main(){
  cin >> N >> Q;
  A.resize(Q);
  for(int i=0; i<Q; i++){
    cin >> A[i].first >> A[i].second;
    dp1[A[i].first]++;
    dp1[A[i].second+1]--;
  }

  int sum = 0;

  for(int i=1; i<=N; i++){
    dp1[i] += dp1[i-1];
    if(dp1[i] == 1)
      dp2[i]++;
    if(dp1[i] == 2)
      dp3[i]++;
    if(dp1[i])
      sum++;
  }
  for(int i=1; i<=N; i++){
    dp2[i] += dp2[i-1];
    dp3[i] += dp3[i-1];
  }

  sort(A.begin(), A.end());

  int best = 0;
  pair<int,int> i1, i2, i3;
  for(int i=0; i<Q; i++){
    for(int j=i+1; j<Q; j++){
      if(A[j].second <= A[i].second){
        i1 = {A[i].first, A[j].first};
        i2 = {A[j].first, A[j].second+1};
        i3 = {A[j].second+1, A[i].second+1};
      }
      else{
        if(A[i].second >= A[j].first){
          i1 = {A[i].first, A[j].first};
          i2 = {A[j].first, A[i].second+1};
          i3 = {A[i].second+1, A[j].second+1};
        }
        else{
          i1 = {A[i].first, A[i].second+1};
          i2 = {1, 1};
          i3 = {A[j].first, A[j].second+1};
        }
      }
      int weg = 0;
      weg += dp2[i1.second-1] - dp2[i1.first-1];
      weg += dp3[i2.second-1] - dp3[i2.first-1];
      weg += dp2[i3.second-1] - dp2[i3.first-1];
      best = max(best, sum-weg);
    }
  }

  cout << best << endl;

  return 0;
}