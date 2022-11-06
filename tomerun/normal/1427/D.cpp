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

int N;
int C[52], C2[52];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", C + i);
    C[i]--;
  }
  vector<vector<int>> ans;
  vector<int> pos(N);
  while (true) {
    for (int i = 0; i < N; ++i) {
      pos[C[i]] = i;
    }
    bool found = false;
    for (int i = 0; i < N - 1; ++i) {
      if (pos[i] > pos[i + 1]) {
        int mid = pos[i];
        while (C[mid] == C[mid - 1] + 1) {
          mid--;
        }
        vector<int> a;
        if (pos[i + 1] > 0) a.push_back(pos[i + 1]);
        a.push_back(mid - pos[i + 1]);
        a.push_back(pos[i] - mid + 1);
        if (pos[i] < N - 1) a.push_back(N - 1 - pos[i]);
        ans.push_back(a);
        // cerr << "i=" << i << " pos[i]=" << pos[i] << " pos[i+1]=" << pos[i+1] << " mid=" << mid << endl;
        int to = 0;
        for (int j = pos[i] + 1; j < N; ++j) {
          C2[to++] = C[j];
        }
        for (int j = mid; j <= pos[i]; ++j) {
          C2[to++] = C[j];
        }
        for (int j = pos[i + 1]; j < mid; ++j) {
          C2[to++] = C[j];
        }
        for (int j = 0; j < pos[i + 1]; ++j) {
          C2[to++] = C[j];
        }
        swap(C, C2);
        found = true;
        break;
      }
    }
    if (!found) break;
    // for (int i = 0; i < N; ++i) {
    //   cerr << C[i] << " ";
    // }
    // cerr << endl;
  }
  cout << ans.size() << endl;
  for (auto& a : ans) {
    cout << a.size();
    for (int i = 0; i < a.size(); ++i) {
      cout << " " << a[i];
    }
    cout << endl;
  }
}