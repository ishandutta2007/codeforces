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
typedef pair<int, ll> pill;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<ll>> matrix;

int p[300005];
void init() {
  for(int i = 2; i <= 300000; i++) {
    if(p[i]) continue;
    for(int j = i; j <= 300000; j += i) {
      if(p[j] == 0) {
        p[j] = i;
      }
    }
  }
}

int seen[300005];

ll analyze(vector<int>& v, int sz) {
  ll ret = 0;
  for(int mask = 1; mask < (1<<v.size()); mask++) {
    bool add = false;
    {
      int t = mask;
      while(t) {
        add = !add;
        t &= t-1;
      }
    }
    int want = 1;
    for(int i = 0; i < v.size(); i++) {
      if((mask&(1<<i))) want *= v[i];
    }
    int have = seen[want] - 1;
    ll delta = 1;
    for(int x = 1; x < sz; x++) {
      delta *= (have+1-x);
      delta /= x;
    }
    if(add) ret += delta;
    else ret -= delta;
  }
  return ret;
}

int main() {
  init();
  int n;
  set<vector<int>> s;
  scanf("%d", &n);
  bool primeFound = false;
  while(n--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      printf("1\n");
      return 0;
    }
    vector<int> v;
    while(t > 1) {
      v.push_back(p[t]);
      int d = p[t];
      while(t%d==0) t /= d;
    }
    s.insert(v);
    if(v.size() == 1) primeFound = true;
  }
  for(vector<int> v: s) {
    for(int mask = 1; mask < (1<<v.size()); mask++) {
      int p = 1;
      for(int i = 0; i < v.size(); i++) {
        if((mask&(1<<i))) {
          p *= v[i];
        }
      }
      seen[p]++;
    }
  }
  for(int i = 2; i <= 300000; i++) {
    if(seen[i] == s.size()) {
      printf("-1\n");
      return 0;
    }
  }
  if(primeFound) {
    printf("2\n");
    return 0;
  }
  int ret = 2;
  while(ret <= 6) {
    ll other = 1;
    for(int x = 1; x < ret; x++) {
      other *= (s.size() - x);
      other /= x;
    }
    for(vector<int> v: s) {
      ll curr = analyze(v, ret);
      if(curr < other) {
        printf("%d\n", ret);
        return 0;
      }
    }
    ret++;
  }
  printf("%d\n", ret);
}