#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 22) + 1;

queue <int> q;

int ok[N] , vis[N] , n , m , x;

void solve(int x) {
  if(vis[x])
    return;
  vis[x] = 1;
  int mask = (1 << n) - 1;
  if(ok[x]) solve(mask ^ x);
  for(int i = 0;i < n;++ i) {
    if((1 << i) & x) {
      solve(x ^ (1 << i));
    }
  }
}


int main() {
  scanf("%d%d" , &n , &m);
  for(int i = 1;i <= m;++ i) {
    scanf("%d" , &x);
    ok[x] = 1;
  }
  int ans = 0;
  for(int i = 0;i < (1 << n);++ i)
    if(ok[i] && !vis[i]) {
      vis[i] = 1;
      solve(((1 << n) - 1) ^ i);
      ++ ans;
    }
  cout << ans << endl;
}