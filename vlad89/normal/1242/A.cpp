#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

ll gcd(ll a, ll b) {
  while (a && b) {
    if (a > b) a %= b; else b %= a;
  }
  return a + b;
}

int main () {
#ifdef LOCAL
  freopen("x.in", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  ll n;
  cin >> n;
  ll g = n;  
  for (ll x = 2; x * x <= n; ++x) {
    if (n % x == 0) {
      g = gcd(x, g);
      g = gcd(n/x, g);
    }    
  }
  cout << g << endl;
  return 0;
}