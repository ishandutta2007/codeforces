#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;

int nTest, n;
string s;

int main() {
  scanf("%d", &nTest);
  while (nTest--) {
    cin >> n;
    cin >> s;

    string ans = "";
    int bestK = -1;

    for(int k = 1; k <= n; ++k) {
      string t = s.substr(k-1) + s.substr(0, k-1);
      if ((n-k+1) % 2 == 1)
        reverse(t.begin() + n-k+1, t.end());
      if (ans == "" || t < ans) {
        ans = t;
        bestK = k;
      }
    }
    
    cout << ans << endl;
    cout << bestK << endl;
  }

  return 0;
}