#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
typedef tree<
pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;
const int MX = 3e5+5;

int main() {
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  vector<ll> a(n1), b(n2), c(n3);
  ll suma = 0, sumb = 0, sumc = 0;
  for(int i=0;i<n1;i++) cin >> a[i], suma+=a[i];
  for(int i=0;i<n2;i++) cin >> b[i], sumb+=b[i];
  for(int i=0;i<n3;i++) cin >> c[i], sumc+=c[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  ll sum=  suma+sumb+sumc;
  ll mn = 1e18;
  mn = min({mn, a[0]+b[0], b[0]+c[0], a[0]+c[0], suma, sumb, sumc});
  cout << sum-2*mn << "\n";
}