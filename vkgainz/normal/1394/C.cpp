#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5 + 5;
const int BLOCK_SZ = 1e3; 
vector<string> s;
vector<pair<int, int>> in;
vector<int> prefMx, sufMn;
vector<int> psMn, sufsMx;
pair<int, int> work(int &c) {
  int x = 0;
  for(int b=0;b<=500000;b++) {
    while(x < in.size() && b >= in[x].f) {
      ++x;
    }
    //[1...x] below, [x+1... n] above?
    if(in[0].f + c < b || in.back().f - c > b) continue;
    int lo1 = b - c + prefMx[x];
    int hi1 = psMn[x] + c;
    if(x==0) lo1 = 0, hi1 = 1000000000;
    int lo2 = sufsMx[x+1] - c;
    int hi2 = c + b + sufMn[x + 1];
    if(x==in.size()) lo2 = 0, hi2 = 1000000000;
    //[lo1, hi1] intersects [lo2, hi2]
    if(lo1 > hi1 || lo2 > hi2) continue;
    if(min(hi1, hi2) >= max(lo1, lo2) && (b>0 || min(hi1, hi2)>0)) return {b, min(hi1, hi2)};
    //check
  }
  return {-1, -1};
}
int main() {
  int n; cin >> n;
  s.resize(n);
  for(auto &s : s) cin >> s;
  in.resize(n);
  for(int i=0;i<n;i++) {
    for(char &ch : s[i]) {
      if(ch == 'B') ++in[i].f;
      else ++in[i].s;
    }
  }
  sort(in.begin(), in.end());
  prefMx.resize(n+2);
  sufMn.resize(n+2);
  psMn.resize(n+2);
  sufsMx.resize(n+2);
  prefMx[0] = -1000000000;
  sufMn[n+1] = 100000000;
  psMn[0] = 1000000000;
  sufsMx[n+1] = 0;
  for(int i=1;i<=n;i++) {
    prefMx[i] = max(prefMx[i-1], in[i-1].s - in[i-1].f);
    psMn[i] = min(psMn[i-1], in[i-1].s);
  }
  for(int i=n;i>=1;i--) {
    sufMn[i] = min(sufMn[i+1], in[i-1].s - in[i-1].f);
    sufsMx[i] = max(sufsMx[i+1], in[i-1].s);
  }
  //bin search ans
  int lo = 0, hi = 500005;
  for(int i=0;i<25;i++) {
    int mid = (lo+hi)/2;
    pair<int, int> temp = work(mid);
    if(temp.f == -1) {
      lo = mid + 1;
    }
    else {
      hi = mid;
    }
  }
  pair<int, int> ans = work(lo);
  string ret;
  for(int i=0;i<ans.f;i++) ret+="B";
  for(int i=0;i<ans.s;i++) ret+="N";
  cout << lo << "\n";
  cout << ret << "\n";
}