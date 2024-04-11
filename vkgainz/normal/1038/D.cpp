#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 2e5+5;

int main() {
  int n; cin >> n;
  int a[n];
  for(int i=0;i<n;i++)
    cin >> a[i];
  if(n==1) {
    cout << a[0];
    return 0;
  }
  int np = 0;
  for(int i=0;i<n;i++)np+=a[i]>0;
  sort(a, a+n);
  ll sum = 0;
  for(int i=0;i<n;i++)
    sum+=abs(a[i]);
  if(np==0){
    sum-=2*abs(a[n-1]);
  }
  else if(np==n) {
    sum-=2*abs(a[0]);
  }
  cout <<sum;
}