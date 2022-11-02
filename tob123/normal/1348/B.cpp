#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T, N, K;
vector<int> A;



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> K;
    A.resize(N);
    set<int> S;
    for(int i=0; i<N; i++){
      cin >> A[i];
      S.insert(A[i]);
    }
    if(sz(S) > K){
      cout << -1 << endl;
    }
    else{
      for(int i=1; i<=N; i++){
        if(sz(S) < K)
          S.insert(i);
      }
      cout << sz(S) * N << endl;
      for(int i=0; i<N; i++){
        for(int x : S)
          cout << x << " ";
      }
      cout << "\n";
    }
  }
}