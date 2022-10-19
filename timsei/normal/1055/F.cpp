#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 5;

int n, x, sz, Now[N], ch[N][2], S[N], dep[N];
long long val[N], w, k, Val[N];

int build(int l, int r, long long L = 0, int w = 62) {
  int t = ++ sz;
  S[t] = r - l;
  while(1) {
    int mid = lower_bound(val + 1, val + r, L + (1LL << w)) - val;
    if(mid == r) -- w;
    else if(mid == l) L += (1LL << w), -- w;
    else {
      ch[t][0] = build(l, mid, L, w);
      ch[t][1] = build(mid, r, L + (1LL << w), w);
      break;
    }
    if(w == -1) break;
  }
  Val[t] = L;
  dep[t] = w;
  return t;
}

long long calc(int i) {
  long long ans = 0;
  for(int j = 1; j <= n; ++ j) {
    int c = (val[j] >> i) & 1;
    int p = Now[j];
    if(i == dep[Now[j]]) p = ch[Now[j]][c];
    else if(((Val[Now[j]] >> i) & 1) != c) p = 0;
    ans += S[p];
  }
  return ans;
}

int main() {
  cin >> n >> k;
  for(int i = 2; i <= n; ++ i) {
    scanf("%d%lld", &x, &w);
    val[i] = val[x] ^ w;
  }
  sort(val + 1, val + n + 1);
  int rt = build(1, n + 1);
  long long ans = 0, num = 0;
  for(int i = 1; i <= n; ++ i) Now[i] = rt;
  for(int i = 62;i >= 0; -- i) {
    long long it = calc(i);
    if(num + it >= k) {
      for(int j = 1; j <= n; ++ j) {
	int c = (val[j] >> i) & 1;
	if(i == dep[Now[j]]) Now[j] = ch[Now[j]][c];
	else if(((Val[Now[j]] >> i) & 1) != c) Now[j] = 0;
      }
    }
    else {
      num += it;
      ans |= (1LL << i);
      for(int j = 1; j <= n; ++ j) {
	int c = (val[j] >> i) & 1;
	c ^= 1;
	if(i == dep[Now[j]]) Now[j] = ch[Now[j]][c];
	else if(((Val[Now[j]] >> i) & 1) != c) Now[j] = 0;
      }
    }
  }
  //cerr << num << endl;
  cout << ans << endl;
}