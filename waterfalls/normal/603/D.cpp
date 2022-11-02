#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 2005;
int N, A, B, C;
ll X[MAXN], Y[MAXN], Z[MAXN], res;

int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A >> B >> C;
    X[i] = A * C;
    Y[i] = B * C;
    Z[i] = A * A + B * B;
  }
  for(int i = 0; i < N; i++){
    map<ld,int> freq;
    int same = 0;
    for(int j = i + 1; j < N; j++){
      ll u = X[i] * Z[j] - X[j] * Z[i];
      ll v = Y[i] * Z[j] - Y[j] * Z[i];
      if (u==0 && v==0) same+=1;
      else {
        ll g = __gcd(u,v);
        u/=g; v/=g;
        freq[(ld) u/v]+=1;
      }
    }
    res+=same*(same-1)/2;
    for (auto j: freq) {
      res+=j.second*(j.second-1)/2;
      res+=j.second*same;
    }
  }
  cout << res << '\n';
}