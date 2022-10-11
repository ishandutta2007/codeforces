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

const int MAX_V = 15000000;
int p[MAX_V+1];
int cnt[MAX_V+1];

int l[300005];

int gcd(int a, int b) {
  while(a%b) {
    int c=a%b;
    a=b;
    b=c;
  }
  return b;
}

int main() {
  for(int i = 1; i <= MAX_V; i++) {
    p[i] = i;
  }
  for(int i = 2; i * i <= MAX_V; i++) {
    if(p[i] == i) {
      for(int j = i*i; j <= MAX_V; j += i) {
        p[j] = i;
      }
    }
  }
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &l[i]);
  }
  int orig = l[0];
  for(int i = 1; i < n; i++) {
    orig = gcd(l[i], orig);
  }
  for(int i = 0; i < n; i++) {
    l[i] /= orig;
  }
  int highest = 0;
  for(int i = 0; i < n; i++) {
    int lastp = -1;
    int curr = l[i];
    while(curr > 1) {
      int nextp = p[curr];
      if(nextp != lastp) {
        highest = max(highest, ++cnt[nextp]);
      }
      lastp = nextp;
      curr /= lastp;
    }
  }
  if(highest == 0) printf("-1\n");
  else printf("%d\n", n - highest);
  return 0;
}