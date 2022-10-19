#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int n;

struct NODE {
  int A[5];
  void input(void) {
    for(int i = 0; i < 5; ++ i) scanf("%d", &A[i]);
  }

  friend int operator * (NODE a, NODE b) {
    int ans = 0;
    for(int i = 0; i < 5; ++ i) ans += a.A[i] * b.A[i];
    return ans;
  }

  friend NODE operator - (NODE a, NODE b) {
    for(int i = 0; i < 5; ++ i) a.A[i] -= b.A[i];
    return a;
  }
  
}T[N];

int main() {
  cin >> n;
  for(int i = 1; i <= n; ++ i) T[i].input();
  if(n > 15) {
    cout << 0 << endl;
    return 0;
  }
  else {
    vector < int> ans; ans.clear();
    for(int i = 1; i <= n; ++ i) {
      bool ok = 1;
      for(int j = 1; j <= n; ++ j) {
	for(int k = 1; k <= n; ++ k)
	  if(i != j && j != k && i != k) {
	    ok &= (((T[j] - T[i]) * (T[k] - T[i])) <= 0);
	    //cerr << i <<" " << j <<" " << k << endl;
	  }
      }
      if(ok) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < (int) ans.size(); ++ i) printf("%d\n", ans[i]);
  }
}