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
    bool pos = false;
    A.resize(N);
    for(int i=0; i<N; i++){
      cin >> A[i];
      if(A[i] == K){
        pos = true;
      }
      A[i] = A[i] >= K ? 1 : -1;
    }
    int sum = A[0];
    int best = 0;
    for(int i=1; i<N; i++){
      sum += A[i];
      best = max(best, sum);
      sum = max(sum, A[i]);
    }
    if(pos && (N==1 || best>0)){
      cout << "yes\n";
    }
    else{
      cout << "no\n";
    }
  }
}