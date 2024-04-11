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

char buf[200];
int n;
int main() {
  scanf("%d\n%s", &n, buf);
  int eight = 0;
  for(int i = 0; i < n; i++) {
    if(buf[i] == '8') eight++;
  }
  printf("%d\n", min(n/11, eight));
}