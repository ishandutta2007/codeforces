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

int ans[1001][1001];
void ch() {
  int ret[1001][1001];
  for(int i=0;i<1000;i++) {
    for(int j=0;j<1000;j++) {
      if(i==j) {
        ret[i][j] = 0;
      }
      else {
        ret[i][j] = 1-ans[i][j];
      }
    }
  }
  for(int i=0;i<1000;i++)
    for(int j=0;j<1000;j++)
      ans[i][j] = ret[i][j];
}
int main() {
  int n, a, b; cin >> n >> a >> b;
  if(n==1) {
    cout << "YES" << "\n";
    for(int i=0;i<1;i++)
      for(int j=0;j<1;j++)
        cout << 0;
    return 0;
  }
  for(int i=0;i<1000;i++)
    for(int j=0;j<1000;j++)
      ans[i][j] = 0;
  if(a==1 && b==1) {
    if(n==2 || n==3) {
      cout << "NO" << "\n";
      return 0;
    }
    for(int i=1;i<n;i++) {
      ans[i][i-1] = 1;
      ans[i-1][i] = 1;
    }
    cout << "YES" << "\n";
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        cout << ans[i][j];
      }
      cout << "\n";
    }
    return 0;
  }
  bool inv = false;
  if(min(a,b)>1) {
    cout << "NO" << "\n";
    return 0;
  }
  if(a==1)
    swap(a, b), inv = true;
  if(a>=2) {
    for(int x=a;x<n;x++) {
      ans[0][x] = 1;
      ans[x][0] = 1;
    }
  }
  else {
    //b=1...
    //put an edgew i and i+1
    for(int i=0;i<n-1;i++) {
      ans[(i+1)%n][i] = 1;
      ans[i][(i+1)%n] = 1;
    }
  }
  if(inv) ch();
  cout << "YES" << "\n";
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cout << ans[i][j];
    }
    cout << "\n";
  }
}