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

int ask(int a, int b) {
  cout << "? " << a << ' ' <<  b << endl;
  int rez;
  cin >> rez;
  return rez;
}

mt19937 rnd(239);

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int pos1 = 1, pos2 = 2;
  int ost = 4269;
  int cval = ask(1, 2);
  ost--;
  for (int i = 3; i <= n; i++) {
    int A = ask(pos1, i);
    ost--;
    if (A < cval) {
      pos2 = i;
      cval = A;
    }
    else if (A == cval) {
      pos1 = i;
      cval = ask(pos1, pos2);
      ost--;
    }
  }
  int pos = -1;
  while (ost - 2 >= n - 1) {
    int pos3 = rnd() % n + 1;
    if (pos1 == pos3 || pos2 == pos3) {
      continue;
    }
    int A = ask(pos1, pos3), B = ask(pos2, pos3);
    ost -= 2;
    if (A < B) {
      pos = pos1;
      break;
    }
    if (B < A) {
      pos = pos2;
      break;
    }
  }
  assert(pos != -1);
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    if (i != pos) {
      ans[i] = ask(i, pos);
    }
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}