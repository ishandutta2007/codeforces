#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 3e5+10;

int Q, N;
int A[n];
map<int,int> M[n];
int cnt[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> Q;
  while(Q--){
    cin >> N;
    for(int i=0; i<=N; i++){
      cnt[i] = 0;
      M[i].clear();
    }
    A[N] = 0;
    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    for(int i=N-1; i>=0; i--){
      int nxt = -1;
      if(A[i] == A[i+1]){
        nxt = i+2;
      }
      else{
        if(M[i+1].count(A[i])){
          nxt = M[i+1][A[i]]+1;
        }
        else{
          nxt = -1;
        }
      }
      if(nxt == -1){
        cnt[i] = 0;
      }
      else{
        cnt[i] = 1 + cnt[nxt];
        M[i] = move(M[nxt]);
      }
      M[i][A[i]] = i;
    }
    ll sum = 0;
    for(int i=0; i<N; i++){
      //cout << i << ": " << cnt[i] << endl;
      if(cnt[i] > 0)
        sum += cnt[i];
    }
    cout << sum << "\n";
  }

  return 0;
}