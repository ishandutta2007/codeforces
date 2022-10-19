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

const int MOD = 998244353;
void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}

const int N = 2e5 + 10;
int ans[N], pw[N];
int ans2[N];

vector<int> kek;
void f() {
  /*for (auto it : kek) {
    cout << it;
  }
  cout << '\n';*/
  int prv = kek[0], cnt = 1;
  for (int i = 1; i < SZ(kek); i++) {
    if (kek[i] != prv) {
      ans2[cnt]++;
      cnt = 1;
      prv = kek[i];
    }
    else {
      cnt++;
    }
  }
  ans2[cnt]++;
}

void gen(int cur, int need) {
  if (cur == need) {
    f();
    return;
  }
  for (int i = 0; i < 10; i++) {
    kek.pb(i);
    gen(cur + 1, need);
    kek.pop_back();
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  //gen(1, n + 1);
	pw[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw[i] = (pw[i - 1] * 10ll) % MOD;
  }
  ans[n] = 10;
  for (int i = 1; i <= n - 1; i++) {
    add(ans[i], mult(180, pw[n - i - 1]));
  }
  int cnt = 1;
  for (int i = n - 2; i >= 1; i--) {
    int cr = mult(cnt, 810);
    add(ans[i], mult(cr, pw[n - i - 2]));
    cnt++;
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}