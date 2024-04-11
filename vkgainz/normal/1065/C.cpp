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
  int n, k; cin >> n >> k;
  int h[n];
  for(int i=0;i<n;i++)
    cin >> h[i];
  int f[200005];
  memset(f, 0, sizeof(f));
  for(int i=0;i<n;i++)
    ++f[h[i]];
  ll sumIn = 0;
  int numIn = 0;
  int ans = 0;
  ll mn = 1000000000;
  for(int i=0;i<n;i++)
    mn = min(mn, h[i]*1LL);
  for(int sl=200001;sl>=mn;sl--) {
    sumIn+=numIn; //cost at sl-1
    if(sumIn>k) {
      sumIn = numIn;
      ++ans;
    }
    numIn+=f[sl];
  }
  if(sumIn>0) ++ans;
  cout << ans << "\n";
}