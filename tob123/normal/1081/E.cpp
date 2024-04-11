#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int n = 1e5+10;

int N;
ll D[n];
ll res[n];

ll srt(ll z){
  double res = sqrt(z);
  res += 0.2;
  return res;
}

ll notSquare(ll z){
  ll root = srt(z);
  return root*root != z;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N/2; i++){
    cin >> D[i];
  }
  ll cur = 0;
  for(int i=0; i<N/2; i++){
    cur++;
    while(notSquare(cur*cur+D[i]) && cur < ((ll) 1e6)){
      cur++;
    }
    if(cur == 1000000){
      cout << "No" << endl;
      return 0;
    }
    res[2*i] = cur*cur;
    res[2*i+1] = cur*cur+D[i];
    cur = srt(cur*cur+D[i]);
  }
  for(int i=N-1; i>0; i--){
    res[i] -= res[i-1];
  }

  cout << "Yes\n";
  for(int i=0; i<N; i++){
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
}