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

int amt[256];

void solve() {
  int n;
  cin >> n;
  while(n--) {
    string s;
    cin >> s;
    amt[s[0]]++;
  }
  int ret = 0;
  for(int i = 0; i < 256; i++) {
    int a = amt[i]/2;
    int b = amt[i] - a;
    ret += a*(a-1)/2;
    ret += b*(b-1)/2;
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}