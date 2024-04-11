#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int Q, N;
vector<int> A;
vector<int> sm;
vector<int> M;

int main(){
  cin >> Q;
  while(Q--){
    cin >> N;
    A.resize(N);
    sm.resize(N+1);
    M.resize(N+1);
    fill(sm.begin(), sm.end(), -1);
    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    set<int> S;
    for(int i=N-1; i>=0; i--){
      S.insert(A[i]);
      auto it = S.lower_bound(A[i]);
      if(it != S.begin()){
        it--;
        sm[A[i]] = max(sm[A[i]], *it);
      }
    }
    /*
    cout << "sm: ";
    for(int i=0; i<=N; i++){
      cout << sm[i] << " ";
    }
    cout << endl;
    */
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    fill(M.begin(), M.end(), -1);
    for(int i=0; i<sz(A); i++){
      M[A[i]] = i;
    }
    int best = 0;
    for(int i=1; i<=N; i++){
      if(M[i] == -1)
        continue;
      if(M[i] == 0)
        sm[i] = 1;
      else if(sm[i] == -1){
        sm[i] = 1 + sm[A[M[i]-1]];
      }
      else if(M[sm[i]] < M[i]-1){
        sm[i] = min(1 + sm[A[M[i]-1]], M[i] - M[sm[i]]);
      }
      else{
        sm[i] = 1;
      }
      best = max(best, sm[i]);
    }
    cout << sz(A)-best << endl;
  }

  return 0;
}