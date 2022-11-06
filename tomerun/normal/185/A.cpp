#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
typedef long long ll;

typedef vector<ll> vl;
typedef vector<vl> mat;
const int MOD = 1000000007;

mat mul(mat& m1, mat& m2){
  mat ans(2);
  ans[0].push_back((m1[0][0]*m2[0][0] + m1[0][1]*m2[1][0] ) % MOD);
  ans[0].push_back((m1[0][0]*m2[0][1] + m1[0][1]*m2[1][1] ) % MOD);
  ans[1].push_back((m1[1][0]*m2[0][0] + m1[1][1]*m2[1][0] ) % MOD);
  ans[1].push_back((m1[1][0]*m2[0][1] + m1[1][1]*m2[1][1] ) % MOD);
  return ans;
}

mat pow(mat m, ll p){
  mat ans(2);
  ans[0].push_back(1);
  ans[0].push_back(0);
  ans[1].push_back(0);
  ans[1].push_back(1);
  while(p > 0) {
    if (p % 2 != 0) {
      ans = mul(ans, m);
    }
    m = mul(m, m);
    p /= 2;
  }
  return ans;
}

int main(){
  ll n;
  cin >> n;
  mat coef(2);
  coef[0].push_back(3);
  coef[0].push_back(1);
  coef[1].push_back(1);
  coef[1].push_back(3);
  mat ans = pow(coef, n);
  cout << ans[0][0] << endl;
  return 0;
}