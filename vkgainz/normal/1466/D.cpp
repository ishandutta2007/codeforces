#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree <pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update>
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 2e5 + 5;
int w[MX];
bool cmp(const int &x, const int &y) {
  return w[x] < w[y];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    for(int i=0;i<n;i++)
      cin >> w[i];
    int deg[n];
    memset(deg,0,sizeof(deg));
    for(int i=0;i<n-1;i++) {
      int a, b; cin >> a >> b;
      --a, --b;
      ++deg[a], ++deg[b];
    }
    int freq[n];
    for(int i=0;i<n;i++)
      freq[i] = 0;
    vector<int> v;
    for(int i=0;i<n;i++) {
      if(deg[i]>1) v.push_back(i);
    }
    sort(v.begin(), v.end(), cmp);
    ll sum = 0;
    for(int i=0;i<n;i++) sum+=w[i];
    printf("%lld\n", sum);
    for(int k=2;k<n;k++) {
      int x = v.back();
      ++freq[x], sum+=w[x];
      printf("%lld\n",sum);
      if(freq[x]==deg[x]-1)
        v.pop_back();
    }
  }
}