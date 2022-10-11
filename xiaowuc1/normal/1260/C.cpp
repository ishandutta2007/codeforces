#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> trap;

string slow(ll a, ll b, ll k) {
  if(a > b) swap(a, b);
  ll high = a / __gcd(a, b) * b;
  int aa = 0;
  int bb = 0;
  for(int i = 1; i < high; i++) {
    if(i%a && i%b) continue;
    if(i%a == 0) {
      if(aa == k-1) return "REBEL";
      aa++;
      bb = 0;
    }
    else {
      assert(i%b==0);
      if(bb == k-1) return "REBEL";
      aa = 0;
      bb++;
    }
  }
  return "OBEY";
}

string rsolve(ll a, ll b, ll k) {
  if(a > b) swap(a, b);
  ll g = __gcd(a, b);
  a /= g;
  b /= g;
  if(b%a == 0) {
    if(b/a > k) return "REBEL";
    return "OBEY";
  }
  if((b-1+a-1)/a >= k) return "REBEL";
  return "OBEY";
}

void solve() {
  /*
  for(int a = 1; a <= 1e9; a++) {
    cerr << a << endl;
    for(int b = 1; b <= a; b++) {
      for(int k = 2; true; k++) {
        string fast = rsolve(a, b, k);
        string ac = slow(a, b, k);
        if(fast != ac) {
          cerr << a << " " << b << " " << k << ": " << fast << " " << ac << endl;
          assert(false);
        }
        if(ac == "OBEY") break;
      }
    }
  }
  */
  int t;
  cin >> t;
  while(t--) {
    ll a, b, k;
    cin >> a >> b >> k;
    cout << rsolve(a, b, k) << "\n";
    // rsolve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}