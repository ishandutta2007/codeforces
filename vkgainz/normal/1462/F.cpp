#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 2e5+5;
void compress(vector<pair<int, int>> &v) {
  set<int> s;
  for(int i=0;i<v.size();i++)
    s.insert(v[i].f), s.insert(v[i].s);
  map<int, int> m;
  int va = 0;
  for(auto &it : s) m[it] = va++;
  for(int i=0;i<v.size();i++)
    v[i].f = m[v[i].f], v[i].s = m[v[i].s];
}
int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<pair<int, int>> seg(n);
    for(int i=0;i<n;i++)
      cin >> seg[i].f >> seg[i].s;
    compress(seg);
    int pref[2*n+1], suf[2*n+1];
    memset(pref,0,sizeof(pref));
    memset(suf,0,sizeof(suf));
    //pref[i] is number of segs such that seg[i].r < i (strict)
    //suf[i] is number of segs such taht i < seg[i].l (strict)
    int numL[2*n+1], numR[2*n+1];
    memset(numL,0,sizeof(numL));
    memset(numR,0,sizeof(numR));
    for(int i=0;i<n;i++) 
      ++numL[seg[i].f], ++numR[seg[i].s];
    pref[0] = 0;
    suf[2*n] = 0;
    int in = 0;
    for(int i=0;i<=2*n;i++) {
      pref[i] = in;
      in+=numR[i];
    }
    in = 0;
    for(int i=2*n;i>=0;i--) {
      suf[i] = in;
      in+=numL[i];
    }
    int ans = n;
    for(int g=0;g<n;g++) {
      //seg[g] is the good one
      int l = seg[g].f;
      int r = seg[g].s;
      ans = min(ans, suf[r] + pref[l]);
    }
    cout << ans << "\n";
  }
}