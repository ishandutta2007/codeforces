#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
const int MX = 1e5+5;

int main() {
  string s; cin >> s;
  int x, y; cin >> x >> y;
  ll ans = 0;
  pair<int, int> put[s.length()];
  put[0] = {0, 0};
  int nz = 0, no = 0;
  vector<int> ques;
  if(s[0]=='0') ++nz;
  else if(s[0]=='1') ++no;
  else ques.push_back(0);
  for(int i=1;i<s.length();i++) {
    put[i] = {nz, no};
    if(s[i]!='?') {
      if(s[i]=='0') ans+=put[i].s*1LL*y;
      else ans+=put[i].f*1LL*x;
    }
    else ques.push_back(i);
    if(s[i]=='0') ++nz;
    else if(s[i]=='1') ++no;
  }
  if(x<=y) { //0000...1111
    ll mn = 1e18;
    ll curr = 0LL;
    for(auto &pos : ques) {
      curr+=put[pos].f*1LL*x+(nz-put[pos].f)*1LL*y;
    }
    mn = min(mn, curr);
    for(int p=0;p<ques.size();p++) {
      //first p+1 are 0
      ll change = 0LL;
      int pos = ques[p];
      change-=put[pos].f*1LL*x+p*1LL*x+(nz-put[pos].f)*1LL*y;
      change+=put[pos].s*1LL*y+(no-put[pos].s)*1LL*x+(ques.size()-1-p)*1LL*x; //check this
      curr+=change;
      mn = min(mn, curr);
    }
    ans+=mn;
  }
  else { //1111...0000
    ll mn = 1e18;
    ll curr = 0LL;
    for(auto &pos : ques) {
      curr+=put[pos].s*1LL*y+(no-put[pos].s)*1LL*x;
    }
    mn = min(mn, curr);
    for(int p=0;p<ques.size();p++) {
      //first p+1 are 1
      ll change = 0LL;
      int pos = ques[p];
      change-=put[pos].s*1LL*y+(no-put[pos].s)*1LL*x+p*1LL*y;
      change+=put[pos].f*1LL*x+(nz-put[pos].f)*1LL*y+(ques.size()-1-p)*1LL*y;
      curr+=change;
      mn = min(mn, curr);
    }
    ans+=mn;
  }
  cout << ans << "\n";
}