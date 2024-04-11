#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int n = 1e5+10;

int N, M;
vector<int> S[n];
vector<int> R[n];

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N >> M;
  for(int i=0; i<N; i++){
    int s, r;
    cin >> s >> r;
    S[s].push_back(r);
  }
  for(int i=0; i<=M; i++){
    sort(S[i].rbegin(), S[i].rend());
    for(int j=1; j<S[i].size(); j++){
      S[i][j] += S[i][j-1];
    }
    for(int j=0; j<S[i].size(); j++){
      R[j].push_back(S[i][j]);
    }
  }
  ll best = 0;
  for(int i=0; i<=N; i++){
    ll sum = 0;
    for(int j=0; j<R[i].size(); j++){
      if(R[i][j] > 0)
        sum += R[i][j];
    }
    best = max(best, sum);
  }

  cout << best << endl;

  return 0;
}