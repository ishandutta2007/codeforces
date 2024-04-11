#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> pos(n+1), mn(n+1), mx(n+1);
  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> os;
  rep(a,1,n+1) os.insert(pos[a] = mn[a] = mx[a] = a);
  rep(i,0,m) {
    int a;
    cin>>a;
    mx[a] = max<int>(mx[a], os.order_of_key(pos[a])+1);
    mn[a] = 1;
    os.erase(pos[a]);
    os.insert(pos[a] = -i);
  }
  rep(a,1,n+1) mx[a] = max<int>(mx[a], os.order_of_key(pos[a])+1);
  rep(i,1,n+1) cout << mn[i] << " " << mx[i] << "\n";
}