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
    int d; cin >> d;
    vector<int> a(n);
    bool w = true;
    int num = 0;
    for(int i=0;i<n;i++) {
      cin >> a[i];
      if(a[i]>d) ++num;
    }
    sort(a.begin(), a.end());
    if(num==0) cout << "YES" << "\n";
    else {
      if(a[0]+a[1] <= d) cout << "YES" << "\n";
      else cout << "NO" << "\n";
    }
  }
}