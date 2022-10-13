#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 2e5+5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n; cin >> n;
  int a[n];
  for(int i=0;i<n;i++)
    cin >> a[i];
  int m; cin >> m;
  int b[m];
  for(int i=0;i<m;i++)
    cin >> b[i];
  ll suma =0, sumb=0;
  for(int i=0;i<n;i++)
    suma+=a[i];
  for(int i=0;i<m;i++)
    sumb+=b[i];
  if(suma!=sumb)
    cout << -1 << "\n";
  else {
    int j=0;
    int ans =0;
    for(int i=0;i<n;i++) {
      suma+=a[i];
      while(j<m && sumb<suma) {
        sumb+=b[j++];
      }
      if(sumb==suma) {
        ++ans, suma=0, sumb=0;
      }
    }
    cout << ans << "\n";
  }
}