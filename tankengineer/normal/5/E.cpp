//CF 5E
/*
n<=10^6ih[i]i ji jkh[k]i j

0 i ji j 
1   
2  
3 nlognn 

4   ans 

5 TLE

6  
*/ 

#include<cstdio>
#include<algorithm>

using namespace std;

int n, h[1000005], r[1000005], l[1000005];
long long ans, c[1000005];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &h[i]);
  }
  rotate(h, max_element(h, h + n), h + n);
  h[n] = h[0];
  for (int i = n - 1; i >= 0; i--) {
    r[i] = i + 1;
    while (r[i] < n && h[r[i]] < h[i]) {
      r[i] = r[r[i]];
    }
    if (r[i] < n && h[r[i]] == h[i]) {
      c[i] = c[r[i]] + 1;
      r[i] = r[r[i]];
    }
  }
  for (int i = 0; i < n; i++) {
    ans += c[i];
    if (h[i] == h[0]) continue;
    l[i] = i - 1;
    while (l[i] > 0 && h[l[i]] <= h[i]) {
      l[i] = l[l[i]];
    }
    ans += 2;
    if (l[i] == 0 && r[i] == n) ans--;
  } 
  
  printf("%I64d\n", ans);
  
  return 0;
}