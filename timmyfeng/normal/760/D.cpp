#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int min_cost[N];
int t[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  int ptr90 = 0;
  int ptr1440 = 0;
  for (int i = 0; i < n; ++i) {
    while (t[ptr90] + 90 <= t[i]) {
      ++ptr90;
    }

    while (t[ptr1440] + 1440 <= t[i]) {
      ++ptr1440;
    }

    min_cost[i + 1] = min({
        min_cost[i] + 20,
        min_cost[ptr90] + 50,
        min_cost[ptr1440] + 120
    });

    cout << min_cost[i + 1] - min_cost[i] << "\n";
  }
}