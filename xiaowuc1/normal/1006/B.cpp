#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int l[2005];
bool used[2005];
vector<int> choose;

void solve() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  int ret = 0;
  while(k--) {
    int best = -1;
    int from = -1;
    for(int i = 0; i < n; i++) {
      if(!used[i] && l[i] > best) {
        from = i;
        best = l[i];
      }
    }
    ret += best;
    choose.push_back(from);
    used[from] = true;
  }
  sort(choose.begin(), choose.end());
  cout << ret << endl;
  int leftover = n;
  for(int i = 0; i < choose.size(); i++) {
    if(i == choose.size()-1) {
      cout << leftover << endl;
    }
    else if(i == 0) {
      cout << choose[i]+1 << " ";
      leftover -= choose[i] + 1;
    }
    else {
      cout << (choose[i] - choose[i-1]) << " ";
      leftover -= choose[i] - choose[i-1];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}