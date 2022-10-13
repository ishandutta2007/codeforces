#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
const int MX = 3e6+5;
int main() {
  int t; cin >> t;
  while(t--) {
    int n, x; cin >> n >> x;
    vector<int> w(n);
    for(auto &w : w) cin >> w;
    sort(w.begin(), w.end(), greater<int>());
    bool work = true;
    int sum = 0;
    for(int i=0;i<n;i++) {
      sum += w[i];
      if(sum == x) work = false;
    }
    if(sum == x) {
      cout << "NO" << "\n";
      continue;
    }
    if(work) {
      cout << "YES" << "\n";
      for(auto &w : w)
        cout << w << " ";
      cout << "\n";
    }
    else {
      sum = 0;
      for(int i=0;i<n;i++) {
        sum += w[i];
        if(sum == x) {
          int x = w[i];
          w[i] = w[i+1];
          w[i+1] = x;
          break;
        }
      }
      cout << "YES" << "\n";
      for(auto &w : w)
        cout << w << " ";
      cout << "\n";
    }
  }
}