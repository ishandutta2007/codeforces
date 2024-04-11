#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T, N;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    if(N == 1){
      cout << -1 << "\n";
    }
    else{
      int qs = 2*(N-1)%3;
      if(qs == 0){
        cout << 4;
      }
      else{
        cout << 2;
      }
      for(int i=0; i<N-2; i++){
        cout << 2;
      }
      cout << 3 << "\n";
    }
  }

  return 0;
}