#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 1e5+5;

int main() {
  int t; cin >> t;
  while(t--) {
    int a, b; cin >> a >> b;
    int ans = 10000;
    for(int ch=2;ch<=100;ch++) {
      int x = max(b, ch), y = max(ch-b, 0);
      int temp = a;
      int numStep = y;
      while(temp>0) {
        temp/=x, numStep++;
      }
      ans = min(ans, numStep);
    }
    cout << ans << "\n";
  }
}