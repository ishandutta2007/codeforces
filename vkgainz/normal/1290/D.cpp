#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ask(int x) { 
  cout << "? " << x + 1 << "\n";
  cout.flush();
  char c; cin >> c;
  return c == 'Y';
}

void reset() { cout << "R" << "\n", cout.flush(); }

int main() {
  int n, k; cin >> n >> k;
  
  vector<bool> unique(n, 1);
  
  int bucket = max(k / 2, 1);

  for(int d = 1; d < n / bucket; d++) {
    for(int st = 0; st < d; st++) {
      if(st + d >= n / bucket) continue;
      reset();
      for(int x = st; x < n / bucket; x += d) {
        //add segment in
        for(int i = x * bucket; i < x * bucket + bucket; i++) {
          if(ask(i)) unique[i] = false;
        }
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++) ans += unique[i];
  cout << "! " << ans;
}