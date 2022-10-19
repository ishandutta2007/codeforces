#include <bits/stdc++.h>
using namespace std;

const int N = 111111;

#define lowbit(x) (x & (-x))

int S[N] , n , m , l , r  , cnt[N] , A[N];

void add(int x , int v) {
  ++ x;
  for(int i = x;i < N;i += lowbit(i))
    S[i] = max(S[i] , v);
}

int sum(int x) {
  ++ x;
  int res = 0;
  for(int i = x;i;i -= lowbit(i))
    res = max(res , S[i]);
  return res;
}

int main() {
  scanf("%d%d" , &n , &m);
  for(int i = 1;i <= n;++ i) {
    scanf("%d%d" , &l , &r);
    ++ cnt[l]; -- cnt[r + 1];
  }
  for(int i = 1;i <= m;++ i)
    cnt[i] += cnt[i - 1];
  int ans = 0;
  for(int i = 1;i <= m;++ i) {
    A[i] = sum(cnt[i]);
    add(cnt[i] , A[i] + 1);
  }
  memset(S , 0 , sizeof(S));
  for(int i = m;i >= 1;-- i) {
    int now = sum(cnt[i]);
    ans = max(ans , now + 1 + A[i]);
    add(cnt[i] , now + 1);
  }
  cout << ans << endl;
}