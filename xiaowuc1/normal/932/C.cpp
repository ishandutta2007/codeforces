#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  for(int i = 0; i * a <= n; i++) {
    int j = (n-a*i)/b;
    if(a*i + b*j != n) continue;
    int curr = 1;
    while(i--) {
      vector<int> v;
      for(int q = 0; q < a; q++) {
        v.push_back(curr++);
      }
      for(int q = 0; q < a; q++) {
        cout << v[(q+1)%a] << " ";
      }
    }
    while(j--) {
      vector<int> v;
      for(int q = 0; q < b; q++) {
        v.push_back(curr++);
      }
      for(int q = 0; q < b; q++) {
        cout << v[(q+1)%b] << " ";
      }
    }
    cout << endl;
    return;
  }
  cout << "-1\n";
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