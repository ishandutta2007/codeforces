#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 110;

int N, M;
int A[n][n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;
  for(int i=0; i<M; i++){
    for(int j=0; j<N; j++){
      cin >> A[j][i];
    }
  }
  int bestCnt = N+M+10;
  vector<int> best, res;
  for(int i=0; i<N-1; i++){
    int sum = 0;
    vector<pii> X;
    for(int j=0; j<M; j++){
      sum += A[i][j] - A[N-1][j];
      X.push_back(make_pair(A[i][j]-A[N-1][j], j));
    }
    sort(X.begin(), X.end());
    vector<int> res;
    for(int x=0; sum<0; x++){
      sum -= X[x].first;
      res.push_back(X[x].second);
    }
    if(bestCnt > sz(res)){
      bestCnt = sz(res);
      best = move(res);
    }
  }
  cout << sz(best) << "\n";
  for(int x : best){
    cout << (x+1) << " ";
  }
  cout << "\n";

  return 0;
}