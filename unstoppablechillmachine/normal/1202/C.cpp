#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second
 
const int N = 2e5 + 10;
int pref1[N], pref2[N], pref3[N], pref4[N], suf1[N], suf2[N], suf3[N], suf4[N];
int vlx[N], vly[N];
signed main() {
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int cx = 0, cy = 0;
    int n = SZ(s);
    s.insert(s.begin(), ' ');
    for (int i = 1; i <= n; i++) {
      if (s[i] == 'W') {
        cx++;
      }
      else if (s[i] == 'S') {
        cx--;
      }
      else if (s[i] == 'A') {
        cy++;
      }
      else {
        cy--;
      }
      vlx[i] = cx;
      vly[i] = cy;
      pref1[i] = max(pref1[i - 1], cx);
      pref2[i] = min(pref2[i - 1], cx);
      pref3[i] = max(pref3[i - 1], cy);
      pref4[i] = min(pref4[i - 1], cy);
    }
    int A = pref1[n] - pref2[n] + 1, B = pref3[n] - pref4[n] + 1;
    cx = 0, cy = 0;
    suf1[n] = suf2[n] = vlx[n];
    suf4[n] = suf3[n] = vly[n];
    for (int i = n - 1; i >= 1; i--) {
      suf1[i] = max(suf1[i + 1], vlx[i]);
      suf2[i] = min(suf2[i + 1], vlx[i]);
      suf3[i] = max(suf3[i + 1], vly[i]);
      suf4[i] = min(suf4[i + 1], vly[i]);
    }
    bool can1 = false, can2 = false;
    cx = 0, cy = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == 'W') {
        cx++;
      }
      else if (s[i] == 'S') {
        cx--;
      }
      else if (s[i] == 'A') {
        cy++;
      }
      else {
        cy--;
      }
      if (max(vlx[i], max(pref1[i - 1], suf1[i] + 1)) + 1 - min(vlx[i], min(pref2[i - 1], suf2[i] + 1)) < A) {
        can1 = true;
      }
      if (max(vlx[i], max(pref1[i - 1], suf1[i] - 1)) + 1 - min(vlx[i], min(pref2[i - 1], suf2[i] - 1)) < A) {
        can1 = true;
      }
      if (max(vly[i], max(pref3[i - 1], suf3[i] + 1)) + 1 - min(vly[i], min(pref4[i - 1], suf4[i] + 1)) < B) {
        can2 = true;
      }
      if (max(vly[i], max(pref3[i - 1], suf3[i] - 1)) + 1 - min(vly[i], min(pref4[i - 1], suf4[i] - 1)) < B) {
        can2 = true;
      }
    }
    if (can1 && can2) {
      cout << min((A - 1) * 1ll * B, A * 1ll * (B - 1)) << '\n';
      continue;
    }
    else if (can1) {
      A--;
    }
    else if (can2) {
      B--;
    }
    cout << A * 1ll * B << '\n';
  }
}