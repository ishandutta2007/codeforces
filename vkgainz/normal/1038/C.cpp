#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
const int MX = 1e6+5;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for(int i=0;i<n;i++)
    cin >> a[i];
  for(int i=0;i<n;i++)
    cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ll x = 0, y = 0;
  for(int i=0;i<2*n;i++) {
    if(i%2==0) {
      if(a.size()==0)
        b.pop_back();
      else {
        if(b.size()==0)
          x+=a[a.size()-1], a.pop_back();
        else {
          if(a[a.size()-1]>b[b.size()-1])
            x+=a[a.size()-1], a.pop_back();
          else
            b.pop_back();
        }
      }
    }
    else {
      if(b.size()==0)
        a.pop_back();
      else {
        if(a.size()==0)
          y+=b[b.size()-1], b.pop_back();
        else {
          if(b[b.size()-1]>a[a.size()-1]) 
            y+=b[b.size()-1], b.pop_back();
          else
            a.pop_back();
        }
      }
    }
  }
  cout << x-y << "\n";
}