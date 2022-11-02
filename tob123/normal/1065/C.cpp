#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, K;
ll H[200005];

int main(){
  cin >> N >> K;
  for(int i=0; i<N; i++){
    int h;
    cin >> h;
    H[h]++;
  }
  ll res = 0;
  ll curS = K;
  for(int i=2e5+2; i>0; i--){
    curS += H[i+1];
    if(curS > K){
      curS = H[i+1];
      res++;
    }
    H[i]+=H[i+1];
    if(H[i] == N){
      cout << res << endl;
      return 0;
    }
  }
  
  return 0;
}