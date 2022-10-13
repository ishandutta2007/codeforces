#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MX = 1e6+5;

int main() {
  int n; cin >> n;
  int f[n];
  memset(f,0,sizeof(f));
  for(int i=0;i<n-1;i++) {
    int a,b;
    cin >> a >> b;
    --a, --b, ++f[a], ++f[b];
  }
  int p[n];
  memset(p, 0, sizeof(p));
  p[0] = n;
  int r = 0;
  for(int i=n-2;i>=0;i--) {
    if(f[i]==0) {
      bool placed = false;
      for(int j=0;j<=r;j++) {
        if(p[j]==0) {
          p[j] = i+1, placed = true;
          break;
        }
      }
      if(!placed) {
        cout << "NO" << "\n";
        return 0;
      }
    }
    else {
      if(r+f[i]>=n) {
        cout << "NO" << "\n";
        return 0;
      }
      p[r+=f[i]]= i+1;
    }
  }
  cout << "YES" << "\n";
  for(int i=1;i<n;i++) {
    cout << p[i-1] << " " << p[i] << "\n";
  }
}