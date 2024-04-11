#include <bits/stdc++.h>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);

ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/
using namespace std;

const double PI = 2 * acos(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<ll>> matrix;

int amt[300005];
int pref[300005];
int main() {
  int n;
  scanf("%d", &n);
  int es = 1;
  int os = 0;
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    ll curr;
    scanf("%lld", &curr);
    amt[i] = __builtin_popcountll(curr);
    pref[i+1] = pref[i] + amt[i];
    int seen = 0;
    int maxS = 0;
    for(int j = i; j >= 0; j--) {
      seen += amt[j];
      maxS = max(maxS, amt[j]);
      if(seen%2 == 0 && maxS * 2 > seen) ret--;
      if(seen > 130) break;
    }
    if(pref[i+1]%2) ret += os++;
    else ret += es++;
  }
  printf("%lld\n", ret);
}