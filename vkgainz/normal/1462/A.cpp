#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 5e5+5;

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int b[n];
    for(int i=0;i<n;i++) cin >> b[i];
    int a[n];
    for(int i=0;i<n;i++) {
      if(i<(n+1)/2) a[2*i] = b[i];
      else {
        a[2*n-2*i-1] = b[i];
      }
    }
    for(int i=0;i<n;i++)
      cout << a[i] << " ";
    cout << "\n";
  }
}