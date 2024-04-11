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

const int N = 1e6 + 10;
bool gr_pal[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int n = SZ(s);
    for (int i = 0; i <= n; i++) {
      gr_pal[i] = false;  
    }
    vector<int> d1 (n);
    int l=0, r=-1;
    for (int i=0; i<n; ++i) {
      int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
      while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
      d1[i] = k;
      if (i+k-1 > r)
        l = i-k+1,  r = i+k-1;
    }
    vector<int> d2 (n);
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
      int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
      while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
      d2[i] = k;
      if (i+k-1 > r)
        l = i-k,  r = i+k-1;
    }
    gr_pal[0] = true;
    for (int i = 1; i <= n / 2; i++) {
      if (s[i - 1] != s[n - i]) {
        break;
      }
      gr_pal[i] = true;
    }
    if (gr_pal[n / 2]) {
      cout << s << '\n';
      continue;
    }
    int ans = 0;
    pair<int, int> best;
    for (int i = 0; i < n; i++) {
      d1[i]--;
      {
        int L = i - d1[i] - 1, R = i + d1[i] + 1;
        int len1 = L + 1, len2 = n - R;
        if (gr_pal[len1] && len1 * 2 + d1[i] * 2 + 1 < n) {
          if (len1 * 2 + d1[i] * 2 + 1 > ans) {
            ans = len1 * 2 + d1[i] * 2 + 1;
            best = {len1 + d1[i] * 2 + 1, len1};
          }
        }
        if (gr_pal[len2] && len2 * 2 + d1[i] * 2 + 1 < n) {
          if (len2 * 2 + d1[i] * 2 + 1 > ans) {
            ans = len2 * 2 + d1[i] * 2 + 1;
            best = {len2, d1[i] * 2 + 1 + len2};
          }
        }
      }
      {
        if (d2[i] == 0) {
          continue;
        }
        int L = i - d2[i] - 1, R = i + d2[i];
        int len1 = L + 1, len2 = n - R;
        //cout << len1 << ' ' << len2 << '\n';
        if (gr_pal[len1] && len1 * 2 + d2[i] * 2 < n) {
          if (len1 * 2 + d2[i] * 2 > ans) {
            ans = len1 * 2 + d2[i] * 2;
            best = {len1 + d2[i] * 2, len1};
          }
        }
        if (gr_pal[len2] && len2 * 2 + d2[i] * 2 < n) {
          if (len2 * 2 + d2[i] * 2 > ans) {
            ans = len2 * 2 + d2[i] * 2;
            best = {len2, d2[i] * 2 + len2};
          }
        } 
      }
    }
    for (int i = 1; i <= best.F; i++) {
      cout << s[i - 1];
    }
    for (int i = best.S; i >= 1; i--) {
      cout << s[n - i];
    }
    cout << '\n';
  }  
}