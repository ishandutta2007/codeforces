#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> ap;
  vector<int> an;
  int sp = 0;
  int sn = 0;
  int cz = 0;
  for (int i = 0; i < N; ++i) {
    int v;
    cin >> v;
    if (v < 0) {
      sn += v;
      an.push_back(v);
    } else if (v == 0) {
      cz++;
    } else {
      sp += v;
      ap.push_back(v);
    }
  }
  if (sp + sn == 0) {
    cout << "NO" << endl;
    return;
  }

  vector<int> a;
  if (sp > -sn) {
    a.insert(a.end(), ap.begin(), ap.end());
    a.insert(a.end(), an.begin(), an.end());
  } else {
    a.insert(a.end(), an.begin(), an.end());
    a.insert(a.end(), ap.begin(), ap.end());
  }
  for (int i = 0; i < cz; ++i) {
    a.push_back(0);
  }
  cout << "YES" << endl;
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << (i == a.size() - 1 ? "\n" : " ");
  }
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i){
    solve();
  }
}