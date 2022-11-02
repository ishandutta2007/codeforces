#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

ll Q, N, x, y, a, b, K;
vector<ll> P;

ll calc(int m){
  ll mult = a*b/__gcd(a,b);
  ll res = 0;
  for(int i=0; i<m/mult; i++){
    res += P[i]/100 * (x+y);
  }
  //cout << res << " ";
  for(int i=m/mult; i<m/a; i++){
    res += P[i]/100 * x;
  }
  //cout << res << " ";
  for(int i=m/a; i<m/a + m/b - m/mult; i++){
    res += P[i]/100 * y;
  }
  return res;
}

int main(){
  cin >> Q;
  while(Q--){
    cin >> N;
    P.resize(N);
    for(int i=0; i<N; i++){
      cin >> P[i];
    }
    cin >> x >> a >> y >> b;
    if(x < y){
      swap(x,y);
      swap(a,b);
    }
    cin >> K;
    sort(P.rbegin(), P.rend());
    /*
    for(int i=0; i<=N; i++){
      cout << i << ": " << calc(i) << endl;
    }
    */
    int l = 0, r = N;
    while(l < r){
      int m = (l+r)/2;
      ll res = calc(m);
      if(res >= K){
        r = m;
      }
      else{
        l = m+1;
      }
    }
    if(calc(l) < K){
      cout << -1 << endl;
    }
    else{
      cout << l << endl;
    }
  }

  return 0;
}