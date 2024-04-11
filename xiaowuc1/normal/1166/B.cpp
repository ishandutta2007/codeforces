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

string v = "aeiou";

void solve() {
  int k;
  cin >> k;
  for(int r = 5; r <= k; r++) {
    if(k%r) continue;
    int c = k/r;
    if(c<5) continue;
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        cout << v[(i+j)%5];
      }
    }
    cout << "\n";
    return;
  }
  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}