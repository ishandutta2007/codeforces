#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>> " << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;

bool check(ll n, ll k) {
  int at = 0, need = 0;
  ll cnt = 0;
  while (cnt + at < k && need < n) {
    cnt += at;
    at++;
    need++;
  }

}

int main() {
  ll n, k;
  cin >> n >> k;
  if (n  * (n-1) / 2 < k) {
    puts("Impossible");
    return 0;
  }
  int at = 0;
  ll cnt = 0;
  while (cnt + at < k) {
    cnt += at;
    at++;
    printf("(");
    n--;
  }
  while(at > 0) {
    if (at + cnt == k) {
      printf("()");
      cnt = k;
      n--;
    }
    printf(")");
    at--;
  }
  while (n > 0) {
    printf("()");
    n--;
  }
  puts("");
}