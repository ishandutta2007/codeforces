#include <bits/stdc++.h>
using namespace std;

const int n = 5e5+5;

int N, C, cntC;
vector<int> X[n];
int P[n];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N >> C;
  for(int i=1; i<=N; i++){
    int a;
    cin >> a;
    if(a == C){
      P[i]++;
      cntC++;
    }
    else{
      X[a].push_back(i);
    }
  }
  for(int i=1; i<=N+1; i++){
    P[i] += P[i-1];
  }
  int best = 0;
  for(int i=0; i<n; i++){
    if(X[i].size() > 0){
      vector<int> r;
      r.push_back(1);
      int sum = 0;
      for(int j=1; j<X[i].size(); j++){
        r.push_back(- (P[X[i][j]] - P[X[i][j-1]]));
        r.push_back(1);
      }
      for(int j=0; j<r.size(); j++){
        sum = max(0, sum);
        sum += r[j];
        best = max(best, sum);
      }
    }
  }

  cout << best+cntC << endl;

  return 0;
}