#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

const int n = 5e5 + 10;

int N, M;
int nc[n];
vector<pair<int,int>> A;
int lToI[n];
//rToI[n], 
vector<int> L, R;
pair<int,int> iToC[n];
int J[20][n];

int main(){
  cin >> N >> M;
  A.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i].first >> A[i].second;
    A[i].second *= -1;
  }
  sort(A.begin(), A.end());
  int to = 0;
  int cnt = 0;
  //R.push_back(0);
  for(int i=0; i<N; i++){
    if(-A[i].second <= to)
      continue;
    if(A[i].first > to){
      for(int x=to; x<A[i].first; x++){
        nc[x+1] = 1;
      }
    }
    to = -A[i].second;
    L.push_back(A[i].first);
    //R.push_back(-A[i].second);
    iToC[cnt] = make_pair(A[i].first, -A[i].second);
    cnt++;
  }
  L.push_back(n-1);
  for(int i=0; i<sz(L)-1; i++){
    for(int j=L[i]; j<L[i+1]; j++){
      lToI[j] = i;
    }
  }
  /*
  for(int i=sz(R)-1; i>0; i--){
    for(int j=R[i]; j>R[i-1]; j--){
      rToI[j] = i;
    }
  }
  */
  for(int i=to; i<n-1; i++){
    nc[i+1] = 1;
  }
  for(int i=1; i<n; i++){
    nc[i] += nc[i-1];
  }
  for(int i=0; i<cnt; i++){
    J[0][i] = lToI[iToC[i].second];
  }
  for(int i=1; i<20; i++){
    for(int j=0; j<cnt; j++){
      J[i][j] = J[i-1][J[i-1][j]];
    }
  }
  int l, r;
  for(int i=0; i<M; i++){
    cin >> l >> r;
    int notC = nc[r]-nc[l];
    if(notC){
      cout << -1 << "\n";
    }
    else{
      /*
      int i1 = * (S1.lower_bound(-l));
      int i2 = * (S2.lower_bound(r));
      int res = rToI[i2] - lToI[-i1] + 1;
      */
      int res = 1;
      int st = lToI[l];
      for(int i=19; i>=0; i--){
        if(iToC[J[i][st]].second < r){
          res += 1<<i;
          st = J[i][st];
        }
      }
      if(iToC[st].second < r)
        res++;
      cout << res << "\n";
    }
  }

  return 0;
}