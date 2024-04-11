#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
const int MX = 1e5+5;

int main() {
  int n, p; cin >> n >> p;
  int ans = 100;
  for(int i=1;i<=70;i++) {
    int r = n-i*p;
    int lo = __builtin_popcount(r);
    int hi = r;
    if(lo <= i && i <= hi) ans = min(ans, i);
  }
  if(ans==100) cout << -1 << "\n";
  else
  cout << ans;
}