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
const int MX = 5e5 + 5;
ll dist[5001][5001];
ll get(pair<int, int> &x, pair<int, int> &y) {
  ll a = x.f-y.f, b = x.s-y.s;
  return a*1LL*a+b*1LL*b;
}
bool obtuse(ll x, ll y, ll z) {
  return z>=x && z>=y && x<=z - y;
}
bool obt(int a, int b, int c) { //a->b->c-a
  ll x = dist[a][b], y = dist[b][c], z = dist[a][c];
  return obtuse(x, y, z);
}
int main() {
  int n; cin >> n;
  vector<pair<int, int>> a(n);
  for(int i=0;i<n;i++) cin >> a[i].f >> a[i].s;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      dist[i][j] = get(a[i], a[j]);
    }
  }
  //acute -> x^2+y^2 > z^2
  vector<int> ans;
  ans.push_back(0), ans.push_back(1);
  for(int i=2;i<n;i++) {
    ans.push_back(i);
    //bef->prev->curr
    for(int j=ans.size()-1;j>=2;j--) {
      int bef = ans[j-2], prev = ans[j-1], curr = ans[j];
      if(obt(bef, prev, curr)) {
        swap(ans[j-1], ans[j]);
      }
    }
  }
  bool work = true;
  for(int i=0;i<n-2;i++) {
    if(obt(ans[i], ans[i+1], ans[i+2])) 
      work = false;
  }
  if(!work) {
    cout << -1 << "\n";
    return 0;
  }
  for(int i=0;i<n;i++) {
    cout << ans[i]+1 << "\n";
  }
  
}