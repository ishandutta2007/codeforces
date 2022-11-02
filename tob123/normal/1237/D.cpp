#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

const int n = 1e5 + 10;

typedef long long ll;
typedef pair<int,int> pii;

int N;
set<int> S;
vector<pii> A;
int M[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A.resize(N);
  for(int i=0; i<N; i++){
    cin >> A[i].first;
    A[i].second = i;
    M[i] = 3*N;
  }
  sort(A.rbegin(), A.rend());
  int l = 0;
  for(int r=0; r<N; r++){
    while(l < N && A[l].first > 2*A[r].first){
      S.insert(A[l].second);
      S.insert(A[l].second+N);
      l++;
    }
    auto it = S.lower_bound(A[r].second+N);
    if(it != S.begin()){
      it--;
      int ind = *it;
      if(ind >= N)
        ind -= N;
      int curi = A[r].second;
      if(curi < ind)
        curi += N;
      M[ind] = min(M[ind], curi-ind);
    }
  }
  for(int i=2*N-1; i>=0; i--){
    M[i%N] = min(M[i%N], 1+M[(i+1)%N]);
  }
  for(int i=0; i<N; i++){
    cout << (M[i]==3*N ? -1 : M[i]) << " ";
  }
  cout << endl;

  return 0;
}