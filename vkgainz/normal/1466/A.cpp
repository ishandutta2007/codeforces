#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 1e5+5;

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> x(n);
    for(int i=0;i<n;i++)
      cin >> x[i];
    set<int> s;
    for(int i=0;i<n;i++) {
      for(int j=i+1;j<n;j++) {
        s.insert(x[j]-x[i]);
      }
    }
    cout << s.size() << "\n";
  }
}