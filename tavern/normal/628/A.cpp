#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;

const int INF = 1e9 + 7; 

int n, b, p, ansp = 0, ansb = 0;

int main(){
  scanf("%d%d%d", &n, &b, &p);
  ansp = n * p;
  for(; n > 1; ){
    int k = 1;
    for(; k <= n; k <<= 1);
    k >>= 1;
    ansb += b * k + k / 2;
    n -= k / 2;
  }
  printf("%d %d\n", ansb, ansp);
  return 0;
}