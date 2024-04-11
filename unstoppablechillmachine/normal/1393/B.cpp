#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll    

const int N = 1e5 + 10;
int cnt[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int sum1 = 0, sum2 = 0;
  for (int i = 1; i <= 1e5; i++) {
    sum1 += cnt[i] / 4;
    sum2 += cnt[i] / 2;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    char type;
    cin >> type;
    int x;
    cin >> x;
    sum1 -= cnt[x] / 4;
    sum2 -= cnt[x] / 2;
    if (type == '+') {
      cnt[x]++;
    }
    else {
      cnt[x]--;
    }
    sum1 += cnt[x] / 4;
    sum2 += cnt[x] / 2;
    if (sum1 > 0 && sum2 >= 4) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
}