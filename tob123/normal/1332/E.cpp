#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<ll>> matr;

ll MOD = 998244353;
ll N, M, L, R;

matr mult(matr m1, matr m2){
  matr erg = vector<vector<ll>>(2, vector<ll>(2, 0));
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      for(int k=0; k<2; k++){
        (erg[i][j] += m1[i][k] * m2[k][j]) %= MOD;
      }
    }
  }
  return erg;
}

matr exp(matr b, ll e){
  if(e == 1)
    return b;
  matr erg = exp(b, e/2);
  erg = mult(erg, erg);
  if(e%2)
    erg = mult(erg, b);
  return erg;
}

ll exp2(ll b, ll e){
  if(e == 1)
    return b;
  ll x = exp2(b, e/2);
  x *= x;
  x %= MOD;
  if(e%2)
    x *= b;
  x %= MOD;
  return x;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M >> L >> R;
  ll v1=(R-L+1)/2, v2=(R-L+2)/2; //v1: one less
  if(L % 2 == 0)
    swap(v1, v2);
  matr base = {{v1, v2}, {v2, v1}}; //v1: stay, v2: switch
  matr erg = exp(base, N*M); 
  ll res = erg[0][0];
  if(N*M%2){
    res = erg[0][0] + erg[1][0];
    res %= MOD;
  }
  cout << res << endl;
  /*
  cout << erg[1][0] << endl;
  cout << (erg[0][0]+erg[1][0])%MOD << endl;
  cout << exp2(R-L+1, N*M) << endl;
  */

  return 0;
}