#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)

const int N = 1e5 + 5;

int t[N], n;
const int MAX = 1e2;

int main() {
  cin >> n;
  for(int i = 1, x, r; i <= n; ++ i) {
    scanf("%d", &r);
    REP(j, 1, r) scanf("%d", &x), ++ t[x];
  }
  REP(i, 1, MAX) if(t[i] == n) printf("%d ", i);
  puts("");
}