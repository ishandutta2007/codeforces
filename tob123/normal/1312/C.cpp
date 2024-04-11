#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

ll T, N, K;
vector<ll> A;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> K;
    A.resize(N);
    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    bool nz = true;
    bool works = true;
    bool found = false;
    while(nz){
      nz = false;
      found = false;
      for(int i=0; i<N; i++){
        if(A[i]%K > 1)
          works = false;
        if(A[i]%K == 1){
          if(found)
            works = false;
          found = true;
        }
        A[i] /= K;
        if(A[i] != 0)
          nz = true;
      }
    }
    if(works)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}