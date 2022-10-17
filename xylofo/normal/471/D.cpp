#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


vi Z(const vi&s) {
  int n = sz(s), l = 0, r = 0;
  vi z(n);
  rep(i,1,n) {
    if (i <= r) z[i] = min(r - i + 1, z[i-l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

vi match(const vi& s, const vi& pat) {
  vi p = pat, res;
  p.push_back(INT_MIN);
  for(int i:s) p.push_back(i);
  p = Z(p);
  rep(i,0,sz(s))
    if (p[i+sz(pat)+1] == sz(pat)) res.push_back(i);
  return res;
}


int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n,w,x,y;
  cin >> n >> w;
  vi dn(n-1), dw(w-1);

  cin >> x; rep(i,0,n-1) { cin >> y; dn[i] = y-x; x = y; }
  cin >> x; rep(i,0,w-1) { cin >> y; dw[i] = y-x; x = y; }
  dn.push_back(INT_MAX);

  vi m = match(dn, dw);
  cout << m.size() << endl;
}