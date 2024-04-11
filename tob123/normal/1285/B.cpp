#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e5+10;

int N, T;
ll A[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    ll sum = 0;
    ll s2 = 0;
    bool f = false;
    ll best = -1e16;
    for(int i=0; i<N; i++){
      cin >> A[i];
      sum += A[i];
      s2 += A[i];
      if(f || i < N-1){
        best = max(best, s2);
      }
      if(s2 <= 0){
        s2 = 0;
        f = true;
      }
    }
    if(best >= sum){
      cout << "NO\n";
    }
    else{
      cout << "YES\n";
    }

  }

  return 0;
}