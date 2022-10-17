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
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  int answer = 0;
  map<int, int> cnt_h;
  map<pair<int, int>, int> cnt_pairs;
  for (int i = 0; i < n; i++) {
    int w, h;
    cin >> w >> h;
    if (w > h) {
      swap(w, h);
    }
    if (w == h) {
      answer += cnt_h[h];
      cnt_h[h]++;
    } 
    else {
      answer += cnt_h[h] + cnt_h[w] - cnt_pairs[{w, h}];
      cnt_h[h]++;
      cnt_h[w]++;
      cnt_pairs[{w, h}]++;
    }
  }
  cout << answer << '\n';
}