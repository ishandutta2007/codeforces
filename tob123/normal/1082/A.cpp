#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e11;

ll T, N, X, Y, D;

int main(){
  cin >> T;
  for(int t=1; t<=T; t++){
    cin >> N >> X >> Y >> D;
    Y--;
    X--;
    ll best = INF;
    if(abs(Y-X) % D == 0){
      best = abs(Y-X) / D;
    }
    if(Y % D == 0){
      best = min(best, Y/D + (X+D-1)/D);
    }
    if((N-1-Y)%D == 0){
      best = min(best, (N-1-Y)/D + (N-1-X+D-1)/D);
    }
    if(best == INF)
      best = -1;
    cout << best << endl;
  }

  return 0;
}