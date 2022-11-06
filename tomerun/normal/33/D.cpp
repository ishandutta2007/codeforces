#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cmath>
//#include "../myutil.hpp"

using namespace std;
const int INF = 1000000000;

int kx[1000];
int ky[1000];
bool in[1000][1000];


int main(){
  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 0; i < n; ++i) {
    int x,y;
    cin >> x >> y;
    kx[i] = x;
    ky[i] = y;
  }
  for(int i = 0; i < m; ++i) {
    long long r,x,y;
    cin >> r >> x >> y;
    for(int j = 0; j < n; ++j) {
      in[j][i] = (kx[j] - x) * (kx[j] - x) + (ky[j] - y) * (ky[j] - y) < r*r;
    }
  }
  int a,b;
  for(int i = 0; i < k; ++i) {
    scanf("%d %d", &a, &b);
    --a;
    --b;
    int ans = 0;
    for(int j = 0; j < m; ++j) {
      if(in[a][j] ^ in[b][j]) ++ans;
    }
    printf("%d\n", ans);
  }

  return 0;
}