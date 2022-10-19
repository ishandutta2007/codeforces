#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int dp[N], n, A[N];

vector <int> who;

bool cmp(int x, int y) {
  return A[x] < A[y];
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++ i)
    scanf("%d", &A[i]), who.push_back(i);
  sort(who.begin(), who.end(), cmp);
  for(int i = who.size() - 1; i >= 0; -- i) {
    int V = who[i];
    for(int j = (V % A[V]); j <= n; j += A[V]) {
      if(A[j] > A[V])
	dp[V] |= (!dp[j]);
    }
  }
  for(int i = 1; i <= n; ++ i)
    if(dp[i]) putchar('A');
    else putchar('B');
}