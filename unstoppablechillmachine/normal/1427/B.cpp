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

bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.S - a.F < b.S - b.F;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> segm_l;
    vector<pair<int, int>> other_hui1, other_hui2;
    int l = -1;
    vector<char> c(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
      if (c[i] == 'W') {
        if (l != -1) {
          if (l == 1) {
            other_hui1.pb({l, i - 1});
          }
          else {
            segm_l.pb({l, i - 1});
          }
        }
        l = -1;
      }
      else {
        if (l == -1) {
          l = i;
        }
      }
    }
    if (l != -1) {
      other_hui2.pb({l, n});
    }
    sort(all(segm_l), cmp);
    for (int i = 0; i < SZ(segm_l); i++) {
      while (k > 0 && segm_l[i].F <= segm_l[i].S) {
        k--;
        c[segm_l[i].F++] = 'W';
      }
    }
    for (int i = 0; i < SZ(other_hui2); i++) {
      while (k > 0 && other_hui2[i].F <= other_hui2[i].S) {
        k--;
        c[other_hui2[i].F++] = 'W';
      } 
    }
    for (int i = 0; i < SZ(other_hui1); i++) {
      while (k > 0 && other_hui1[i].F <= other_hui1[i].S) {
        k--;
        c[other_hui1[i].S--] = 'W';
      } 
    }
    int rez = 0;
    for (int i = 1; i <= n; i++) {
      if (c[i] == 'W') {
        if (c[i - 1] == 'W') {
          rez += 2;
        }
        else {
          rez++;
        }
      }
    }
    cout << rez << '\n'; 
  }
}