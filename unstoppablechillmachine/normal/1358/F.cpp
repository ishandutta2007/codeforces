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
  vector<int> a(n), b(n);
  for (auto &x : a) {
    cin >> x;
  }
  for (auto &x : b) {
    cin >> x;
  }
  if (n == 1) {
    if (a[0] == b[0]) {
      cout << "SMALL\n0\n";
    }
    else {
      cout << "IMPOSSIBLE\n";
    }
    exit(0);
  }
  if (n == 2) {
    vector<pair<char, int>> rez;
    int ss = a[0] + a[1];
    for (;;) {
      if (b[0] + b[1] < a[0] + a[1]) {
        cout << "IMPOSSIBLE\n";
        exit(0);
      }
      if (a == b) {
        break;
      }
      vector<int> b2 = {b[1], b[0]};
      if (b2 == a) {
        rez.pb({'R', 1});
        break;
      }
      bool srt1 = (b[0] < b[1]), srt2 = (b2[0] < b2[1]);
      if (srt1) {
        if (b[0] < 1 || b[1] < 1 || b[1] <= a[1]) {
          cout << "IMPOSSIBLE\n";
          exit(0);
        }
        int to_sum = b[0] + (b[1] % b[0]);
        if (to_sum < ss) {
          int cnt = (b[0] + b[1] - ss) / b[0];
          if (b[0] + b[1] - b[0] * cnt != ss) {
            cout << "IMPOSSIBLE\n";
            exit(0);
          }
          b[1] -= b[0] * cnt;
          rez.pb({'P', cnt});
          if (b == a) {
            break;
          }
          if (vector<int>{b[1], b[0]} == a) {
            rez.pb({'R', 1});
            break;
          }
          else {
            cout << "IMPOSSIBLE\n";
            exit(0);
          }
        }
        else {
          rez.pb({'P', b[1] / b[0]});
          b[1] %= b[0];
        }
      }
      else if (srt2) {
        rez.pb({'R', 1});
        swap(b, b2);
        if (b[0] < 1 || b[1] < 1 || b[1] <= a[1]) {
          cout << "IMPOSSIBLE\n";
          exit(0);
        }
        int to_sum = b[0] + (b[1] % b[0]);
        if (to_sum < ss) {
          int cnt = (b[0] + b[1] - ss) / b[0];
          if (b[0] + b[1] - b[0] * cnt != ss) {
            cout << "IMPOSSIBLE\n";
            exit(0);
          }
          b[1] -= b[0] * cnt;
          rez.pb({'P', cnt});
          if (b == a) {
            break;
          }
          if (vector<int>{b[1], b[0]} == a) {
            rez.pb({'R', 1});
            break;
          }
          else {
            cout << "IMPOSSIBLE\n";
            exit(0);
          }
        }
        else {
          rez.pb({'P', b[1] / b[0]});
          b[1] %= b[0];
        }
      }
      else {
        cout << "IMPOSSIBLE\n";
        exit(0);
      }
    }
    reverse(all(rez));  
    int sum = 0, sum2 = 0;
    for (auto it : rez) {
      if (it.F == 'P') {
        sum += it.S;
      }
      sum2 += it.S;
    }
    if (sum > 2e5) {
      cout << "BIG\n" << sum << '\n';
    }
    else {
      cout << "SMALL\n" << sum2 << '\n';
      for (auto it : rez) {
        for (int i = 0; i < it.S; i++) {
          cout << it.F;
        }
      }
      cout << '\n';
    }
    exit(0);
  }
  int mx = 0;
  for (auto &x : a) {
    mx = max(mx, x);
  }
  vector<char> rez;
  for (;;) {
    //cout << b[0] << ' ' << b[1] << ' ' << b[2] << '\n';
    if (a == b) {
      break;
    }
    vector<int> b2 = b;
    reverse(all(b2));
    if (b2 == a) {
      rez.pb('R');
      break;
    }
    bool srt1 = true, srt2 = true;
    for (int i = 1; i < n; i++) {
      if (b[i] <= b[i - 1]) {
        srt1 = false;
      }
      if (b2[i] <= b2[i - 1]) {
        srt2 = false;
      }
    }
    if (srt1) {
      for (int i = 0; i < n; i++) {
        if (b[i] < 1) {
          cout << "IMPOSSIBLE\n";
          exit(0);
        }
      }
      if (b.back() <= mx) {
        cout << "IMPOSSIBLE\n";
        exit(0);
      }
      rez.pb('P');
      vector<int> nb = {b[0]};
      for (int i = 1; i < n; i++) {
        nb.pb(b[i] - b[i - 1]);
      }
      b = nb;
    }
    else if (srt2) {
      rez.pb('R');
      rez.pb('P');
      for (int i = 0; i < n; i++) {
        if (b2[i] < 0) {
          cout << "IMPOSSIBLE\n";
          exit(0);
        }
      }
      if (b2.back() <= mx) {
        cout << "IMPOSSIBLE\n";
        exit(0);
      }
      vector<int> nb = {b2[0]};
      for (int i = 1; i < n; i++) {
        nb.pb(b2[i] - b2[i - 1]);
      }
      b = nb;
    }
    else {
      cout << "IMPOSSIBLE\n";
      exit(0);
    }
  }
  int sum = 0;
  for (auto it : rez) {
    if (it == 'P') {
      sum++;
    }
  }
  /*for (int i = 0; i + 1 < SZ(rez); i++) {
    assert(rez[i] != 'R' || rez[i + 1] != 'R');
  }*/
  if (sum > 2e5) {
    cout << "BIG\n" << sum << '\n';
  }
  else {
    cout << "SMALL\n" << SZ(rez) << '\n';
    reverse(all(rez));
    for (auto &c : rez) {
      cout << c;
    }
    cout << '\n';
  }
  cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}