#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<array<int, 2>> freq(n);
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      ++freq[a - 1][0];
      freq[a - 1][1] += b;
    }
    sort(freq.begin(), freq.end());

    priority_queue<int> choices;
    int candies = 0;
    int dislike = 0;

    for (int i = n; i > 0; --i) {
      while (!freq.empty() && freq.back()[0] >= i) {
        choices.push(freq.back()[1]);
        freq.pop_back();
      }

      if (!choices.empty()) {
        dislike += min(i, choices.top());
        choices.pop();
        candies += i;
      }
    }

    cout << candies << " " << dislike << "\n";
  }
}