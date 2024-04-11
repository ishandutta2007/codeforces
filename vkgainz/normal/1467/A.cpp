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
    if(n==1) cout << "9" << "\n";
    else {
      string ans = "98";
      for(int i=2;i<n;i++) {
        ans+=to_string((7+i)%10);
      }
      cout << ans << "\n";
    }
  }
}