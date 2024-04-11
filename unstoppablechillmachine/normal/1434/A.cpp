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

const int N = 1e5 + 10;
int cnt[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  vector<int> a(6);
  for (auto &it : a) {
    cin >> it;
  }  
  int n;
  cin >> n;
  vector<int> b(n);
  for (auto &it : b) {
    cin >> it;
  }
  vector<pair<int, int>> srt;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < n; j++) {
      srt.pb({b[j] - a[i], j});
    }
  }
  sort(all(srt));
  int ptr = 0, cntall = 0;
  while (cntall < n) {
    cnt[srt[ptr].S]++;
    if (cnt[srt[ptr].S] == 1) {
      cntall++;
    }
    ptr++;
  }
  int ans = srt[ptr - 1].F - srt[0].F;
  for (int i = 1; i < SZ(srt); i++) {
    cnt[srt[i - 1].S]--;
    if (cnt[srt[i - 1].S] == 0) {
      cntall--;
    }
    while (cntall < n && ptr < SZ(srt)) {
      cnt[srt[ptr].S]++;
      if (cnt[srt[ptr].S] == 1) {
        cntall++;
      }
      ptr++;
    }
    if (cntall == n) {
      ans = min(ans, srt[ptr - 1].F - srt[i].F);
    }
    //cout << srt[i].F << ' ' << srt[ptr].F << '\n';
  }
  cout << ans << '\n';
}