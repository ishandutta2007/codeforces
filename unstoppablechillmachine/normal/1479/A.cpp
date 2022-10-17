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
  auto ask = [](int x) {
    cout << "? " << x << endl;
    int res;
    cin >> res;
    return res;
  };
  auto answer = [](int x) {
    cout << "! " << x << endl;
    exit(0);
  };
  if (n == 1) {
    answer(1);
  }
  int A = ask(1), B = ask(2);
  if (A < B) {
    answer(1);
  }
  int C = ask(n - 1), D = ask(n);
  if (C > D) {
    answer(n);
  }
  int l = 1, r = n;
  while (true) {
    int mid = (l + r) / 2;
    int A = ask(mid - 1), B = ask(mid), C = ask(mid + 1);
    if (B < A && B < C) {
      answer(mid);
    }
    if (B > A) {
      r = mid;
    }
    else {
      assert(B > C);
      l = mid;
    }
  }
}