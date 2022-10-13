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
  int n, m; cin >> n >> m;
  ll dpHor[max(n, m)+1];
  dpHor[0] = 2LL;
  dpHor[1] = 2LL;
  ll mod = 1e9 + 7;
  for(int i=2;i<=max(n, m);i++) {
    dpHor[i] = dpHor[i-1] + dpHor[i-2];
    dpHor[i] %= mod;
  }
  cout << ((dpHor[m] + dpHor[n] - 2) %mod + mod)% mod << "\n";
}