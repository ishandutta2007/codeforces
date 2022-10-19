#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
const int MAX = 4e4;

int A[N], n;

map <int, int> who, DP;

int solve(int x) {
  if(DP.count(x)) return DP[x];
  DP[x] = 0;
  bool tmp[34] = {0};
  for(int i = 1; i < 31; ++ i) {
    if(x >= (1 << i)) {
      //cerr << x << " " << ((x >> i) | (x & ((1 << i) - 1))) << " " << i <<  endl;
      tmp[solve((x >> i) | (x & ((1 << i) - 1)))] = 1;
    }
  }
  while(tmp[DP[x]]) ++ DP[x];
  return DP[x];
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; ++ i) {
    scanf("%d", &A[i]);
    for(int j = 2; j <= MAX; ++ j) {
      if(A[i] % j == 0) {
	int cnt = 0;
	while(A[i] % j == 0) A[i] /= j, ++ cnt;
	who[j] |= (1 << cnt);
      }
    }
    if(A[i] != 1) who[A[i]] |= 2;
  }

  int ans = 0;
  
  for(auto V : who) {
    ans ^= solve(V.second);
  }
  
  if(ans) puts("Mojtaba");
  else puts("Arpa");
}