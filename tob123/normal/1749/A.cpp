#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef pair<int,int> pii;

int main(){
  int T;
  cin >> T;
  while(T--){
    int N, M;
    cin >> N >> M;
    vector<int> cntY(N), cntX(N);
    for(int i=0; i<M; i++){
      int x, y;
      cin >> x >> y;
      x--; y--;
    }
    int twy=0, twx=0;
    for(int i=0; i<N; i++){
      twy += max(0, cntY[i] - 1);
      twx += max(0, cntX[i] - 1);
    }
    bool res;
    if(twy + twx == 0){
      res = M < N;
    }
    else{
      res = twy + twx <= 1;
    }
    cout << (res ? "YES" : "NO") << endl;
  }

  return 0;
}