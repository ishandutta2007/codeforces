#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pii l[1000000];

void solve() {
  int n;
  int a, b;
  cin >> n >> a >> b;
  for(int i = 0; i < n; i++) {
    int t;
    cin >> t;
    l[i] = {t, i+1};
  }
  sort(l, l+n);
  for(int i = 0; i < n; i++) {
    // can l[i] go to a?
    {
      int aNeed = (a + l[i].first - 1) / l[i].first;
      if(i + aNeed < n) {
        int start = i + aNeed;
        int bNeed = (b + l[start].first - 1) / l[start].first;
        if(start + bNeed <= n) {
          cout << "Yes\n";
          cout << aNeed << " " << bNeed << "\n";
          for(int x = 0; x < aNeed; x++) {
            cout << l[i+x].second << " ";
          }
          cout << "\n";
          for(int x = 0; x < bNeed; x++) {
            cout << l[start+x].second << " ";
          }
          cout << "\n";
          return;
        }
      }
    }
    // can l[i] go to b?
    {
      int bNeed = (b + l[i].first - 1) / l[i].first;
      if(i + bNeed < n) {
        int start = i + bNeed;
        int aNeed = (a + l[start].first - 1) / l[start].first;
        if(start + aNeed <= n) {
          cout << "Yes\n";
          cout << aNeed << " " << bNeed << "\n";
          for(int x = 0; x < aNeed; x++) {
            cout << l[start+x].second << " ";
          }
          cout << "\n";
          for(int x = 0; x < bNeed; x++) {
            cout << l[i+x].second << " ";
          }
          cout << "\n";
          return;
        }
      }
    }
  }
  cout << "No\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}