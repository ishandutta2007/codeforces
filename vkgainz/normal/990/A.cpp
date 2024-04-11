#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 5e5+5;

int main() {
  ll n, m; cin >> n >> m;
  ll a, b; cin >> a >> b;
  ll x = n%m, y = m-x;
  cout << min(x*b, y*a) << "\n";
}