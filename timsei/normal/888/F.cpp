#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 2e3 + 5;
const int mod = 1e9 + 7;

int n , x , y;

void A(int &x , int y) {
  if((x += y) >= mod) x -= mod;
}

int a[N][N] , m , no[N][N] , ye[N][N];

int getno(int l , int r);
int getye(int l , int r);

int getno(int l , int r) {
  if(no[l][r] != -1) return no[l][r];
  int &res = no[l][r];
  if(l == r) return res = 1;
  if(l > r) return res = 0;
  if(a[l][r]) res = getye(l , r);
  else res = 0;
  for(int i = l + 1;i < r;++ i)if(a[l][i]) {
    A(res , getye(l , i) * 1ll * getno(i , r) % mod);
  }
  return res;
}

int getye(int l , int r) {
  if(ye[l][r] != -1) return ye[l][r];
  int &res = ye[l][r];
  if(l >= r) return res = 0;
  if(l + 1 == r) return res = 1;
  res = getno(l + 1 , r);
  for(int i = l + 1;i < r;++ i)if(a[l][i]) {
    A(res , getye(l , i) * 1ll * getye(i , r) % mod);
  }
  return res;
}

int dancing_on_your_road(void) {
  int ans = 0;
  for(int i = 1;i < n;++ i) if(a[n][i]) {
    A(ans , getno(1 , i) * 1ll * getye(i , n) % mod);
  }
  return ans;
}

int main(void) {
  memset(no , -1 , sizeof(no));
  memset(ye , -1 , sizeof(ye));
  scanf("%d", &n);
  for(int i = 1;i <= n;++ i) 
    for(int j = 1;j <= n;++ j) scanf("%d" , &a[i][j]) , m += a[i][j];
  m >>= 1;
  if(m < n - 1) return 0 * puts("0");
  return 0 * printf("%d\n" , dancing_on_your_road());
}