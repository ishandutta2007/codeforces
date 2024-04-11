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
  vector<string> s(n), t(m);
  for(auto &a : s) cin >> a;
  for(auto &a : t) cin >> a;
  int q; cin >> q;
  while(q--) {
    int x; cin >> x;
    --x;
    cout << s[(x%n)]+t[(x%m)] << "\n";
  }
}