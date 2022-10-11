#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

char buf[1000000];

void solve() {
  scanf("%s", buf);
  int len = strlen(buf);
  for(int i = 1; i < len; i++) {
    bool flag = false;
    if(buf[i] == buf[i-1]) {
      while(buf[i] == buf[i-1] || (i+1 < len && buf[i] == buf[i+1])) {
        flag = true;
        buf[i] = (char)('a' + rand()%26);
      }
    }
    if(flag) i++;
  }
  printf("%s\n", buf);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
  solve();
}