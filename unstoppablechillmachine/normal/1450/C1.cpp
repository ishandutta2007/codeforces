#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
 
const int N = 310; 
char c[N][N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> cnt(3);
    int all_cnt = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> c[i][j];
        if (c[i][j] == 'X') {
          cnt[(i + j) % 3]++;
          all_cnt++;
        }
      }  
    }
    int kek = 0;
    while (cnt[kek] * 3 > all_cnt) {
      kek++;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (c[i][j] == 'X' && (i + j) % 3 == kek) {
          c[i][j] = 'O';
        }
        cout << c[i][j];
      }
      cout << '\n';
    }
  }
}