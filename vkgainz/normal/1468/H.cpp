#include <bits/stdc++.h>
using namespace std;
const int MX = 2e5 + 5;
int main() {
  int t; cin >> t;
  while(t--) {
    int n, k, m; cin >> n >> k >> m;
    int b[m];
    for(int i=0;i<m;i++) cin >> b[i];
    bool work = false;
    for(int i=0;i<m;i++) {
      int numLeft = b[i] - (i+1);
      int numRight = (n - b[i] - (m - i - 1));
      if(numLeft >= (k-1)/2 && numRight >= (k-1)/2)
        work = true;
    }
    if((n-m)%(k-1)!=0) work = false;
    if(work) cout << "Yes" << "\n";
    else cout << "No" << "\n";
  }
}