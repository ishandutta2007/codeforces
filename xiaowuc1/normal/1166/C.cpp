#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/*
x inside |x-y| and |x+y|
y inside |x-y| and |x+y|
*/

int n;
int l[300000];
void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    l[i] = abs(t);
  }
  sort(l, l+n);
  ll ret = 0;
  int j = 0;
  for(int i = 0; i < n; i++) {
    while(j < n && l[j] <= 2*l[i]) j++;
    ret += j-i-1;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}