#include <bits/stdc++.h>
using namespace std;

const int N = 2505;
const int MAX = (1 << 9) + 1;

int n , A[N] , B[N] , S[N];

unordered_map <string , int> dp[N][11];

int dfs(int x , int now , string Lsk) {
  if(x == n + 1 && Lsk == "9999") {
    return 0;
  }
  if(dp[x][now].count(Lsk))
    return dp[x][now][Lsk];
  int res = 2e9;
  string Cxt;
  for(int i = 0;i < 4;++ i)
    if(Lsk[i] != '9') {
    Cxt = Lsk;
    int L = now , R = Cxt[i] - '0';
    if(L > R)
      swap(L , R);
    for(int j = 0;j < 4;++ j) {
      if(Cxt[j] - '0' >= L && Cxt[j] - '0' <= R) {
	Cxt[j] = '9';
      }
    }
    sort(Cxt.begin() , Cxt.end());
    res = min(res , R - L + dfs(x , Lsk[i] - '0' , Cxt));
  }
  if(Lsk[3] == '9' && x != n + 1) {
    Cxt = Lsk;
    int L = now , R = A[x];
    if(L > R)
      swap(L , R);
    for(int j = 0;j < 4;++ j) {
      if(Cxt[j] - '0' >= L && Cxt[j] - '0' <= R) {
	Cxt[j] = '9';
      }
    }
    sort(Cxt.begin() , Cxt.end());
    for(int j = 0;j < 4;++ j)
      if(Cxt[j] == '9') {
	Cxt[j] = B[x] + '0';
	break;
      }
    sort(Cxt.begin() , Cxt.end());
    res = min(res , R - L + dfs(x + 1 , A[x] , Cxt));
  }
  dp[x][now][Lsk] = res;
  return res;
}

main(void) {
	scanf("%d" , &n);
	for(int i = 1;i <= n;++ i) {
		scanf("%d%d" , &A[i] , &B[i]);
		-- A[i]; -- B[i];
	}
	cout << dfs(1 , 0 , "9999") + 2 * n;
}