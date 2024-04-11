#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5 + 5;
vector<int> in[MX];
multiset<int> inPrime[MX];
map<int, int> freq[MX];
ll mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(auto &a : a) cin >> a;
  for(int i=2;i<MX;i++) {
    if(in[i].size() == 0) {
      for(int j=i;j<MX;j+=i) {
        in[j].push_back(i);
      }
    }
  }
  for(int i=0;i<n;i++) {
    for(int p : in[a[i]]) {
      int f = 0;
      while(a[i]%p==0) {
        a[i]/=p;
        ++f;
      }
      freq[i][p] = f;
      inPrime[p].insert(f);
    }
  }
  ll curr = 1;
  for(int i=0;i<MX;i++) {
    if((int)inPrime[i].size() == n) {
      for(int j=0;j<*inPrime[i].begin();j++)
        curr = curr *1LL* i, curr %= mod;
    }
  }
  while(q--) {
    int i, x; cin >> i >> x;
    --i;
    for(int p : in[x]) {
      int f = 0;
      while(x%p==0) {
        ++f;
        x/=p;
      }
      int old = 0, nxt = 0;
      if((int)inPrime[p].size() == n)
        old = *inPrime[p].begin();
      if(inPrime[p].count(freq[i][p]))
        inPrime[p].erase(inPrime[p].lower_bound(freq[i][p]));
      freq[i][p] += f;
      inPrime[p].insert(freq[i][p]);
      if((int)inPrime[p].size() == n)
        nxt = *inPrime[p].begin();
      //cout << p << " " << old << " " << nxt << "\n";
      for(int i=old;i<nxt;i++) {
        curr = curr *1LL* p;
        curr %= mod;
      }
    }
    if(curr < 0) curr += mod;
    cout << curr << "\n";
  }
}