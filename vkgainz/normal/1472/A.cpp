#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 1e5+5;

int main() {
  int t; cin >> t;
  while(t--) {
    int w, h, n; cin >> w >> h >> n;
    w*=h;
    int x = 1;
    while(w%2==0) {
      x*=2, w/=2;
    }
    if(x >= n) {
      cout<< "YES" << "\n";
    }
    else cout << "NO" << "\n";
  }
}