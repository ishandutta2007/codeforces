#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 4000;

int T, N, M, K;
int A[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    K = min(M-1, K);
    for(int i=0; i<M; i++){
      A[i] = max(A[i], A[i+N-M]);
      //cerr << A[i] << " ";
    }
    //cerr << endl;
    int res = 0;
    for(int j=0; j<=K; j++){
      int mi = A[j];
      for(int i=0; i<=M-K-1; i++){
        mi = min(mi, A[j+i]);
      }
      //cerr << mi << " ";
      res = max(res, mi);
    }
    //cerr << endl;
    cout << res << "\n";
    //cerr << endl;
  }


  return 0;
}