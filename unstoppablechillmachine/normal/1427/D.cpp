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

vector<int> get(vector<int> a, vector<int> parts) {
  reverse(all(parts));
  int lst = SZ(a);
  vector<int> rez;
  for (auto it : parts) {
    for (int j = lst - it; j < lst; j++) {
      rez.pb(a[j]);
    }
    lst -= it;
  }
  return rez;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  vector<vector<int>> answer;
  for (;;) {
    int id = -1;
    for (int i = 1; i < n; i++) {
      int ps1 = -1, ps2 = -1;
      for (int j = 0; j < n; j++) {
        if (a[j] == i) {
          ps1 = j;
        }
        if (a[j] == i + 1) {
          ps2 = j;
        }
      }
      if (ps1 > ps2) {
        id = i;
        break;
      }
    }
    if (id == -1) {
      break;
    }
    int ps1 = -1, ps2 = -1;
    for (int j = 0; j < n; j++) {
      if (a[j] == id) {
        ps1 = j;
      }
      if (a[j] == id + 1) {
        ps2 = j;
      }
    }
    //cout << id << ' ' << ps1 << ' ' << ps2 << endl;
    int tps = ps2;
    while (a[tps + 1] - a[tps] == 1) {
      tps++;
    }
    vector<int> parts;
    if (ps2 > 0) {
      parts.pb(ps2);
    }
    parts.pb(tps + 1 - ps2);
    parts.pb(ps1 - tps);
    if (ps1 < n - 1) {
      parts.pb(n - ps1 - 1);
    }
    /*for (auto it : parts) {
      cout << it << ' ';
    }
    cout << '\n';*/
    answer.pb(parts);
    a = get(a, parts);
    /*for (auto it : a) {
      cout << it << ' ';
    }
    cout << '\n';*/
  }
  cout << SZ(answer) << '\n';
  for (auto it : answer) {
    cout << SZ(it) << ' ';
    for (auto x : it) {
      cout << x << ' ';
    }
    cout << '\n';
  }  
}