#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 1e5+5;

int main() {
  int t; cin >> t;
  while(t--) {
    int n;
    ll k; cin >> n >> k;
    ll gcd = 0;
    vector<ll> a(n);
    for(int i=0;i<n;i++) {
      cin >> a[i];
    }
    for(int i=0;i<n-1;i++) {
      gcd = __gcd(gcd, abs(a[i]-a[i+1]));
    }
    
    bool work = false;
    for(int i=0;i<n;i++) {
      if((a[i]%gcd+gcd)%gcd==(k%gcd+gcd)%gcd) {
        work = true;
      }
    }
    if(work) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
}