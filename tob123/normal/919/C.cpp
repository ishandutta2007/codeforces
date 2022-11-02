#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int cntH[2002];

int main(){
  ios_base::sync_with_stdio(false);
  cin >> N >> M >> K;
  char c;
  int res = 0;
  for(int i=1; i<=N; i++){
    int cnt = 0;
    for(int j=1; j<=M; j++){
      cin >> c;
      if(c == '.'){
        cnt++;
        cntH[j]++;
        if(cnt >= K){
          res++;
        }
        if(cntH[j] >= K){
          res++;
        }
      }
      else{
        cnt = 0;
        cntH[j] = 0;
      }
    }
  }

  if(K == 1){
    cout << res/2 << endl;
  }
  else{
    cout << res << endl;
  }

  return 0;
}